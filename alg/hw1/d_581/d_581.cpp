/**
 * task d aka 581
 * link: http://informatics.mccme.ru/moodle/mod/statements/view3.php?id=3333&chapterid=581#1
 * Copyright reserved.
 * author: Gumeniuk Stanislav
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class shelter {
	public:
		int index;
		int position;

		shelter(int a, int b):index(a),position(b) {}
		shelter():index(0),position(0) {}
};


void quick_sort() {
	
}



int main(void) {
	int n;
	int *village;
	int k;
	shelter *shelters;
	int t;

	ifstream in("input.txt");
	in >> n;
	village = new int[n];
	for (size_t i=0; i<n; i++) {
		in >> village[i];
	}
	in >> k;
	shelters = new shelter[k];
	for (int i=0; i<k; i++) {
		in >> t;
		shelters[k] = *(new shelter(i,t));
		cout << shelters[k].position << " ";
	}
	in.close();





	delete [] village;
	delete [] shelters;
	return 0;
}