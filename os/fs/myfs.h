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

class myfs {
	private:
		size_t _CONFIG_BLOCK_SIZE;
		size_t _CONFIG_BLOCK_COUNT;
	public:
		myfs();
		void init();
};