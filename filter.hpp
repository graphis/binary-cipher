#ifndef FILTER_HPP
#define FILTER_HPP
#include <inttypes.h>

class filter {
	public:
		virtual void getByte(uint8_t* byte) = 0;
		virtual bool needKeys() = 0;
		virtual const char* getDescription() const = 0;
		void setKeys(const int* k, int kl);
	protected:
		const int* keys;
		int keysLength;
};
#endif
