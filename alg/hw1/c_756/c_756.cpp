/**
 * task c aka 756
 * link: http://informatics.mccme.ru/moodle/mod/statements/view3.php?id=598&chapterid=756
 * Copyright reserved.
 * author: Gumeniuk Stanislav
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <deque>
#include <map>

using namespace std;



int main(void) {
	int n, k, t;
	deque< pair<int, int> > arr;
	deque< pair<int, int> > :: iterator it;
	//deque<int> arr;

	ifstream in("input.txt");
	in >> n >> k;
	for (int i = 0; i < n; i++) {
		in >> t;

		if (k==1) {
			cout << t << endl;
		} else {

			//cout << " i " << i << endl;
			
			if (!arr.empty()) {
				it = arr.begin();
				//it = arr.end();
			}

			
			while ( !arr.empty() && it != arr.end() && (*it).second < t) {
			//while ( !arr.empty() && it != arr.begin() && (*it).second > t) {
				//arr.pop_back();
				//--it;
				it++;

			}
			
			

			pair<int, int> temppair(i,t);
			if (arr.empty()) {
				arr.push_back(temppair);
			} else {
				arr.insert(it, temppair);
			}

			
			
			//cout << "if" << endl;
			if (i >= k ) {
				for (it = arr.begin(); it < arr.end(); it++ ){
				// /cout << "!" << (*it).first << "!" ;
					if ((*it).first == i-k) {
						arr.erase(it);
						break;
					}
				}
				
			}
			/*
			cout << endl;
			for (int j = 0; j <= i ; j++) {
				cout << arr[j].second<<"|"<<arr[j].first << " ";
			}  cout << " " << i-k<< endl;
			*/	
			
			

		
			if (i >= k-1) {
				cout  << arr.front().second << endl;	
			}
		}	
	}
	in.close();
	return 0;
}