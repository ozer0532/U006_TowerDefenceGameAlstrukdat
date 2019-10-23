//ADT ATTACK

#include <stdio.h>
#include "boolean.h"
#include "attack.h"

address SearchPOINT (List L, POINT Po)
{
    address P;
    boolean Found=false;
    P=First(L);
    while (Next(P)!= Nil && (!Found)) {
        if (Info(P).Lok.X==Po.X  && Info(P).Lok.Y==Po.Y) {
            Found = true;
        }
        else {
            P=Next(P);
        }
    }
    if (IsEmptyL(L)) {
        return Nil;
    }
    else {
        return P;
    }
}
void CetakDaftarBangunan (Pemain Pe, int PEMAINKE)
//Mencetak daftar bangunan dari pemain 1
//I.S L adalah List1 YANG SUDAH TERDEFINISI dimana Info(L).Milik=1 
{
    int N;
    address P;
    int no=1;
    boolean Empty=true;
    
    printf("Daftar bangunan:\n");

    if (PEMAINKE==1 ){ 
        P=First(Pe.L1);
        if (IsEmptyL(Pe.L1)) {
            printf("Kamu belom punya bangunan\n");
        }
        else {
            Empty= false;
        }
    }
    else {
        P=First(Pe.L2);
        if (IsEmptyL(Pe.L2)) {
            printf("Kamu belom punya bangunan\n");
        }
        else {
            Empty= false;
        }
    }


    if(Empty==false) {
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
    }
}


void UpdateBangunan (Pemain *Pe, BangunanTot *B,  POINT Po, int PEMAINKE, int Jmlh)
//Membuat Bangunan menjadi berubah kepemilikan
//Proses: Misal Bangunan milik P1 baru dikuasai maka LIST L1 berkurang 1  LIST L2 bertambah, Bangunan TOtal tetap
{
    address P;
    if (PEMAINKE==1){
        List La= (*Pe).L1;
        List Lb= (*Pe).L2;

        if (IsBangunanNon(*B,Po))
        {
            P=AlokasiL((*B).TI[SearchLokasiBangunan(*B,Po)]);
            ResetBangunan(Info(P),Jmlh,PEMAINKE);
            InsertLastL(&La,P);
            Del1Urut(B,Po);

        }
        else
        {
            P=SearchPOINT((*Pe).L2,Po);
            ResetBangunan(Info(P),Jmlh,PEMAINKE);
            InsertLastL(&La,P);
            DelPL(&Lb,Info(P));
        }
    }
    
}