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


using namespace std;



int main(void) {
	int n, k, t;
	deque< pair<int, int> > arr;
	deque< pair<int, int> > :: iterator it;
	//deque<int> arr;

	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> n >> k;
	for (int i = 0; i < n; i++) {
	//while (in >> t) {
		in >> t;

		if (k==1) {
			out << t << endl;
		} else {
			int delq = 0;
			
			if (!arr.empty()) {
				it = arr.begin();
				while ( !arr.empty() && it != arr.end() && (*it).second < t ) {
					//cout << "&"<< endl;
					if ((delq == 0) && (i >= k ) && ((*it).first == i-k) ) {
						cout << " delete " << (*it).first << " ";
						arr.erase(it);
						delq = 1;
						if (it != arr.begin()) --it;
						
					}
					it++;
				}

				arr.insert(it, make_pair(i,t));
			} else {
				arr.push_back(make_pair(i,t));	
			}

			
			
			
			
			if ((i >= k ) && (delq == 0)) {
				if (it != arr.begin()) --it;
				for (; it < arr.end(); it++ ){
				//cout << "!" << (*it).first << "!" ;
					if ((*it).first == i-k) {
						cout << " delete " << (*it).first << " ";
						arr.erase(it);
			
						break;
					}
				}
				
			}
			
			cout << endl ;
			for (int j = 0; j < arr.size()  ; j++) {
				cout << arr[j].second<<"|"<<arr[j].first << " ";
			}  cout << " " << i-k<< endl;
				
			
			

		
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