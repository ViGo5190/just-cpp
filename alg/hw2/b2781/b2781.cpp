#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

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

ifstream in("input.txt");
ofstream out("output.txt");

class decTree{
    public:
    int treeSize;
    node *nodes;
    pnode *sorted;
    pnode root;
    
    
    decTree(int a): treeSize(a){
        nodes = new node[treeSize];
        sorted= new pnode[treeSize];
    }

    void insertionSort(pnode *pnodes , int left, int right){
        pnode temp;

        for (int i = left + 1; i < right; i++){
            int j = i - 1;
            temp = pnodes[i];
            while ((j >= left) && (pnodes[j]->x > temp->x)){
                pnodes[j + 1] = pnodes[j];
                j--;
            }
            pnodes[j + 1] = temp;
        }
    }

    void quickSort(pnode *pnodes, int left, int right){
        srand(time(NULL));
        int l = left;
        int r = right-1;
        pnode temp, p;

        p = pnodes[l+rand() % (right - left)];

        do{
            while (pnodes[l]->x < p->x) l++;
            while (pnodes[r]->x > p->x) r--;

            if (l <= r){
                temp = pnodes[l];
                pnodes[l] = pnodes[r];
                pnodes[r] = temp;
                l++; r--;
            }
        } while (l <= r);

        if (r - left > 20)
            quickSort(pnodes, left, r + 1);
        else if (r > left)
            insertionSort(pnodes, left, r + 1);

        if (right - l > 20)
            quickSort(pnodes, l, right);
        else if (l < right - 1)
            insertionSort(pnodes, l , right);
        ////

    }
    
    void addNode(int i, int x, int y){
        nodes[i].x = x;
        nodes[i].y = -y;
        nodes[i].num = i+1;
        nodes[i].parent = NULL;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
        sorted[i] = nodes+i;

    }

    void buildTree(){
        pnode last = NULL;
        
        if (treeSize > 0){
            root = sorted[0];
            last = root;
            for (int i = 1; i < treeSize; i++){
                while (last->parent != NULL && sorted[i]->y > last->y)
                    last = last->parent;
                if (sorted[i]->y <= last->y){
                    sorted[i]->left = last->right;
                    sorted[i]->parent = last;
                    if (last->right)
                        last->right->parent = sorted[i];
                    last->right = sorted[i];

                } else {
                    sorted[i]->left = last;
                    last->parent = sorted[i];
                    root = sorted[i];
                }
                last = sorted[i];
            }
        }
    }

    void printResults(){
        int p, l, r;
        out << "YES" << endl;
        for (int i = 0; i < treeSize; i++){
            p = (nodes[i].parent) ? nodes[i].parent->num : 0;
            l = (nodes[i].left) ? nodes[i].left->num : 0;
            r = (nodes[i].right) ? nodes[i].right->num : 0;
            out << p << " " << l << " " << r << endl;
        }
    }
};




int main(void){
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int size, a, b;
    in >>  size;
    
    decTree *mytree = new decTree(size);
    for (int i = 0; i < size; i++ ){
        in >> a >> b;
        mytree->addNode(i,a,b);
    }
    mytree->quickSort(mytree->sorted, 0, mytree->treeSize);
    mytree->buildTree();
    mytree->printResults();
    return 0;
}
