#ifndef ulamek_h
#define ulamek_h
#include <iostream>
using namespace std;

class Ulamek
{
    int l;
    int m;
public:
    Ulamek(int l=0, int m=1);
    friend ostream& operator << (ostream& out, const Ulamek &u);
    Ulamek operator+(const Ulamek& u);
    Ulamek operator*(const Ulamek& u);
    Ulamek operator-() const;
    Ulamek operator-(const Ulamek& u);
    Ulamek operator~() const;
    Ulamek operator/(const Ulamek& u);
    Ulamek operator+(const int n);
    friend Ulamek operator+(const int n, Ulamek& u);
    Ulamek& operator++();
};

Ulamek::Ulamek(int l, int m)
{
    this->l = l;
    this->m = m;
}

ostream& operator<<(ostream& out, const Ulamek &u)
{
    return out << "[" << u.l << "/" << u.m << "]";
}

//Operator dodawania
//u.l oraz u.m to zmienne licznika i mianownika dowolnego innego ułamka ktory dodajemy w mainie(&u)
Ulamek Ulamek::operator+(const Ulamek& u)
{
    return Ulamek(l*u.m + u.l*m, m * u.m);
}

//Operator mnożenia
//u.l oraz u.m to zmienne licznika i mianownika dowolnego innego ułamka ktory mnozymy w mainie(&u)
Ulamek Ulamek::operator*(const Ulamek &u)
{
    return Ulamek(l*u.l, m*u.m);
}

Ulamek Ulamek::operator-(const Ulamek& u)
{
    return *this + (-u);
}

Ulamek Ulamek::operator-() const
{
    return Ulamek(-l, m);
}

Ulamek Ulamek::operator~() const
{
    return Ulamek(m, l);
}

Ulamek Ulamek::operator/(const Ulamek& u)
{
    return *this * ~u;
}

Ulamek Ulamek::operator+(const int n)
{
    return *this + Ulamek(n, 1);
}

Ulamek operator+(const int n, Ulamek& u)
{
    return u + n;
}

Ulamek& Ulamek::operator++()
{
    *this = *this + 1;
    return *this;
}


#endif /* ulamek_h */
