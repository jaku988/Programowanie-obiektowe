#include "02.h"

int main()
{
    A a("obiekt klasy A",1);
    B b("obiekt klasy B",2, false);
    B c("kopia obiektu b", b);
    a.drukuj(); //drukuje wszystkie składoweobiektu
    c.drukuj();
    a.ustaw("A",3);
    b.ustaw("B", 4, false);
    cout << a << endl << b << endl;
    
    
    return 0;
}
