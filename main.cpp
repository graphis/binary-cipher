#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include "reader.hpp"
#include "encoder.hpp"
#include "decoder.hpp"
using namespace std;

void printHeader() {
	cerr << "=============== Binary cipher ===============" << endl;
	cerr << "= Author: Patryk Jaworski" << endl;
	cerr << "= Contact: skorpion9312@gmail.com" << endl;
	cerr << "= License: GNU GPLv3 " << endl;
	cerr << "====== (Copyright by Patryk Jaworski) =======" << endl;
}

void printUsage() {
	printHeader();
	cerr << "\nUsage:\n\t./binary-cipher (--encode or --decode) PATH_TO_YOUR_FILE\n\n";
}

int main(int argc, char** argv) {
	if(argc<3) {
		printUsage();
		return 1;
	}
	bool encrypt;
	if(!strcmp("--encode", argv[1]))
		encrypt=true;
	else if(!strcmp("--decode", argv[1]))
		encrypt=false;
	else {
		printUsage();
		return 1;
	}
	printHeader();
	cerr << "[I] Input file: " << argv[2] << endl;
	cerr << "[I] " << (encrypt?"Encoding":"Decoding") << " mode." << endl;
	sleep(1);
	reader r;
	try {
		r.open(argv[2]);
	} catch(skorpionException e) {
		cerr << "[E] Error: " << e.getMessage() << endl;
		return 1;
	}
	if(encrypt) {
		cerr << "[I] Generating binary code for your file..." << endl;
		while(true) {
			try {
				uint8_t b=r.readByte();
				cout << encoder::encode(b);
			} catch(endOfFile e) {
				break;
			} catch(skorpionException e) {
				cerr << "[E] Error: " << e.getMessage() << endl;
			}
		}
		cerr << "\n[I] Done! :-)" << endl;
	} else {
		cerr << "[I] Decoding bytes..." << endl;
		uint8_t bits[8];
		while(true) {
			int i;
			try {
				for(i=0; i<8; i++)
					bits[i]=r.readByte();
			} catch(endOfFile e) {
				if(i!=0) {
					cerr << "[E*] Fatal error! Unexpected end of file. Your data is corrupt..." << endl;
				}
				break;
			} catch(skorpionException e) {
				cerr << "[E] Error: " << e.getMessage() << endl;
			}
			cout << decoder::decode(bits);
		}
		cerr << "\n[I] Done! :-)" << endl;
	}
}
