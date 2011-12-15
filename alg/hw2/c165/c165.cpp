#include <iostream>
#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
struct mynode {
    int num;
    mynode *next;
};

typedef mynode *listnode;

struct mypoint {
    int color;
    listnode edges;
};

struct mygraph {
    int size;
    mypoint *points;
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

listnode create_node(int num){
    //listnode p = (listnode) malloc(sizeof(mynode));
    //assert( p != NULL);
    listnode p = new mynode;
    p->num = num;
    p->next = NULL;

    return p;
}

void destroy_list(listnode lst){
    listnode node = NULL;
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

void destroy_graph(mygraph *gr){
    for(int i = 0; i <= gr->size; i++){
        destroy_list(gr->points[i].edges);
    }
    delete gr->points;
}

void addedge(mygraph *gr, int point1, int point2){
    listnode node1 = NULL, node2 = NULL;
    node1 = create_node(point1);
    node2 = create_node(point2);

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
    listnode curr = NULL;
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

int dfs_coloring(mygraph *gr){
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
                out << i;
    }
}

static mygraph graph;

void init(){
    int pairs, points;
    int point1,point2;
    in >> points >> pairs;
    create_graph(&graph, points);
    for (int i = 1; i <= pairs; i++){
        in >> point1 >> point2;
        addedge(&graph, point1, point2);
    }
}

void finit(){
    destroy_graph(&graph);
}

int main(void){
    init();
    if (dfs_coloring(&graph) != -1) {
        out << "YES" << endl;
        printpoins(&graph);
    } else
        out << "NO"<<endl;
    finit();
    return 0;
}
