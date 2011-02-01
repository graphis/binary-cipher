#include "encoder.hpp"
const uint8_t* encoder::encode(const uint8_t byte) {
	uint8_t* bin=new uint8_t[8];
	short int bi=0;
	short int b=(short int)byte;
	while(b>0) {
		if(b&1)
			bin[bi++]='1';
		else
			bin[bi++]='0';
		b>>=1;
		
	}
	for(short int i=bi; i<8; i++) {
		bin[i]='0';
	}
	bi=8;
	for(short int i=0; i<4; i++) {
		uint8_t tmp=bin[i];
		bin[i]=bin[bi-(i+1)];
		bin[bi-(i+1)]=tmp;
	}
	return bin;
}
