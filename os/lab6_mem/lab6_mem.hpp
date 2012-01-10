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
		std::fill( (char*)ram , (char*)ram + MAX, 0);
		mem->next = (MCB*)((char*)mem + sizeof(MCB));
		mem->size=0;
		//std::cout << "Created system MCB" << std::endl;
		//std::cout << "size of MCB = " << sizeof(MCB) <<std::endl;
		//std::cout << "Max size = " <<(MCB*)((char*)mem + MAX) << std::endl;
		//std::cout << "Next block= " << mem->next << std::endl;
	}
	//std::cout << " --- " << std::endl;
	while (mem->next!=NULL) {
		prev = mem;
		//cout << "next is available" <<endl;
		if ((MCB*)((char*)mem+sizeof(MCB) + user_data_size) > ((MCB*) (ram + MAX))) {
			return NULL;
		}
		
		if ((mem->next!=NULL) && (mem->size == 0) && ((char*)(mem->next) - (char*)(mem) - sizeof(MCB) >= user_data_size)) {
			break;
		}
		
		mem = mem->next;
		//mem->prev = prev;
		
	}
	mem->next = (MCB*)((char*)mem + sizeof(MCB) + user_data_size);
	mem->size = user_data_size;
	//std::cout << "This blosk is = " <<   mem << " " << prev << " "  << mem->next << std::endl;
	//std::cout << "Between " << (char*)(mem->next) - (char*)(mem) - sizeof(MCB)<< std::endl;

	return (char*)mem+sizeof(MCB);



}

void my_fill(void * ptr, char c) {
	MCB* mem = (MCB*) ((char*)ptr-sizeof(MCB));
	if (mem->size == 0) {
		return;
	}
	std::fill( (char*)ptr , (char*) ptr + mem->size , c);
}

void * my_delete (void * ptr) {
	MCB* mem = (MCB*) ((char*)ptr-sizeof(MCB));
	my_fill(ptr, 0);
	mem->size=0;
	if (mem->next->next==NULL) {
		mem->next=NULL;
	}
	//std::cout << mem << " " << mem->size << " " << mem->next <<std::endl;

	
}




void print_map() {
	MCB* mem = (MCB*)ram;
	
	while (mem->next!=NULL) {
			

		std::cout << "MCB: " << mem << " size: ";
		std::cout << std::setw(3) << mem->size;
		std::cout << " data start at: " << (void*)((char*)mem+sizeof(MCB) );
		
		std::cout << std::endl;	
		mem = mem->next;
	}

	for (int i =0 ; i < MAX; i++) {
		std::cout << ram[i];
		
	}
	std::cout << std::endl;

}

