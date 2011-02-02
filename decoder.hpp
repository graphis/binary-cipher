#include <inttypes.h>
#include "exceptions.hpp"
class decoder {
	public:
		static uint8_t decode(const uint8_t* bits) throw(skorpionException);
};
