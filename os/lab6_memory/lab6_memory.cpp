#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

char ram[1024];

class MCB{
	public:
	size_t magicStart;
	size_t magicEnd;
	size_t size;
	int index;
	MCB **ptr;
	
	MCB *next;
	MCB *prev;
	
	MCB(){
		next = (MCB*)ram;
		size = 0;
		next = NULL;
		index = 0;
	}	
	
};

//static MCB* mem = (MCB*)ram;


size_t lastMCB = sizeof(MCB);

void* my_alloc (size_t user_size){
	MCB* mem =  (MCB*)ram;
	MCB* prev = mem;
	
	cout << "sss" << user_size << endl;
	while ((mem->next)&&(mem->index > 0)){
		prev = mem;
		mem = mem->next;
		cout << " q " << mem   << " ! " << prev<< endl;
	}

	
	
	
	mem->next = (MCB*)(mem + sizeof(mem) + mem->size);
	
	if (prev->index>0){
		mem->prev = prev;
		prev->next = mem;
		mem -> index = prev->index + 1;
		
			
	} else {
		mem->index = 1;
	}
	mem->size = user_size;
	cout << prev->index << " ~" <<mem->index <<  "!!" << mem->next << " prev = " << mem->prev <<endl;
	
	return mem;

	
}

int main(void){
	char a = '7';
	char* b;
	b = (char*)&a;
	void *q[5];

	q[0] =  my_alloc(5);
	q[1] =  my_alloc(2);
	q[2] =  my_alloc(3);
	q[3] =  my_alloc(10);
	//cout << b << endl;
	//cout << ram << endl;
	cout << q[0] << " ~"<< q[1]<< " ~"<< q[2]<< " ~"<< q[3] << endl;


	

	return 0;
}