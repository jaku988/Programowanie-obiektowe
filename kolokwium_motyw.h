#ifndef UNTITLED_MOTYW_H
#define UNTITLED_MOTYW_H
#include <iostream>
using namespace std;

static int ile = 0;

class Motyw
{
    char znak1;
public:
    Motyw(char p): znak1(p) {ile++;};
    Motyw(Motyw &m1);
    virtual ~Motyw(){ile--;};
    virtual void rysuj(){cout << znak1;};
    virtual char getZnak1() const {return znak1;};
    static int getIle(){return ile;};
    friend ostream& operator<<(ostream &os, Motyw &m1);
};



Motyw::Motyw(Motyw &m1)
{
    this->znak1 = m1.znak1;
}

class MotywZlozony : public Motyw
{
    char znak1;
    char znak2;
    int dlugosc;
public:
    MotywZlozony(char p, char q,  int n): Motyw(p), znak2(q), dlugosc(n) {};
    ~MotywZlozony(){};
    virtual void rysuj();
    friend ostream& operator<<(ostream &os, MotywZlozony &m1);
    virtual MotywZlozony &operator!();
    char getZnak1() const {return Motyw::getZnak1();};
    char getZnak2() const {return znak2;};
};

void MotywZlozony::rysuj()
{
    for(int i=0; i<dlugosc; i++)
    {
        Motyw::rysuj();
        cout << znak2;
    }
}

ostream& operator<<(ostream &os, Motyw &m1)
{
    os << m1.znak1;
    return os;
}

ostream &operator<<(ostream &os, MotywZlozony &m1)
{
    for(int i=0; i<m1.dlugosc; i++)
    {
        os << m1.znak1 << m1.znak2;
    }
    return os;
}

MotywZlozony &MotywZlozony::operator!() {
    char temp = getZnak1();
    znak1 = getZnak2();
    znak2 = temp;
}











#endif //UNTITLED_MOTYW_H
