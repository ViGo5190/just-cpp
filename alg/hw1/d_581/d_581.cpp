/**
 * task d aka 581
 * link: http://informatics.mccme.ru/moodle/mod/statements/view3.php?id=3333&chapterid=581#1
 * Copyright reserved.
 * author: Gumeniuk Stanislav
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

class shelter {
	public:
		int index;
		int position;

		shelter(int a, int b):index(a),position(b) {}
		shelter():index(0),position(0) {}
};


void printsh (shelter * a,int size) {
	//int size  = sizeof()
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << a[i].position << "-" << a[i].index << " ";
	}
	cout << endl;
}

int bin_search(shelter * arr, int pos, int size) {
	int low = 0;
	int hight = size - 1;
	int med;
	if (arr[0].position > pos) {
		return 0;
	} else if (arr[hight].position < pos) {
		return hight;
	}
	
	while (  hight - low > 0 ) {
		med = (hight-low)/2;
		if (arr[med].position < pos) {
			low = med + 1;
		} else if (arr[med].position > pos) {
			hight = med ;
		} else return med;
	}

	if (arr[hight].position - pos > pos - arr[hight-1].position) {
		return hight -1;
	} else {
		return hight;
	}
	return 0;
}

void quick_sort(shelter * arr, int left, int right, int size) {
	int low = left;
	int hight = right;
	int x = arr[size/2].position;
	int ti, tp;
	//printsh(arr, size);
	do {
		while (arr[low].position < x) low++;
		while (arr[hight].position > x) hight--;
		if (low < hight) {
			ti = arr[hight].index;
			tp = arr[hight].position;

			arr[hight].index = arr[low].index;
			arr[hight].position = arr[low].position;

			arr[low].index = ti;
			arr[low].position = tp;

			low++; hight--;
		}

		
	} while (low <= hight);
	if (left < hight) quick_sort(arr,left, hight,size);
	if (low < right) quick_sort(arr, low, right,size);
	return;
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
		shelters[i] = *(new shelter(i+1,t));
		//cout << shelters[i].position << " ";
	}
	in.close();

	//printsh(shelters, k);
	//cout << "q"<<endl;
	quick_sort(shelters, 0, k-1,k);
	//printsh(shelters, k);

	//cout << shelters[bin_search(shelters, 1, n)].position;
	for (int i = 0; i< n; i++) {
		cout << shelters[bin_search(shelters, village[i], k)].index << " ";
		//cout << bin_search(shelters, village[i], k) << " ";
	}


	delete [] village;
	delete [] shelters;
	return 0;
}