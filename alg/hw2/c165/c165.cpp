#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

struct mynode {
    int num;
    mynode *next;
};

typedef mynode *mylist;

struct __mypoint {
    int color;
    mylist edges;
};

typedef __mypoint mypoint;

struct __mygraph {
    int size;
    mypoint *points;
};

typedef __mygraph mygraph;

mylist pop(mylist *list){
    mylist node = *list;

    if (*list != NULL)
        *list = node->next;
    else 
        *list = NULL;
    return node;
}

mylist push(mylist list, mylist node){
    if (node != NULL) {
        node->next = list;
        return node;
    }
    return list;
}

mylist create_node(int num){
    mylist p = new mynode;
    assert(p != NULL);
    p->num = num;
    p->next = NULL;

    return p;
}

void destroy_list(mylist lst){
    mylist node = NULL;
    while (lst != NULL){
        node = lst;
        lst=lst->next;
        delete node;
    }
}

void create_graph(mygraph *gr, int size){
    int i;
    gr->size = size;
    gr->points = new mypoint[size+1];
    for (i = 0; i<= size; i++) {
        gr->points[i].edges = NULL;
        gr->points[i].color = -1;
    }
}



void addedge(mygraph *gr, int point1, int point2){
    mylist node1 = NULL, node2 = NULL;
    assert(gr->size >= point1 && gr->size >= point2);
    node1 = create_node(point1);
    node2 = create_node(point2);
    assert(node1 != NULL && node2 != NULL);

    gr->points[point1].edges = push(gr->points[point1].edges, node2);
    gr->points[point2].edges = push(gr->points[point2].edges, node1);
}

int coloring(mypoint *point, int color){
    if (point->color == -1) {
        point->color = color;
        return 0;
    }else if (point->color == color){
        return 1;
    } else
        return -1;
}

int dfs_from_point_coloring(mygraph *gr, int num, int color){
    mylist curr = NULL;
    int rc = coloring(gr->points+num, color);

    if (rc == 0){
        curr = gr->points[num].edges;
        while (curr != NULL && rc >= 0){
            rc = dfs_from_point_coloring(gr, curr->num, (color+1)%2);
            curr = curr->next;
        }
    }

    return rc;
}

int dfs_color(mygraph *gr){
    int  rc =1;
    if (gr != NULL || gr->size != 0){
        for(int i=1; i<=gr->size && rc >= 0; i++)
            if (gr->points[i].color == -1)
                rc = dfs_from_point_coloring(gr, i ,1);
    }

    return rc;
}

void printpoins(mygraph *gr){
    if (gr != NULL && gr->size > 0){
        for (int i = 1;i <= gr->size; i++)
            if (gr->points[i].color == 1)
                out << i << " ";
    }
}





int main(void){
    mygraph gr;
    int pairs, points;
    int point1,point2;
    in >> points >> pairs;
    create_graph(&gr, points);
    for (int i = 1; i <= pairs; i++){
        in >> point1 >> point2;
        addedge(&gr, point1, point2);
    }
    if (dfs_color(&gr) != -1) {
        out << "YES" << endl;
        printpoins(&gr);
    } else
        out << "NO"<<endl;
    
    return 0;
}
