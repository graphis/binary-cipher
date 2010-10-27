
class skorpionException {
	protected:
		char msg[1024];
	public:
		skorpionException();
		skorpionException(const char* msg);
		const char* getMessage() const;
};

class endOfFile : public skorpionException{
	public:
		endOfFile(const char* msg);
};
