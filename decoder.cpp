#include "decoder.hpp"
#include <iostream>

uint8_t decoder::decode(const uint8_t* bits) throw (skorpionException) {
	uint8_t x=0;
	for(short int i=0; i<8; i++) {
		if(bits[i]!=(uint8_t)('0') && bits[i]!=(uint8_t)('1')) {
			throw skorpionException("Decoding error. Your data is corrupt or you are using wrong filter...");
		}
		if((char)bits[i]=='1')
			x=x|1;
		if(i!=7)
			x<<=1;
	}
	return x;
}
