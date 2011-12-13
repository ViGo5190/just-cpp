#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int levenDist ( const string &a , const string &b ){
    if ( a == b ){
        return 0;
    }
    
    const int a_size = a.size();
    const int b_size = b.size();
    
    if ( a_size == 0 ) {
        return b_size;
    } else if ( b_size == 0 ){
        return a_size;
    }


    const int INF = a_size + b_size;
    vector < vector<int> > T( a_size + 2, vector<int> ( b_size + 2 ) );
    T[0][0] = 0;
    for ( int i = 0; i <= a_size; ++i ) { T[i][0] = i;  }
    for ( int j = 0; j <= b_size; ++j ) { T[0][j] = j; }

    int cost, above_cell,left_cell,dig_cell;
    for ( int i = 1; i <= a_size; ++i ){
        for ( int j = 1; j <= b_size; ++j) {
            cost = a[i-1] == b[j-1] ? 0 : 1;        
            above_cell = T[i-1][j];
            left_cell = T[i][j-1];
            dig_cell = T[i-1][j-1];
            T[i][j] = min( min( above_cell + 1 , left_cell + 1 ) , dig_cell + cost );
        }
    }

    return T[a_size][b_size];
}

int main(){
    string firstString;
    string secondString;
    
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> firstString;
    in >> secondString; 
    out << levenDist( firstString , secondString );    
    return 0;
}
