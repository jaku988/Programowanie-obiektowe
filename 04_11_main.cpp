#include <iostream>
#include "ulamek.h"

using namespace std;

int main()
{
    Ulamek x(1, 2);
    Ulamek y(3, 4);
    
    cout << x << endl << y << endl;
    cout << x << " + " << y << " = " << x + y << endl;
    cout << x << " - " << y << " = " << x - y << endl;
    cout << "~" << y << " = " << ~y << endl;
    cout << x << " / " << y << " = " << x / y << endl;
    cout << x << " + " << 6 << " = " << x + 6 << endl;
    cout << x << " + " << 6 << " = " << 6 + x << endl;
    
    for (int i=0; i<4; i++)
    {
        cout << x << endl;
        x++;
    }
    
    return 0;
}
