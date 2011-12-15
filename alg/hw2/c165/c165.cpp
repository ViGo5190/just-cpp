#include <iostream>
#include <fstream>

using namespace std;

struct mynode {
    int num;
    mynode *next;
};

typedef mynode *listnode;

struct mypoint {
    int color;
    listnode edges;
};

listnode pop(listnode *list){
    listnode node = *list;

    if (*list != NULL)
        *list = node->next;
    else 
        *list = NULL;
    return node;
}

listnode push(listnode list, listnode node){
    if (node != NULL) {
        node->next = list;
        return node;
    }
    return list;
}

int main(void){

    return 0;
}
