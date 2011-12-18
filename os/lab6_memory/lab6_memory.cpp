#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

char ram[1024];

class MCB{
	public:
	size_t magicStart;
	size_t magicEnd;
	int size;
	MCB **ptr;
	
	MCB *next;
	MCB *prev;
	
	MCB(){
		//index = 0;
		//ptr = 1024;
		//size = 0;
		next = (MCB*)ram;
		size = 1;
	}	
	
};

static MCB* mem = (MCB*)ram;


size_t lastMCB = sizeof(MCB);

int my_alloc (size_t user_size){
	MCB** iterator = &mem;
	cout << iterator.->size;
}

int main(void){
	char a = '7';
	char* b;
	b = (char*)&a;
	cout << b << endl;

	

	return 0;
}