#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "lab6_mem.hpp"



using namespace std;











int main(void) {
	cout << "start = " <<&ram;
	cout << endl;

	void *q[5];
 
	q[0] = my_alloc(5);
	cout << "q0 = " << q[0] << endl;
	q[1] = my_alloc(5);
	cout << "q1 = " << q[1] << endl;
	q[2] = my_alloc(5);
	cout << "q2 = " << q[2] << endl;
	q[3] = my_alloc(5);
	cout << "q3 = " << q[3] << endl;
}