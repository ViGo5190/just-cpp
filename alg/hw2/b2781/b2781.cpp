#include <iostream>
#include <fstream>

using namespace std;

struct node{
    int x;
    int num;
    int y;
    struct node *parent;
    struct node *left;
    struct node *right;
};

typedef node *pnode;


class decTree{
    private:
    int treeSize;

    
    public:
    decTree(int a):treeSize(a){ }
};



int main(void){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int sizet;
    in >>  sizet;
    
    decTree mytree = new decTree(55555);   
    return 0;
}
