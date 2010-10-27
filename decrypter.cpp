#include "decrypter.hpp"

unsigned char decrypter::decrypt(const unsigned char* bits) {
	int x=0;
	for(short int i=0; i<8; i++) {
		if(bits[i]=='1')
			x=x|1;
		if(i!=7)
			x<<=1;
	}
	return (unsigned char)x;
}
