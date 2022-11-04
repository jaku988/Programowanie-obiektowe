#ifndef PLASZCZAK_H
#define PLASZCZAK_H
#include<iostream>
using namespace std;

enum Kierunek {GORA, DOL, LEWO, PRAWO};

class Plaszczak
{
    int pozx;
    int pozy;
    char postac;
    string imie;
public:
    Plaszczak(char p='?', string i="flatman");
    ~Plaszczak()=default;
    void ruch(Kierunek k);
    void drukuj() const;
    void ustawpozycje(int x, int y);
    int getx() {return pozx;}
    int gety() {return pozy;}

};
Plaszczak::Plaszczak(char p, string i)
{
    pozx = pozy = 0;
    postac = p;
    imie = i;
}

void Plaszczak::ruch(Kierunek k)
{
    switch (k)
    {
        case GORA: --pozy; break;
        case DOL: ++pozy;
        case LEWO: --pozx;
        case PRAWO: ++pozx;
    }
}
void Plaszczak::drukuj() const
{
    cout<<postac;
}
void Plaszczak::ustawpozycje(int x, int y)
{
    pozx=x;
    pozy=y;
}


#endif // PLASZCZAK_H
