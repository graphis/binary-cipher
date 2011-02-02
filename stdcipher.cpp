#include "stdcipher.hpp"
#include <iostream>

void stdcipher::feed(uint8_t* byte) {
	std::cerr << "stdcipher::feed()" << std::endl;
}

bool stdcipher::feedMode() {
	return 0;
}

bool stdcipher::needKeys() {
	return true;
}

void stdcipher::setMode(bool mode) {
	this->mode=mode;
}

const char* stdcipher::getDescription() const {
	return "Standard cipher filter. Use -k to add a keys...";
}

const char* stdcipher::author() const {
	return "Patryk Jaworski <skorpion9312@gmail.com>";
}
