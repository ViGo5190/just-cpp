#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int mysolve(){
    int n,k;
    string str;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> n >> k;
    in >> str;
    /*
    short *dp[n+1];
    for (int i = 0; i < n+1; i++) {
        short d[n+1];
        dp[i] = d;
    }
    */
    short **dp;
    dp = new short*[n+1];
    for (int i=0; i < n+1; i++){
        dp[i] = new short[n+1];
    }
    
    for ( int i = 1; i < n; ++i ){
        for ( int j = 0; j < n - i; ++j ) {
            int l = j + i;
            dp[j][l] = 1e4;
            if ( str[j] == str[l] ) {
                dp[j][l] = dp [j+1][l-1];
            } else if ( dp[j+1][l-1]+1 <= k){
                dp[j][l] = dp[j+1][l-1] + 1;
            }
        }
    }
    int res = n;
    for ( int i = 0; i<n; ++i) {
        //for ( int j = 0; j<=i; ++j) cout << dp[i][j]<< " ";
        for ( int j = i + 1; j < n; ++j ){
            //cout << dp[i][j] << "! ";
            if (dp[i][j] != 1e4){
                res++;
            }
        }

        //cout << endl;
    }
    out << res;
    
    return 0;
}
            

int main (){
    mysolve();
    return 0;
}
