#include "bangunan.c"
#include <stdio.h>

int main ()
{
    ACUAN A;
    char a;
    a='C';
    Inisialisasi(&A);
    printf("%d\n",CariDariAcuan(A,a,4,'A'));
    printf("%d",A.C[4].A);
}