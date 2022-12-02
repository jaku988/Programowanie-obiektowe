#include "zwierze.h"
#include <cstdlib>

int main()
{
    srand(time(NULL));
    int n, nr;
    cout << "n = ";
    cin >> n;
    cout << n << endl;
    
    Zwierze* *zoo = new Zwierze*[n];
    for(int i=0; i<n; i++){
        nr = rand() % 4;
        switch(nr)
        {
            case 0: zoo[i] = new Kot; break;
            case 1: zoo[i] = new Krowa; break;
            case 2: zoo[i] = new Waz; break;
            case 3: zoo[i] = new Kon; break;
        }
    }
    
    for(int i=0; i<n; i++){
        zoo[i]->dajGlos();
        delete zoo[i];
    }
    
    delete [] zoo;
    
    return 0;
}
