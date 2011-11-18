#include <iostream>
#include <vector>
using namespace std;
static char* my_memory[1024];

struct MCB{
    public:
    int magic;
    void *start;
    int length;

};

//vector<my_log_class> my_log;

void *find_memory(){
    return my_memory;    
}

void *my_alloc(size_t my_size){
    MCB p; // для нового куска
    
    p.length = my_size;
    p.magic = 1;
    void *t = my_memory;
    p.start = t +sizeof(p);
    *((MCB*)t) = p;
    cout << t << " !" << endl;
    return p.start;
}
void my_delete(void *ptr){

    return;
}



int main(){
    cout << find_memory()<<endl;
    cout << my_alloc(2);
    return 0;
}
