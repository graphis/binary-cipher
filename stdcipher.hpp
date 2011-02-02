#include "filter.hpp"

class stdcipher : public filter {
	public:
		void feed(uint8_t* byte);
		bool feedMode();
		bool needKeys();
		const char* getDescription() const;
		const char* author() const;
		void setMode(bool mode);
	private:
		bool mode;
};
