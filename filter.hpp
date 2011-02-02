#ifndef FILTER_HPP
#define FILTER_HPP
#include <inttypes.h>

class filter {
	public:
		virtual void feed(uint8_t* byte) = 0;
		virtual bool feedMode() = 0 ; // 0 = standard bytes; 1 = encoded bytes;
		virtual bool needKeys() = 0;
		virtual void setMode(bool mode) = 0; // 0 = encode; 1 = decode
		virtual const char* author() const = 0;
		virtual const char* getDescription() const = 0;
		void setKeys(const int* k, int kl);
	protected:
		const int* keys;
		int keysLength;
};
#endif
