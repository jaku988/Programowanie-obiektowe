#ifndef UNTITLED_GRA_H
#define UNTITLED_GRA_H
#include "symbol.h"

class Gra
{
    int r;
    Symbol* **symbole = new Symbol**[r];
public:
    Gra(int r);
    ~Gra();
    Gra(Gra &g1);
    friend ostream& operator<<(ostream &os, Gra &g);
    void wstaw(int x, int y, Symbol *s);
    Gra operator-=(const char p);
};



Gra::Gra(int r)
{
    this->r = r;
    for(int i=0; i<r; i++)
    {
        symbole[i] = new Symbol*[r];
    }
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<r; j++)
        {
            symbole[i][j] = new Kropka;
        }
    }
}

Gra::~Gra()
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<r; j++)
        {
            delete symbole[i][j];
        }
        delete symbole[i];
    }
    delete [] symbole;
    this->r = 0;
    cout << "Gra deleted" << endl;
}

ostream& operator<<(ostream &os, Gra &g1)
{
    for(int i=0; i<g1.r; i++)
    {
        for(int j=0; j<g1.r; j++)
        {
            os << g1.symbole[i][j]->getZnak() << " ";
        }
        os << endl;
    }
    return os;
}

void Gra::wstaw(int x, int y, Symbol *s)
{
    symbole[x][y] = s;
}

Gra Gra::operator-=(const char p)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<r; j++)
        {
            if(symbole[i][j]->getZnak() == p)
            {
                cout << "~" << p << endl;
                symbole[i][j] = new Kropka;
            }
        }
    }
    return *this;
}

Gra::Gra(Gra &g1)
{
    if(g1.r > 0)
    {
        this->r = g1.r;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < r; j++)
            {
                this->symbole[i][j] = g1.symbole[i][j];
            }
        }
    }
}



#endif //UNTITLED_GRA_H
