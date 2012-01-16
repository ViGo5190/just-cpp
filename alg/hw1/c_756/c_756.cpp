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
	deque< pair<int, int> > :: iterator it, itdel;
	//deque<int> arr;

	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> n >> k;
	for (int i = 0; i < n; i++) {
	//while (in >> t) {
		in >> t;

		if (k==1) {
			cout << t << endl;
		} else {
			int del = 0;
			
			if (!arr.empty()) {
				it = arr.begin();
				while ( !arr.empty() && it != arr.end() && ((*it).second < t )) {
					if ((i>=k)&&((*it).first == i - k)) {
						itdel = it;
						del = 1;
					}
					it++;
					

				}
			}

			
			
			
			

			if (arr.empty()) {
				arr.push_back(make_pair(i,t));
			} else {
				arr.insert(it, make_pair(i,t));
			}

			
			
			if ((i >= k ) && (del==0)) {
				it--;
				for (; it < arr.end(); it++ ){
				// /cout << "!" << (*it).first << "!" ;
					if ((*it).first == i-k) {
						//arr.erase(it);
						itdel = it;
						del = 1;
						//break;
					}
				}
				
			}

			if (del == 1) {
				arr.erase(itdel);
			}
			/*
			cout << endl ;
			for (int j = 0; j < arr.size()  ; j++) {
				cout << arr[j].second<<"|"<<arr[j].first << " ";
			}  cout << " " << i-k<< endl;
			*/	
			
			

		
			if (i >= k-1) {
				out  << arr.front().second << endl;	
			}
		}	
	}
	in.close();
	out.flush();
	out.close();
	return 0;
}