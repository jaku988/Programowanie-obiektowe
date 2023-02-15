#ifndef UNTILTED_POCIAG_H
#define UNTILTED_POCIAG_H
#include "zwierze.h"

class Wagon
{
public:
    int ile;
    Zwierze *z;
    Wagon *next;
    Wagon(int ile=0, Zwierze *z= nullptr, Wagon *next= nullptr): ile(ile), z(z), next(next){};
};

class Pociag
{
    int ile_wagonow;
    Wagon *lokomotywa;
public:
    Pociag();
    ~Pociag();
    friend ostream& operator<<(ostream &os, Pociag &p1);
    void wstaw(int i, Zwierze *z);
    void odczep(int a);
};

Pociag::Pociag()
{
    ile_wagonow = 0;
    lokomotywa = nullptr;
}

Pociag::~Pociag()
{
    if(lokomotywa != nullptr) {
        Wagon *killer = new Wagon;
        Wagon *iterator = lokomotywa;
        while (iterator->next != nullptr) {
            killer = iterator;
            iterator = iterator->next;
            delete killer;
        }
    }
    cout << "Pociag deleted" << endl;
}

ostream& operator<<(ostream &os, Pociag &p1)
{
    if(p1.lokomotywa == nullptr)
    {
        os << "Pociag jest pusty!" << endl;
    }
    else
    {
        Wagon *iterator = p1.lokomotywa;
        while(iterator != nullptr)
        {
            os << "[" << iterator->ile << ", " << iterator->z->getNazwa() << "]<->";
            iterator = iterator->next;
        }
        os << endl;
    }
    return os;
}

void Pociag::wstaw(int i, Zwierze *z)
{
    Wagon *nowy = new Wagon(i, z);
    if(lokomotywa == nullptr)
    {
        lokomotywa = nowy;
    }
    else
    {
        Wagon *iterator = lokomotywa;
        while(iterator->next != nullptr)
        {
            iterator = iterator->next;
        }
        iterator->next = nowy;
    }
    ile_wagonow++;
}

void Pociag::odczep(int a)
{
    if(lokomotywa == nullptr)
    {
        cout << "Nie ma nic do odczepiania!" << endl;
    }
    else
    {
        int licznik = 0;
        Wagon *iterator = lokomotywa;
        Wagon *prev = new Wagon;

        while(iterator->next != nullptr)
        {
            if(licznik == a)
            {
                break;
            }
            licznik++;
            prev = iterator;
            iterator = iterator->next;
        }

        if(iterator == lokomotywa)
        {
            lokomotywa = iterator->next;
            delete iterator;
        }
        else if(iterator->next == nullptr)
        {
            prev->next = nullptr;
            delete iterator;
        }
        else
        {
            prev->next = iterator->next;
            delete iterator;
        }
        ile_wagonow--;
    }

}



#endif
