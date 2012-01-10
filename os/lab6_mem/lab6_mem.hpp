#define MAX 100

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
		std::cout << "Created system MCB" << std::endl;
		std::cout << "size of MCB = " << sizeof(MCB) <<std::endl;
		//cout << (MCB*)(ram + MAX) << endl;
		std::cout << "Max size = " <<(MCB*)((char*)mem + MAX) << std::endl;
		std::cout << "Next block= " << mem->next << std::endl;
	}
	std::cout << " --- " << std::endl;
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
	std::cout << "This blosk is = " <<   mem << " " << prev << " "  << mem->next << std::endl;
	

	return mem;



}


void * my_delete () {
	
}