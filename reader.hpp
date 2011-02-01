#ifndef READER_HPP
#define READER_HPP
#include "exceptions.hpp"
#include <inttypes.h>

class reader {
	public:
		uint8_t readByte() throw(skorpionException, endOfFile);
		void open(const char* name) throw(skorpionException);
		reader();
		~reader();
	private:
		char name[512];
		FILE* file;
		uint8_t buffer[524288];
		int bpos;
		int blen;
		long size;
};
#endif
