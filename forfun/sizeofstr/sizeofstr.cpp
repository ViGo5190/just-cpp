#include <iostream>

using namespace std;

class qwe {
	int a;
		
};

class qwewptr {
	int a;
	qwe *p;
		
};

class qwewtwoptr {
	int a;
	qwe *p;
	qwe *l;
		
};

class qwewtwoptrnoint {
	
	qwe *p;
	qwe *l;
		
};


int main(void) {
	cout << sizeof (qwe) << endl;
	cout << sizeof (qwewptr) << endl;
	cout << sizeof (qwewtwoptr) << endl;
	cout << sizeof (qwewtwoptrnoint) << endl;
	qwewptr *o;
	cout << sizeof (o);
	return 0;
}