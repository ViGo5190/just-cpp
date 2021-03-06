#include <iostream>
#include <algorithm>
using namespace std;

inline size_t min(size_t first, size_t second){
    return first<=second?first:second;
}
inline size_t max(size_t first, size_t second){
    return first>=second?first:second;
}
class array{
private:
	int 	*p;
	size_t 	size;

public:
array(size_t t){
	p 	= new int[t];
	size 	= t;
	}
array(array const& copy):size(copy.size),p(new int[copy.size]){
	std::copy(copy.p, copy.p + copy.size, p);
	}
array(){
	p 	= new int[1];
	size	= 1;
	}
int get(size_t index){
	return p[index];
	}
void set(size_t i, int v){
	p[i]	= v;
	}
inline int size_of(){return size;}
void resize(size_t t){
	int *newp = new int[t];
    for (int i=0;i<max(size,t);i++){
        if (i<min(size,t)) { newp[i] = p[i];}
        else { newp[i] = 0;}
    }

    delete[] p;
	p 	= newp;
    size =  t;
	}

void push_back(int a){
    
    resize(size+1);
    p[size-1] = a;

    }

array operator =( array& rhs){
	//size 	= rhs.size_of();
	resize(rhs.size_of());
	for (size_t i=0;i<rhs.size_of();i++){
        p[i]	= rhs.get(i);
		}
    return *this;    
	}
//inline bool operator==(array& f, array& s){
//	return true;
//	}
inline int &operator [](size_t i) { return p[i];}
//inline void operator []+(size_t i,int k){}
~array(){
	delete[] p;
	}
};






int main(){
array m(10);
array n(15);
for (size_t i=0;i<n.size_of();i++){
	n.set(i,i*2);
	cout << n[i] << " ";
	}
cout << endl;
for (size_t i=0;i<m.size_of();i++){
	m.set(i,i*3);
	cout << m[i] << " ";
	}
cout << endl;
cout<< "qqq" <<endl;
m = n;
cout << "www" <<endl;
n.set(9,100000);

for (size_t i=0;i<n.size_of();i++){
	cout << n[i] << " ";
	}
cout << endl;
for (size_t i=0;i<m.size_of();i++){
	cout << m[i] << " ";
	}
cout << endl;



array k = n;
n.set(8,123);
for (size_t i=0;i<n.size_of();i++){
	cout << n[i] << " ";
	}
cout << endl;

for (size_t i=0;i<k.size_of();i++){
	cout << k[i] << " ";
	}
cout << endl;

k.resize(22);

for (size_t i=0;i<k.size_of();i++){
    cout << k[i] << " ";
    }
cout << endl;

k.push_back(13);
for (size_t i=0;i<k.size_of();i++){
    cout << k[i] << " ";
    }
cout << endl;



cout << k[0]<<endl;

return 0;
}
