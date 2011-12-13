#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void solve(const int &n, const int &k, const string &str){
    short dp[50001][5001];
    for ( int i = 1; i < n; ++i ){
        for ( int j = 0; j < n - i; ++j ) {
            int l = j + i;
            dp[j][l] = 1e4;
            if ( str[j] == str[l] ) {
                dp[j][l] = dp [j+1][l-1];
            } else if ( dp[j+1][l-1]+1<= k){
                dp[j][l] = dp[j+1][l-1] + 1;
            }
        }
    }
    int res = n;
    for ( int i = 0; i<n; ++i) {
        for ( int j = i + 1; j < n; ++j ){
            if (dp[i][j] != 1e4){
                res++;
            }
        }
    }
    cout << res;
}
            

int main (){
    int n,k;
    string str;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> n >> k;
    in >> str;

    solve(n,k,str);
    cout << str;
    return 0;
}
