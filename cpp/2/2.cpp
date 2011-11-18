#include <iostream>

using namespace std;


static int nod(int a, int b){
if (b == 0)
    return a;
return nod(b,a%b);
}

static int nok(int a, int b){
    return a*b/nod(a,b);
}




class rational{
private:
    int q,r;
public:

    void balans(){
        int thisnod = nod(q,r);
        if (thisnod>1){
            q = q/thisnod;
            r = r/thisnod;
        }
    }
    
    rational():q(1),r(1){}

    rational(int qq,int rr):q(qq),r(rr){balans();}
    
    rational(rational const &a):q(a.q),r(a.r){balans();}

    rational& operator=(const rational &a){
        q = a.q;
        r = a.r;
        balans();
        return *this;
    }
    
    rational& operator++(int){
        q=q+r;
        return *this;
    }
    /*
    rational operator++(){
        q=q+r;
        return *this;
    }
    */

    rational& operator--(int){
        q=q-r;
        return *this;
    }

    rational& operator+=(rational const &a){
        int newr = nok(r, a.r);
        int newq = q*(newr/r) + a.q*(newr/a.r);
        q = newq;
        r = newr;
        balans();
        return *this;
    }

    rational& operator-=(rational const &a){
        int newr = nok(r, a.r);
        int newq = q*(newr/r) - a.q*(newr/a.r);
        q = newq;
        r = newr;
        balans();
        return *this;
    }

    rational& operator*=(rational const &a){
        q = q*a.q;
        r = r*a.r;
        balans();
        return *this;
    }

    rational& operator/=(rational const &a){
        r = r*a.q;
        q = q*a.r;
        balans();
        return *this;
    }

    friend ostream& operator<<(ostream &os, rational const &a);
    friend rational operator+(rational const &a, rational const &b);
};

ostream& operator<<(ostream &os, rational const &a){
        os << "(" << a.q <<"/" << a.r << ")";
        return os;
    }

rational operator+(rational const &a, rational const &b){
    rational t(a);
    t+=b;
    return t;
}
rational operator-(rational const &a, rational const &b){
    rational t(a);
    t-=b;
    return t;
}
rational operator*(rational const &a, rational const &b){
    rational t(a);
    t*=b;
    return t;
}
rational operator/(rational const &a, rational const &b){
    rational t(a);
    t/=b;
    return t;
}
int main(){
    int a;

    rational q(6,4);
    
    rational w;
    rational e;
    rational r;
    rational t(7,3);
    w=q;
    e = q++;

    t--;
    //q.r = 5;
    cout <<q << w << e<<r << t<<endl;

    rational aa(3,4);
    rational bb(1,4);
    rational cc;
    cc = aa/ bb;
    cout <<cc;
return 0;
}
