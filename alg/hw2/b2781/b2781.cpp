/**
 * task b aka 2781
 * link: http://informatics.mccme.ru/moodle/mod/statements/view3.php?id=1974&chapterid=2781#1
 * Copyright reserved.
 * author: Gumeniuk Stanislav
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;



class vertex{
    public:
    int x, y, label;
    vertex *parent, *left, *right;
    
    vertex() {}
    
    
    
    vertex(int xi, int yi, int labeli) {
        x = xi;
        y = -yi;
        label = labeli;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    
    
};


typedef vertex *pvertex;


class decTree{
    private:
    int treeSize;
    vertex *vertexs;
    pvertex *ordered;
    pvertex root;
    int vertexCount;
    
    public:

    void sortIns(pvertex *pvertexs, int left, int right) {
        pvertex shift;

        for (int i = left + 1; i < right; i++) {
            int j = i - 1;
            shift = pvertexs[i];
            
            for ( ; ((j >= left) && (pvertexs[j]->x > shift->x)) ; j--) {                
                pvertexs[j + 1] = pvertexs[j];
            }
            pvertexs[j + 1] = shift;
        }
    }

    void sortQuick(pvertex *pvertexs, int left, int right) {
        int l = left;
        int r = right-1;
        pvertex p;

        p = pvertexs[l + rand() % (right - left)];

        do{
            while (pvertexs[l]->x < p->x) {
                l++;
            }
            while (pvertexs[r]->x > p->x) {
                r--;
            }

            if (l <= r) {
                swap(pvertexs[l++], pvertexs[r--]);
            }
        } while (l <= r);

        if (r - left > 16) {
            sortQuick(pvertexs, left, r + 1);
        } else if (r > left) {
            sortIns(pvertexs, left, r + 1);
        }

        if (right - l > 16) {
            sortQuick(pvertexs, l, right);
        } else if (l < right - 1) {
            sortIns(pvertexs, l , right);
        }
        ////

    }

    void makeTree(){
        pvertex last = NULL;
        root = ordered[0];
        last = root;
        for (int i = 1; i < treeSize; i++) {
            while (last->parent != NULL && ordered[i]->y > last->y) {
                last = last->parent;
            }
            if (ordered[i]->y <= last->y) {
                ordered[i]->left = last->right;
                ordered[i]->parent = last;
                if (last->right) {
                    last->right->parent = ordered[i];
                }
                last->right = ordered[i];

            } else {
                ordered[i]->left = last;
                last->parent = ordered[i];
                root = ordered[i];
            }
            last = ordered[i];
        }
        
    }



    
    
    void vertexAdd(int x, int y) {
        vertexs[vertexCount] = *(new vertex(x, y, vertexCount + 1));
        ordered[vertexCount] = vertexs + vertexCount;
        vertexCount++;
        sortQuick(ordered, 0, treeSize);
        makeTree(); 
    }   

    explicit decTree(int size):treeSize(size) {
        vertexCount = 0;
        vertexs = new vertex[treeSize];
        ordered = new pvertex[treeSize];    
    }

    
    void loadData() {
        ifstream in("input.txt");
        int a , b;
        in >> treeSize;
        vertexs = new vertex[treeSize];
        ordered = new pvertex[treeSize];
        for (int i = 0; i < treeSize; i++ ) {
            in >> a >> b;
            //vertexs[vertexCount].set(a, b, vertexCount + 1);
            vertexs[vertexCount] = *(new vertex(a, b, vertexCount + 1));
            ordered[vertexCount] = vertexs + vertexCount;
            vertexCount++;
        }
        in.close();
    }

    void init() {
        srand(time(NULL));
        sortQuick(ordered, 0, treeSize);
            
    }

    decTree() {
        vertexCount = 0;
    }

    ~decTree() {
        delete[] vertexs;
        delete[] ordered;
    }
    

    void resultsDisplay() {
        ofstream out("output.txt");
        int parent, left, right;
        out << "YES" << endl;
        for (int i = 0; i < treeSize; i++) {
            if (vertexs[i].parent) {
                parent = vertexs[i].parent->label;
            } else {
                parent = 0;
            }
            
            if (vertexs[i].left) {
                left = vertexs[i].left->label;
            }  else {
                left = 0;
            }
            
            if (vertexs[i].right) {
                right = vertexs[i].right->label;
            } else {
                right = 0;
            }
            
            out << parent << " " << left << " " << right << endl;
        }
        out.flush();
        out.close();
    }
};




int main(void) {
    decTree *mytree = new decTree();
    mytree->loadData();
    mytree->init();
    mytree->makeTree(); 
    mytree->resultsDisplay();
    return 0;
}
