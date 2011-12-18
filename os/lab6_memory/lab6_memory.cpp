#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 1024
using namespace std;

char ram[MAX];

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




size_t lastMCB = sizeof(MCB);

void* my_alloc (size_t user_size){
	MCB* mem =  (MCB*)ram;
	MCB* prev = mem;
	cout << "start " << mem << " end " << (MCB*)(mem + sizeof(ram)) << " " << sizeof(ram) << endl; 
	//cout << "sss" << user_size << endl;
	while ((mem->next!=0)&&(mem->index > 0)){
		//cout << "j--" << endl;
		prev = mem;
		//cout << " w "<< mem << " " << mem->next << endl;
		
		cout  <<  (MCB*)(mem + sizeof(MCB) + user_size*sizeof(char)) << " " << (MCB*)( (MCB*)ram + sizeof(char)*1024) << endl;
		if ((MCB*)(mem + sizeof(MCB) + user_size*sizeof(char)) > (MCB*)( (MCB*)ram + sizeof(char)*MAX)){
			return NULL;
		}
		
		mem = mem->next;
		//cout << " q "<<prev->index << " " << mem  << " next---" << " ! " << prev <<endl;
		//cout << "     " << mem->next << " " << mem->index<<endl;
	}

	
	
	//cout << ">> " << sizeof(MCB) << " " << sizeof(mem) << endl;
	


	mem->next = (MCB*)(mem + sizeof(MCB) + user_size*sizeof(char));
	
	if (prev->index>0){
		mem->prev = prev;
		mem->index = prev->index + 1;
		
			
	} else {
		mem->index = 1;
	}

	mem->size = user_size;
	
	cout << prev->index << " ~" <<mem->index << " " <<mem << " "<<  "!!next = " << mem->next << " prev = " << mem->prev <<endl;
	/*
	MCB* qqq = (MCB*)ram;
	for (int i = 1; i<=mem->index;i++){
		
		
		cout << "bal = " <<qqq->index << " cur:" << qqq << " next:" << qqq->next << " prev:"<<qqq->prev << endl;
		qqq = qqq->next;
	}
	*/
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