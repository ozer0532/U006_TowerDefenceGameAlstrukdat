#include "bangunan.h"
#include "point.h"

int main () {

    //Inisialisasi Acuan
    ACUAN Ac;
    BANGUNAN B,C;
    Inisialisasi(&Ac);

    //Cari dari acuan
    printf("A : %d\n",CariDariAcuan(Ac,'C',1,'A'));
    printf("M : %d\n",CariDariAcuan(Ac,'C',1,'M'));
    printf("P : %d\n",CariDariAcuan(Ac,'C',1,'P'));
    printf("U : %d\n",CariDariAcuan(Ac,'C',1,'U'));

    //Inisialisasi dari BANGUNAN
    MakeBANGUNANEmpty(&B);

    //CopyBangunan
    CopyBANGUNAN( MakeBANGUNAN(1,100,1,'C',MakePOINT(1,1)),&B);
   

    //Cari dari BANGUNAN
    printf("A : %d\n",getA(B,Ac));
    printf("M : %d\n",getM(B,Ac));
    printf("P : %d\n",getP(B,Ac));
    printf("U : %d\n",getU(B,Ac));


    return 0;
}