
#include "array.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyBangunanTot (BangunanTot * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    (*T).TI[IdxMax-IdxMin+1];
    for (int i=IdxMin;i<=IdxMax;i++) {
        MakeBANGUNANEmpty(&((*T).TI[i]));
        (*T).P=0;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
