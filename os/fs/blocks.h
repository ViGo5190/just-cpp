#ifndef IOSTREAM
	#define IOSTREAM 
	#include <iostream>
#endif

#ifndef FSTREAM
	#define FSTREAM 
	#include <fstream>
#endif

#ifndef STDNAMESPACE
	#define STDNAMESPACE 
	using namespace std;
#endif

class blocks{
	private:
		bool _ok;
		string _path;
		size_t _CONFIG_BLOCK_SIZE;
		size_t _CONFIG_BLOCK_COUNT;
	
	public:
		blocks();
		~blocks();

		bool init();
		void format();

		size_t read(size_t id, char* buffer, size_t size) const;
		size_t write(size_t id, char* buffer, size_t size);

		bool release(size_t id);
		bool occupy(size_t id);

		size_t get_block (size_t start) const;

		bool get_ok() const {
			return _ok;
		}



};