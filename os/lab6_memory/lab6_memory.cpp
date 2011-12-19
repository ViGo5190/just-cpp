#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define MAX 100
using namespace std;

char ram[MAX] ;

class MCB{
	public:
	char q;
	size_t size;
	int index;
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
	//cout << "start " << mem << " end " << (MCB*)(mem + sizeof(ram)*sizeof(char)) << " " << sizeof(ram) << endl; 
	//cout << "sss" << user_size << endl;
	while ((mem->next!=0)&&(mem->index > 0)){
		//cout << "j--" << endl;
		prev = mem;
		//cout << " w "<< mem << " " << mem->next << endl;
		
		//cout  <<  (MCB*)(mem + sizeof(MCB) + user_size*sizeof(char)) << " " << (MCB*)( (MCB*)ram + sizeof(char)*1024) << endl;
		if ((MCB*)(mem + sizeof(MCB) + user_size*sizeof(char)) > (MCB*)( (MCB*)ram + sizeof(char)*MAX)){
			return NULL;
		}
		
		mem = mem->next;
		//cout << " q "<<prev->index << " " << mem  << " next---" << " ! " << prev <<endl;
		cout << "     " << mem->next << " " << mem->index<<endl;
	}

	
	
	//cout << ">> " << sizeof(MCB) << " " << sizeof(mem) << endl;
	


	mem->next = (MCB*)(char*)(mem + sizeof(MCB) + user_size*sizeof(char));
	//mem->next = (MCB*)(char*)(mem + (sizeof(MCB) + user_size*sizeof(char))*MAX);

	if (prev->index>0){
		mem->prev = prev;
		mem->index = prev->index + 1;
		
			
	} else {
		mem->index = 1;
	}

	mem->size = user_size;
	mem->q = 'q';
	
	cout << prev->index << " ~" <<mem->index << " " <<mem << " "<<  "!!next = " << mem->next << " prev = " << mem->prev <<endl;
	cout << &mem->index << endl;
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
	/*
	for (int i = 0; i < MAX; i++){
		ram[i]=0;
		cout << ram[i];
	}
	*/
	cout << endl;
	char cc; 
	cout << "sizeof char" << sizeof(char) << endl;
	cout << sizeof(ram[0]) << "l" <<endl;
	cout << &ram <<" " << &ram + MAX<< endl;
	char a = '7';
	char* b;
	b = (char*)&a;
	void *q[5];

	q[0] =  my_alloc(1);
	q[1] =  my_alloc(5);
	q[2] =  my_alloc(3);
	q[3] =  my_alloc(10);
	//cout << b << endl;
	//cout << ram << endl;
	cout << q[0] << " ~"<< q[1]<< " ~"<< q[2]<< " ~"<< q[3] << endl;
	cout << sizeof(MCB) << " " << (q[0]+28*MAX) << endl;
	//*(char*)(q[0]+28) = '!';
	memcpy(q[0]+sizeof(MCB), "!", 1);
	cout << q[0]+sizeof(MCB) << " "<< ((char*)(q[0]+sizeof(MCB)));

	memcpy(q[1]+sizeof(MCB), "221265", 5);
	cout << q[1]+sizeof(MCB) << " "<< ((char*)(q[1]+sizeof(MCB)));
	//*(char*)(q[1]+sizeof(MCB)) = '^';
	ofstream out("output.txt");
	for (int i = MAX*0; i < MAX; i++){
		
		//cout << i << " " << (&ram+ i*sizeof(char)) <<" !"<<ram[i] << endl;

	}

	

	return 0;
}