#include <string.h>
#include "exceptions.hpp"

skorpionException::skorpionException() {}

skorpionException::skorpionException(const char* m) {
	strcpy(msg, m);
}

const char* skorpionException::getMessage() const {
	return msg;
}

endOfFile::endOfFile(const char* m) {
	strcpy(msg, m);
}
