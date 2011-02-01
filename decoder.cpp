#include "decoder.hpp"

uint8_t decoder::decode(const uint8_t* bits) {
	uint8_t x=0;
	for(short int i=0; i<8; i++) {
		if((char)bits[i]=='1')
			x=x|1;
		if(i!=7)
			x<<=1;
	}
	return x;
}
