#ifndef MYFS
	#define MYFS
	#include "myfs.h"
#endif

myfs::myfs() {

}

void myfs::init() {
	//size_t size;
	//size_t count;
	ifstream in("config");
	in >> _CONFIG_BLOCK_SIZE >> _CONFIG_BLOCK_COUNT;
	cout << _CONFIG_BLOCK_SIZE;

}