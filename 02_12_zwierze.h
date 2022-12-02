#ifndef zwierze_h
#define zwierze_h
#include <iostream>
using namespace std;

class Zwierze //klasa abstrakcyjna
{
public:
    virtual void dajGlos() const = 0; //pure virtual method - metoda czysto wirtualna
    virtual ~Zwierze() {cout << "~z\n";};
};

class Kot : public Zwierze
{
public:
    void dajGlos() const {cout << "Miau!\n";};
    ~Kot() {cout <<"~kot\n";};
};

class Waz : public Zwierze
{
public:
    void dajGlos() const {cout << "SSSS!\n";};
    ~Waz() {cout <<"~waz\n";};
};

class Krowa : public Zwierze
{
public:
    void dajGlos() const {cout << "Muuu!\n";};
    ~Krowa() {cout <<"~krowa\n";};
};

class Kon : public Zwierze
{
public:
    void dajGlos() const {cout << "Ihaa!\n";};
    ~Kon() {cout <<"~kon\n";};
};





#endif /* zwierze_h */
