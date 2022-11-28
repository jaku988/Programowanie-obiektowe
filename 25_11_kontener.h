#ifndef kontener_h
#define kontener_h
#include <iostream>
using namespace std;

class Element
{
    int x;
public:
    Element(int x=0): x(x) {};
    int getX() {return x;};
    void setX(int x) {this->x = x;};
};

class Container{
    Element* array;
    int numberOfElements;
public:
    Container(int numberOfElements = 0);
    Container(const Container& c);
    ~Container();
    Container& operator=(const Container& c);
    friend ostream& operator<<(ostream& os, const Container& s);
    friend istream& operator>>(istream& is, Container& s);
    //Container& operator--();
    //Container operator--(int);
   // Element& operator[](int i);
    //Container& operator+=(int x);
    //bool operator==(const Container& s);
    //Container operator+(const Container& s);
    //void reverse();operator int() const;

};

Container::Container(int numberOfElements){
    this->numberOfElements = numberOfElements;
    
    if(numberOfElements > 0){
        array = new Element[numberOfElements];
    }
    else{
        array = nullptr;
    }
}

Container::Container(const Container& c){
    this->numberOfElements = c.numberOfElements;
    
    if(numberOfElements > 0){
        array = new Element[numberOfElements];
        
        for(int i=0; i<numberOfElements; i++){
            array[i].setX(c.array[i].getX());
        }
    }
    else{
        array = nullptr;
    }
}

Container::~Container(){
    delete [] array;
}

Container& Container::operator=(const Container& c){
    this->numberOfElements = c.numberOfElements;
    
    delete [] c.array;
    
    for(int i=0; i<numberOfElements; i++){
        array[i].setX(c.array[i].getX());
    }
    return *this;
}

ostream& operator<<(ostream& os, const Container& c){
    for(int i=0; i<c.numberOfElements; i++){
        cout << "[" << c.array[i].getX() << "]" << " ";
    }
    return os;
}

istream& operator>>(istream& is, Container& c){
    for(int i=0; i<c.numberOfElements; i++){
        c.array[i].setX(i);
    }
    return is;
}

#endif /* kontener_h */
