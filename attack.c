//ADT ATTACK

#include <stdio.h>
#include "boolean.h"
#include "attack.h"

void PrintDaftarBangunan1 (Pemain Pe)
//Mencetak daftar bangunan dari pemain 1
//I.S L adalah List1 YANG SUDAH TERDEFINISI dimana Info(L).Milik='A'
{
    int N;
    address P;
    int no=1;
    P=First(Pe.L1);
    printf("Daftar bangunan:\n");

    if (IsEmptyList(Pe.L1)) {
        printf("Kamu belom punya bangunan\n");
    }
    else {
        while(Next(P)!=Nil) {
            printf("%d. ",no);
            
            //Cetak nama bangunannya
            if ((Info(P).Jenis)=='C') {printf("Castle ");}
            else if ((Info(P).Jenis)=='T') {printf("Tower ");}
            else if ((Info(P).Jenis)=='V') {printf("Village ");}
            else if ((Info(P).Jenis)=='F') {printf("Fort ");}

            //Cetak lokasinya
            printf("(%d,%d) ", Info(P).Lok.X,Info(P).Lok.Y);

            //Cetak jumlah pasukannya
            printf ("%d ",Info(P).Jpas);

            //cetak level
            printf("lv. %d\n", Info(P).Level);

            no++;
            P=Next(P);
        }

        printf("Bangunan yang digunakan untuk menyerang: ");
        scanf("%d",&N);
        printf("Daftar bangunan yang dapat diserang:\n");



    }


}

void PrintPOINT (BANGUNAN B)
//Memprint Letak Bangunan B
//I.S B terdefinisi
//F.S tercetak ke layar (X,Y) tanpa enter spasi
{
	printf("(%d,%d)",B.Lok.X,B.Lok.Y);
}