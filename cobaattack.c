#include "attack.c"
#include "bangunan.c"
#include "listlinier.c"
#include "array.c"
#include "point.c"
#include <Stdio.h>
#include "mesinkata.h"
#include "STATE.h"


int main()
{
    BangunanTot T;
    STATE S;
    Player Pe;
    Player Pm;
    CreateEmptyL(&(Pe.bangunanPlayer));
    CreateEmptyL(&(Pe.bangunanPlayer));
    MakeEmptyBangunanTot(&T);
    // CopyBANGUNAN(MakeBANGUNAN(0,0,0,'C',MakePOINT(3,4)),&T.TI[1].B);
    // // CopyBANGUNAN(MakeBANGUNAN(0,0,0,'T',MakePOINT(4,4)),&T.TI[2].B);
    // MakeBangunanPemain(&Pe,&T,2,1,40);
    // CetakDaftarBangunan(T,Pe,1);
    T = S.listbtot;
    LoadFile(&S,&T);
    PrintState(S);
    CetakDaftarBangunan(T,Pe);

    
        PrintInfoL(Pe);
    
    /*CopyBANGUNAN(MakeBANGUNAN(0,0,1,'C',MakePOINT(3,4)),&T.TI[1].B);
    CopyBANGUNAN(MakeBANGUNAN(0,0,1,'T',MakePOINT(4,4)),&T.TI[2].B);
    
    MakeBangunanPemain(&Pe,&T,2,1,80);
    address P= First(Pe.L1);
    PrintInfoL(Pe.L1);
    MakeBangunanPemain(&Pe,&T,2,2,30);
    MakeBangunanPemain(&Pe,&T,2,2,120);
    PrintInfoL(Pe.L1);
    PrintInfoL(Pe.L2);
    CetakDaftarBangunan(T,Pe,2);
    */
    return 0;
}