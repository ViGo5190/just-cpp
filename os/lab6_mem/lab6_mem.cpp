#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

#define MAX 100

using namespace std;

char ram[MAX];

class MCB {
	public:
	size_t size;
	MCB *prev;
	MCB *next;

	MCB() {
		next = (MCB*)ram;;
		prev = NULL;
		size = 0;
	}
};


void * my_alloc (size_t user_data_size) {
	MCB* mem = (MCB*)ram;
	MCB* prev = mem;

	if (mem->next == NULL) {
		//mem = new MCB();
		mem->next = (MCB*)((char*)mem + sizeof(MCB));
		cout << "Created system MCB" << endl;
		cout << "size of MCB = " << sizeof(MCB) <<endl;
		//cout << (MCB*)(ram + MAX) << endl;
		cout << "Max size = " <<(MCB*)((char*)mem + MAX) << endl;
		cout << "Next block= " << mem->next << endl;
	}
	cout << " --- " << endl;
	while (mem->next!=NULL) {
		prev = mem;
		//cout << "next is available" <<endl;
		if ((MCB*)((char*)mem+sizeof(MCB) + user_data_size) > ((MCB*) (ram + MAX))) {
			return NULL;
		}

		mem = mem->next;
		//mem->prev = prev;
		
	}
	mem->next = (MCB*)((char*)mem + sizeof(MCB) + user_data_size);
	cout << "This blosk is = " <<   mem << " " << prev << " "  << mem->next << endl;
	

	return mem;



}

int main(void) {
	cout << "start = " <<&ram;
	cout << endl;

	void *q[5];

	q[0] = my_alloc(5);
	cout << q[0] << endl;
	q[1] = my_alloc(5);
	cout << q[1] << endl;
	q[2] = my_alloc(5);
	cout << q[2] << endl;
	q[3] = my_alloc(5);
	cout << q[3] << endl;
}