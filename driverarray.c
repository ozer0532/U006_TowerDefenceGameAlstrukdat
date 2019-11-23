#include <stdio.h>
#include "array.h"
#include "bangunan.h"

int main () {
    BangunanTot B,C;

    //Inisialisasi awal
    MakeEmptyBangunanTot(&B);

    printf("%d\n",NbElmt(B));
    //Cetak ke layar
    printf("Jumlah pasukan : %d\n",B.TI[3].B.Jpas);
    printf("Jenis : %c\n",B.TI[3].B.Jenis); //Jenis awal adalah X saat diinisialisasi awal
    printf("Level: %d\n",B.TI[3].B.Level);
    printf("Milik : %d\n",B.TI[3].B.Milik);

    //Proses
    Del1Urut(&B,Nil,3,40,2);

    //Cetak ke layar
    printf("Jumlah pasukan : %d\n",B.TI[3].B.Jpas);
    printf("Jenis : %c\n",B.TI[3].B.Jenis);
    printf("Level: %d\n",B.TI[3].B.Level);
    printf("Milik : %d\n",B.TI[3].B.Milik);

    Dealokasi(&B);

    return 0;
}