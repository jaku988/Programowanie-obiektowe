#ifndef _2_h
#define _2_h
#include <iostream>
using namespace std;

class A
{
    string p;
    int x;
public:
    A(string p="", int x=0): p(p), x(x) {};
    virtual ~A() = default;
    int getX() const {return x;};
    virtual void drukuj(){ cout << p << " " << x << endl;}
    virtual void ustaw(string p, int x){this->p = p; this->x = x;}
    friend ostream& operator<<(ostream& os, const A& a){
        os << "text: " << a.p << " id: " << a.x;
        return os;
    }
};

class B : public A
{
    bool t;
public:
    B(string p, int x=0, bool t=false) : A(p, x), t(t) {};
    B(string p, const B& obj) : A(p, obj.getX()), t(obj.t){};
    virtual void drukuj(){A::drukuj(); cout << t << endl;};
    virtual void ustaw(string p, int x, bool t){A::ustaw(p, x); this->t = t;}
    friend ostream& operator<<(ostream &os, const B &b){
        os << (A&)b << " bool: " << b.t;
        return os;
    }
};



#endif /* _2_h */
