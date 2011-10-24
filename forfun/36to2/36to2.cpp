#include <iostream>
#include <stdint.h>
#include <cmath>
using namespace std;

int64_t mypow(int64_t val, int64_t P)
    {
    int64_t r = val;
    for (int64_t i=1; i<P; i++){
        r = r*val;
    }
    return r;
}


int main(){
    int64_t n;
    cin >> n;
    cout << mypow(2,n);
    return 0;
}
