#include <iostream>

using namespace std;

class qwe {
	int a;
		
};

class qwewptr {
	int a;
	qwewptr *p;
		
};

class qwewtwoptr {
	int a;
	qwewtwoptr *p;
	qwewtwoptr *l;
		
};

class qwewtwoptrnoint {
	
	qwewtwoptrnoint *p;
	qwewtwoptrnoint *l;
		
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