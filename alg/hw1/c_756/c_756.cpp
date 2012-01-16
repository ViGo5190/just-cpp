/**
 * task c aka 756
 * link: http://informatics.mccme.ru/moodle/mod/statements/view3.php?id=598&chapterid=756
 * Copyright reserved.
 * author: Gumeniuk Stanislav
 */

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

static const int MAX = 2147483647;

int main () {
	ifstream in("input.txt");
	int n, k;
	int t;
	in >> n >> k;
	


	vector <int> q;
	vector <int> mins;

	int tmin = MAX;

	for (int i = 0; i < k; i++) {
		in >> t;
		tmin = t < tmin ? t : tmin;
		q.push_back(t);
	}

	mins.push_back(tmin);

	

	for (int i = k; i < n; i++) {
		tmin = MAX;
		in >> t;
		q.push_back(t);
		if (t <= mins[i - k]) {
			mins.push_back(t);
		} else if (q[0] == mins[i - k]) {

			for (int j = 1; j <= k; j++) {
				tmin = q[j] < tmin ? q[j] : tmin;
			}
			mins.push_back(tmin);
		
		} else {
			mins.push_back(mins[i - k]);
		}
	for (int i = 0; i < n; i++) {
		cout << q[i] << " ";
	} cout << endl;
		q.erase(q.begin());
	
	
	}
	/*
	for (int i = 0; i < n - k + 1; i++) {
		cout << mins[i] << endl;
	}
	*/
	return 0;
}