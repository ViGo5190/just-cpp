#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int damerauLevenshteinDistance( const std::vector<char>& a, const std::vector<char>& b )
{
    const int a_size = static_cast<int>( a.size() );
    const int b_size = static_cast<int>( b.size() );
    const int INF = a_size + b_size;
    std::vector<std::vector<int> > H( a.size()+2, std::vector<int>( b.size()+2 ) );
    H[0][0] = INF;
    for ( int i = 0; i <= a_size; ++i ) { H[i+1][1] = i; H[i+1][0] = INF; }
    for ( int j = 0; j <= b_size; ++j ) { H[1][j+1] = j; H[0][j+1] = INF; }
     
    const int alphabet_size = std::numeric_limits<char>::max();
    std::vector<char> DA( alphabet_size );
    for ( int d = 0; d < alphabet_size; ++d ) DA[d] = 0;
    for ( int i = 1; i <= a_size; ++i ) {
        size_t DB = 0;
        for ( int j = 1; j <= b_size; ++j ) {
            const int i1 = DA[ b[j-1] ];
            const int j1 = DB;
            const int d = (a[i-1]==b[j-1]) ? 0 : 1;
            if ( d == 0 ) DB = j;
            H[i+1][j+1] = std::min( 
                std::min(H[i][j]+d, H[i+1][j]+1), 
                std::min(H[i][j+1]+1, H[i1][j1] + (i-i1-1) + 1 + (j-j1-1) ) );
        }
        DA[ a[i-1] ] = i;
    }
    return H[a.size()+1][b.size()+1];
}

int main(){
    string firstString;
    string secondString;
    
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> firstString;
    in >> secondString; 
    cout << firstString;
    cout << endl << secondString;    
    return 0;
}
