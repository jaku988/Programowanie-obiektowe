#ifndef ciag_h
#define ciag_h
#include <iostream>
using namespace std;

class Ciag
{
    int n;
    int max;
    int min;
    int* tab;
public:
    Ciag(int n=0, int min=0, int max=0);
    ~Ciag();
    friend ostream& operator<<(ostream &s, const Ciag &c);
    Ciag(const Ciag &c);
    Ciag operator=(const Ciag &c);
    Ciag& operator++();
    Ciag operator++(int);
    int& operator[](int i);
};



Ciag::Ciag(int n, int min, int max){
    
    this->n = n;
    this->min = min;
    this->max = max;
    
    if(n!=0){
        tab = new int[n];
        for(int i=0; i<n; i++){
            tab[i] = rand()%(max-min+1)+min;
        }
    }
    else if(n==0){
        tab = nullptr;
    }
}

Ciag::~Ciag(){
    cout << "Ciag usuniety" << endl;
    
    delete[] tab;
}

ostream& operator<<(ostream &os, const Ciag &c){
    for(int i=0; i<c.n; i++){
        cout << c.tab[i] << " ";
    }
    return os;
}

Ciag::Ciag(const Ciag &c){
    
    this->n = c.n;
    this->min = c.min;
    this->max = c.max;
    
    if(n!=0){
        tab = new int[n];
        for(int i=0; i<n; i++){
            tab[i] = c.tab[i];
        }
    }
    else if(n==0){
        tab = nullptr;
    }
}

Ciag Ciag::operator=(const Ciag &c){
    if(this == &c) return *this;
    
    delete [] tab;
    
    this->n = c.n;
    this->min = c.min;
    this->max = c.max;
    
    if(n!=0){
        tab = new int[n];
        for(int i=0; i<n; i++){
            tab[i] = c.tab[i];
        }
    }
    else if(n==0){
        tab = nullptr;
    }
    return *this;
    
}

Ciag& Ciag::operator++()
{
    int *tab2=new int[n+1];
    for(int i=0; i<n; i++)
    {
        tab2[i]=tab[i];
    }
    tab2[n]=rand()%(max-min+1)+min;
    delete [] tab;
    tab=tab2;
    n++;
    return *this;
}

Ciag Ciag::operator++(int){
    Ciag kopia = *this;
    ++(*this);
    return kopia;
}

int& Ciag::operator[](int i){
    return tab[i];
}



#endif /* ciag_h */
