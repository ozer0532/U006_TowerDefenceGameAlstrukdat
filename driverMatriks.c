#include <stdio.h>
#include "matriks.h"

int main () {
    MATRIKS M;
    MATRIKS Mcop;
    MakeMATRIKS(10,12,&M);
    for (int i=1; i<=10;i++) {
        for (int j=1; j<=12;j++) {
            M.Mem[i][j].p=20;
        }
    }
    printf("%d\n",GetFirstIdxBrsM(M));
    printf("%d\n",GetFirstIdxKolM(M));
    printf("%d\n",GetLastIdxBrsM(M));
    printf("%d\n",GetLastIdxKolM(M));
    CopyMATRIKS(M,&Mcop);
    printf("%d\n",Mcop.Mem[2][2].p);
    


    return 0;
}