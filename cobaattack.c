#include "attack.c"
#include "bangunan.c"
#include "listlinier.c"
#include "array.c"
#include "point.c"
#include <Stdio.h>
#include "mesinkata.h"
#include "state.h"


int main()
{
    BangunanTot T;
    STATE S;
    Pemain Pe;
    MakeEmptyBangunanTot(&T);
    // CopyBANGUNAN(MakeBANGUNAN(0,0,0,'C',MakePOINT(3,4)),&T.TI[1].B);
    // // CopyBANGUNAN(MakeBANGUNAN(0,0,0,'T',MakePOINT(4,4)),&T.TI[2].B);
    // MakeBangunanPemain(&Pe,&T,2,1,40);
    // CetakDaftarBangunan(T,Pe,1);
    T = S.listbtot;
    LoadFile(&S,&T);
    PrintState(S);
    CetakDaftarBangunan(T,Pe,1);

    
    return 0;
}