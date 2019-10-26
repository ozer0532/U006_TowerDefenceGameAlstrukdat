//ADT ATTACK

#include <stdio.h>
#include "boolean.h"
#include "attack.h"

address AlokasiLTambahBangunan (BangunanTot *B, IdxType Index)
//Saat ingin Alokasi / Buat List Liniear
//F.S address di BangunanTOt sudah terisi oleh address dari Alokasi Index di List Linier
{
    address Pe;
    Pe=AlokasiL(Index);
    (*B).P = Pe;
    return (Pe);
}


void AddToLPemain (Pemain *Pe, BangunanTot *B,  IdxType Idx, int PEMAINKE, int JPasNetto)
//Membuat Bangunan menjadi berubah kepemilikan
//Proses: Misal Bangunan milik P1 baru dikuasai maka LIST L1 berkurang 1  LIST L2 bertambah, Bangunan TOtal tetap
{
    address P;
    List La= (*Pe).L1;
    List Lb= (*Pe).L2;
    if (PEMAINKE==1){

        if ((*B).TI[Idx].B.Milik=0)
        {
            P=AlokasiLTambahBangunan((*B),Idx),;
            ResetBangunan(Info(P),JPasNetto,PEMAINKE);
            InsertLastL(&La,P);
            Del1Urut(B,P,JPasNetto,PEMAINKE);

        }
        else
        {
            P=SearchL(Lb,Idx);
            ResetBANGUNAN(B,JPasNetto,PEMAINKE);
            InsertLastL(&La,P);
            Del1Urut(B,P,JPasNetto,PEMAINKE);
            DelPL(&Lb,Idx);
        }
    }

    if (PEMAINKE==2){
        if ((*B).TI[Idx].B.Milik=0)
        {
            P=AlokasiLTambahBangunan((*B),Idx),;
            ResetBangunan(Info(P),JPasNetto,PEMAINKE);
            InsertLastL(&Lb,P);
            Del1Urut(B,P,Idx,JPasNetto,PEMAINKE);

        }
        else
        {
            P=SearchL(La,Idx);
            ResetBANGUNAN(B,JPasNetto,PEMAINKE);
            InsertLastL(&Lb,P);
            Del1Urut(B,P,Idx,JPasNetto,PEMAINKE);
            DelPL(&La,Idx);
        }
    }
}

void MakeBangunanPemain (Pemain *Pe, BangunanTot *B,  IdxType Idx, int PEMAINKE, int Jmlh)
{
    address P;
    int JHDiserang;
    ACUAN Ac;
    Inisialisasi(&Ac);
    List La= (*Pe).L1;
    List Lb= (*Pe).L2;
    if (PEMAINKE==1) 
    {
        if ((*B).TI[Idx].B.Milik=0)
        {
            //Saat Belum dikuasai siapa2. Maka Minimal yang harus diserang adalah Sebanyak U
            JHDiserang=CariDariAcuan(Ac,(*B).TI[Idx].B.Jenis,(*B).TI[Idx].B.Level,'U');
            //Jika Jumlahnya lebih dari diserang
            if (Jmlh>=JHDiserang)
            {
                //Jika belom menyentuh nilai max
                if (JumlahPasukanValid((*B).TI[Idx].B,Jmlh-JHDiserang))
                {
                    AddToLPemain(Pe,B,Idx,PEMAINKE,Jmlh-JHDiserang)
                }
                
                //Jika sudah menyentuh nilai max
                else
                {
                    AddToLPemain(Pe,B,Idx,PEMAINKE,CariDariAcuan(Ac,(*B).TI[Idx].B.Jenis,(*B).TI[Idx].B.Level,'M'))
                }
                
            }
            //Jika jumlahnyaa kurang dari
            else 
            {

            }
        }
        else
        {

        }
    }
}






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


