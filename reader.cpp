#include <string.h>
#include <iostream>
#include <cstdio>
#include "exceptions.hpp"
#include "reader.hpp"

using namespace std;

reader::reader():bpos(0),blen(0),size(0){}

reader::~reader() {
	if(file!=NULL) {
		fclose(file);
	}
}

void reader::open(const char* n) throw(skorpionException) {
	strcpy(name, n);
	file=fopen(name, "r");
	cerr << "[I] Trying to open " << name << "..." << endl;
	if(file==NULL)
		throw skorpionException("Unable to open your file...");
	cerr << "[I] OK..." << endl;
	fseek(file, 0, SEEK_END);
	size=ftell(file);
	fseek(file,0, 0);
	cerr << "[I] File size: " << size << " bytes..." << endl;
}

uint8_t reader::readByte() throw(skorpionException, endOfFile) {
	if(file==NULL)
		throw skorpionException("Open file first...");
	if(blen==bpos) {
		blen=fread(buffer, 1, 524288, file);
		if(blen==0)
			throw endOfFile("EOF");
		bpos=0;
	}
	return buffer[bpos++];
}

