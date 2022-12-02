#ifndef figura_h
#define figura_h
#include <iostream>
using namespace std;

class Figura
{
public:
    virtual void drukuj() const = 0;
    virtual ~Figura() = default;
};

class Square : public Figura
{
public:
    void drukuj(){cout << "\u25a1";};
    ~Square(){cout << "square deleted";};
};

class Triagle : public Figura
{
public:
    void drukuj(){cout << "\u25cf";};
    ~Triagle(){cout << "Triangle deleted";};
};

class Circle : public Figura
{
public:
    void drukuj(){cout << "\u25EC";};
    ~Circle(){cout << "Circle deleted";};
};

class Element
{
    Figura *value;
    Element* next;
public:
    Element(Figura *v, Element* n) : value(v), next(n) {}
    void wypisz(){value->drukuj();};
    Element* getNext(){return next;};
};

class FigureStack
{
    Element* top;
public:
    FigureStack(){this->top = nullptr;}
    virtual ~FigureStack();
    void push(Figura *v);
    Figura* pop();
    friend ostream& operator<<(ostream &os, const FigureStack& s);
};

void FigureStack::push(Figura *v)
{
    top = new Element(v, top);
}

ostream& operator<<(ostream &os, const FigureStack& s){
    Element *iterator=s.top;
    while(iterator)
    {
        os << iterator->wypisz();
        iterator = iterator->getNext();
    }
    return os;
}












#endif /* figura_h */
