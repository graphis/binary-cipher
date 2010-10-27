#include "exceptions.hpp"
#include <stdio.h>

class reader {
	public:
		unsigned char readByte() throw(skorpionException, endOfFile);
		void open(const char* name) throw(skorpionException);
		reader();
		~reader();
	private:
		char name[256];
		FILE* file;
		unsigned char buffer[1024];
		int bpos;
		int blen;
		long size;
};
