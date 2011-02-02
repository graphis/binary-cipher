#include "stdcipher.hpp"
#include <iostream>

void stdcipher::getByte(uint8_t* byte) {
	std::cerr << "stdcipher::getByte()" << std::endl;
}

bool stdcipher::needKeys() {
	return true;
}

const char* stdcipher::getDescription() const {
	return "Standard cipher filter. Use -k to add a keys...";
}
