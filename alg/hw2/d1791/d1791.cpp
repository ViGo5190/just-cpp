#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;



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
