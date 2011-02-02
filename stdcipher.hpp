#include "filter.hpp"

class stdcipher : public filter {
	void getByte(uint8_t* byte);
	bool needKeys();
	const char* getDescription() const;
};
