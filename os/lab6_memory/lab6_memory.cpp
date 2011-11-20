#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;
int static const N = 1024;

char memory[N];

struct myMCB {
    unsigned int size;
    myMCB *start;
    myMCB *end;
};

void* my_alloc(size_t size){
    return 0;
}

void my_delete(void * ptr){

    return;
}

int main(){
    fill(memory,memory+N,0);
    cout << &memory[0] << "-"<<&memory[N+1];
    char* q = &memory[0];
    *q = '1';
    cout << endl<<q;
    
    cout << endl<<"end";  
    return 0;
}
