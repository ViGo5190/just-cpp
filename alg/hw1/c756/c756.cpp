/**
 * task c aka 756
 * link: http://informatics.mccme.ru/moodle/mod/statements/view3.php?id=598&chapterid=756
 * Copyright reserved.
 * author: Gumeniuk Stanislav
 */

#include <iostream>
#include <fstream>

using namespace std;

class mydeque {
	private:
		int * _data;
		int _size;
		int _begin, _end;

		int _next(const int nexti) {
			
				if (nexti == _size - 1) {
					return 0;
				}
				return nexti + 1;
			
		}

		int _prev(const int previ) {
				if (previ == 0) {
					return _size - 1;
				}
				return previ - 1;
			
		}
	public:
		mydeque(int size): _size(size), _data(new int[size]), _begin(0), _end(0) {}
		~mydeque() {
			delete [] _data;
		}
		
		bool empty() {
			return _begin == _end;
		}	

		void push_back(const int &p) {
			
				_data[_end] = p;
				_end = _next(_end);
		}

		void pop_back() {
			
				_end = _prev(_end);
			
		}

		void pop_front() {
			
				_begin = _next(_begin);	
			
		}

		

		int front() {
			return _data[_begin];
		}

		int back() {
			return _data[_prev(_end)];
		}
		
		
		
		
};


int main(void) {
	int n, k;
	
	int it;




	ifstream in("input.txt");
	in >> n >> k;

	int *mydata = new int[n];
	mydeque arr(k);

	for (int i = 0; i < n; ++i) {
		in >>mydata[i];
	}

	in.close();
	it = 0;
	for (it = 0; it < k; ++it) {
		while ( !(arr.empty()) && (mydata[it] <= mydata[arr.back()]) )
			arr.pop_back();
		arr.push_back(it);
	}

	ofstream out("output.txt");
	out << mydata[arr.front()] <<endl;
	
	it = 0;
	
	while (it < n-k) {
		
		++it;
		if (it > arr.front()) {
			arr.pop_front();
		}
		
		while ( !(arr.empty()) && (mydata[it + k - 1] <= mydata[arr.back()]) )
			arr.pop_back();
		arr.push_back(it + k -1);	
		
		
		out << mydata[arr.front()] << endl;
		
	} 
	
	out.flush();
	out.close();

	delete [] mydata;
	return 0;
}