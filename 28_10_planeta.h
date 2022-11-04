#ifndef PLANETA_H
#define PLANETA_H
#include "plaszczak.h"

class Planeta
{
    int wymx;
    int wymy;
    char znak;
    Plaszczak *wskp;
public:
    Planeta(int x, int y, char z);
    void zaplaszczakuj(Plaszczak* p);
    void drukuj() const;
    int gety() {return wymy;};
    int getx() {return wymx;};
};
Planeta::Planeta(int x, int y, char z)
{
    wymx = x;
    wymy = y;
    znak = z;
    wskp = nullptr;
}

void Planeta::zaplaszczakuj(Plaszczak* p)
{
    wskp = p;
    p->ustawpozycje(wymx/2, wymy/2);
}

void Planeta::drukuj() const
{
    int pozycjax = wskp->getx();
    int pozycjay = wskp->gety();

    for(int j=0;j<wymy; j++)
    {
        for(int i=0; i<wymx; i++)
        {
            if( i==0 || j==0 || i==wymx-1 || j==wymy-1)
            {
                cout << znak;
            }
            else if(wskp!=nullptr && i==pozycjax && j ==pozycjay)
            {
                wskp->drukuj();
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
    cout << endl;

}

#endif // PLANETA_H
