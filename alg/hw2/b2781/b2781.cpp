/**
 * task b aka 2781
 * link: http://informatics.mccme.ru/moodle/mod/statements/view3.php?id=1974&chapterid=2781#1
 * Copyright reserved.
 * author: Gumeniuk Stanislav
 */

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct node{
    int x;
    int y;
    int label;
    struct node *parent;
    struct node *left;
    struct node *right;
};

typedef node *pnode;

ifstream in("input.txt");
ofstream out("output.txt");


class decTree{
    private:
    int treeSize;
    node *nodes;
    pnode *sorted;
    pnode root;
    
    void _insertionSort(pnode *pnodes , int left, int right){
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

    void _quickSort(pnode *pnodes, int left, int right){
        srand(time(NULL));
        int l = left;
        int r = right-1;
        pnode temp, p;

        p = pnodes[l + rand() % (right - left)];

        do{
            while (pnodes[l]->x < p->x) {
                l++;
            }
            while (pnodes[r]->x > p->x) {
                r--;
            }

            if (l <= r){
                temp = pnodes[l];
                pnodes[l] = pnodes[r];
                pnodes[r] = temp;
                l++; 
                r--;
            }
        } while (l <= r);

        if (r - left > 20){
            _quickSort(pnodes, left, r + 1);
        } else if (r > left){
            _insertionSort(pnodes, left, r + 1);
        }

        if (right - l > 20){
            _quickSort(pnodes, l, right);
        } else if (l < right - 1){
            _insertionSort(pnodes, l , right);
        }
        ////

    }

    public:
    
    void addNode(int i, int x, int y){
        nodes[i].x = x;
        nodes[i].y = -y;
        nodes[i].label = i + 1;
        nodes[i].parent = NULL;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
        sorted[i] = nodes + i;

    }

    decTree(){
        int a , b;
        
        
        in >> treeSize;
        nodes = new node[treeSize];
        sorted = new pnode[treeSize];
        for (int i = 0; i < treeSize; i++ ){
            in >> a >> b;
            addNode(i , a , b);
        }
        _quickSort(sorted, 0, treeSize);   
    }

    

    
    
    

    void buildTree(){
        pnode last = NULL;
        
        if (treeSize > 0){
            root = sorted[0];
            last = root;
            for (int i = 1; i < treeSize; i++){
                while (last->parent != NULL && sorted[i]->y > last->y){
                    last = last->parent;
                }
                if (sorted[i]->y <= last->y){
                    sorted[i]->left = last->right;
                    sorted[i]->parent = last;
                    if (last->right){
                        last->right->parent = sorted[i];
                    }
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

    void displayResults(){
        int parent, left, right;
        out << "YES" << endl;
        for (int i = 0; i < treeSize; i++){
            if (nodes[i].parent) {
                parent = nodes[i].parent->label;
            } else {
                parent = 0;
            }
            if (nodes[i].left){
                left = nodes[i].left->label;
            }  else {
                left = 0;
            }
            if (nodes[i].right) {
                right = nodes[i].right->label;
            } else {
                right = 0;
            }
            
            out << parent << " " << left << " " << right << endl;
        }
    }
};




int main(void){
    
    
    decTree *mytree = new decTree();
    mytree->buildTree();
    mytree->displayResults();
    return 0;
}
