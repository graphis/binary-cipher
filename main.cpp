#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include "reader.hpp"
#include "encoder.hpp"
#include "decoder.hpp"
#include "filter.hpp"
#include "stdcipher.hpp"

using namespace std;

std::map<string, filter*> filters;

void initFilters() {
	filters["stdcipher"]=new stdcipher();
}

void printHeader() {
	cerr << "=============== Binary cipher ===============" << endl;
	cerr << "= Author: Patryk Jaworski" << endl;
	cerr << "= Contact: skorpion9312@gmail.com" << endl;
	cerr << "= License: GNU GPLv3 " << endl;
	cerr << "====== (Copyright by Patryk Jaworski) =======" << endl;
}

void printUsage() {
	printHeader();
	cerr << "\nUsage:\n\t./binary-cipher MODE (-f FILTER -f FILTER2 ...) (-k KEY1 -k KEY2 ...) PATH_TO_YOUR_FILE\n\n";
	cerr << "Modes:" << endl;
	cerr << "\t --encode - encode your file into binary code" << endl;
	cerr << "\t --decode - decode your file from binary code" << endl << endl;
	cerr << "Filters:" << endl;
	for(map<string, filter*>::const_iterator i=filters.begin(), e=filters.end(); i!=e; ++i) {
		cerr << "\t" << i->first << " - " << (i->second)->getDescription() <<  endl;
		cerr << "\t  -> Author: " << (i->second)->author() << endl;
		cerr << "\t  -> Operate mode: " << ((i->second)->feedMode()==0?"standard bytes":"encoded bytes") << endl;
		cerr << "\t  -> Need keys: " << ((i->second)->needKeys()?"yes":"no") << endl;
	}
	cerr << "\n\n";
}

int main(int argc, char** argv) {
	initFilters();
	vector<filter*> loadedFilters;
	int keys[1024];
	int keysI=0;
	int mode=0;
	const char* name=NULL;

	if(argc<3) {
		printUsage();
		return 1;
	}

	printHeader();
	cerr << "[I] Parsing options..." << endl;
	for(int i=1; i<argc; i++) {
		if(strcmp(argv[i], "--encode")==0) {
			mode=1;
		} else if(strcmp(argv[i], "--decode")==0) {
			mode=2;
		} else if(strcmp(argv[i], "-f")==0) {
			if(filters.count(argv[i+1])==0) {
				cerr << "[E] Filter \"" << argv[i+1] << "\" not found..." << endl;
				exit(1);
			}
			cerr << "[I] Loading filter: " << argv[i+1] << "." << endl;
			loadedFilters.push_back(filters[argv[i+1]]);
			i++;
		} else if(strcmp(argv[i], "-k")==0) {
			int key=atoi(argv[i+1]);
			if(key<=0 || key>255) {
				cerr << "[E] Key must be an integer [1-255]..." << endl;
				exit(1);
			}
			cerr << "[I] Adding key (" << key << ")." << endl;
			keys[keysI++]=key;
			i++;
		} else {
			if(name==NULL)
				name=argv[i];
			else {
				cerr << "[E] Duplicated file name..." << endl;
				exit(1);
			}
		}
	}
	if(mode==0) {
		cerr << "[E] Missing mode..." << endl;
		exit(1);
	}
	if(name==NULL) {
		cerr << "[E] Please set input file name..." << endl;
		exit(1);
	}
	cerr << "\nSummary\n=======\n\n";
	cerr << "[I] Input file: " << name << endl;
	cerr << "[I] " << (mode==1?"Encoding":"Decoding") << " mode." << endl;
	sleep(3);

	reader r;
	try {
		r.open(name);
	} catch(skorpionException e) {
		cerr << "[E] Error while opening input file..." << endl;
		exit(1);
	}

	if(mode==1) {
		try {
			while(true) {
				uint8_t byte=r.readByte();
				uint8_t* encodedByte=NULL;
				for(unsigned int i=0; i<loadedFilters.size(); i++) {
					filter* f=loadedFilters[i];
					f->setMode(0);
					if(f->needKeys())
						f->setKeys(keys, keysI);
					if(f->feedMode()==0) {
						if(encodedByte!=NULL) {
							byte=decoder::decode(encodedByte);
							delete encodedByte;
							encodedByte=NULL;
						}
						f->feed(&byte);
					} else {
						if(encodedByte==NULL)
							encodedByte=encoder::encode(byte);
						f->feed(encodedByte);
					}
				}
				encodedByte=encoder::encode((encodedByte==NULL?byte:decoder::decode(encodedByte)));
				cout << encodedByte;
				delete encodedByte;
			}
		} catch (endOfFile e) {
		} catch(skorpionException e) {
			cerr << "[E] " << e.getMessage() << endl;
			exit(1);
		}
		cerr << "\n[OK] All done." << endl;
	} else if(mode==2) {
		try {
			uint8_t byte;
			bool decodeByte=true;
			uint8_t* encodedByte=new uint8_t[8];
			bool stop=false;
			while(true) {
				for(short int i=0; i<8; i++) {
					try {
						encodedByte[i]=r.readByte();
					} catch(endOfFile e) {
						encodedByte[i]=(uint8_t)('\0');
						stop=true;
						break;
					}
				}
				if(encodedByte[0]=='\0')
					break;
				for(unsigned int i=0; i<loadedFilters.size(); i++) {
					filter* f=loadedFilters[i];
					f->setMode(1);
					if(f->needKeys())
						f->setKeys(keys, keysI);
					if(f->feedMode()==0) {
						byte=decoder::decode(encodedByte);
						f->feed(&byte);
						decodeByte=false;
					} else {
						f->feed(encodedByte);	
					}
				}
				if(stop)
					break;
				if(decodeByte) {
					byte=decoder::decode(encodedByte);
				}
				cout << byte;
				decodeByte=true;
			}
		} catch(endOfFile) {
			
		} catch(skorpionException e) {
			cerr << "[E] " << e.getMessage() << endl;
			exit(1);
		}
		cerr << "[OK] All done." << endl;
	}

}
