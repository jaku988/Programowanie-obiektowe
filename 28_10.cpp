#include"plaszczak.h"
#include"planeta.h"

int main()
{

    Plaszczak Teodor('@', "Teodor");
    //Teodor.drukuj();
    Planeta Rect001(10, 10, '#');
    Rect001.zaplaszczakuj(&Teodor);
    Rect001.drukuj();
    Teodor.ruch(GORA);
    Rect001.drukuj();
    Teodor.ruch(GORA);
    Rect001.drukuj();
    Teodor.ruch(GORA);
    Rect001.drukuj();
    Teodor.ruch(GORA);
    Rect001.drukuj();
    
    return 0;
}
