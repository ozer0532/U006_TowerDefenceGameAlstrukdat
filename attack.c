//ADT ATTACK

#include <stdio.h>
#include "boolean.h"
#include "attack.h"
#include <math.h>

address AlokasiLTambahBangunan (BangunanTot *B, IdxType Index)
//Saat ingin Alokasi / Buat List Liniear
//F.S address di BangunanTOt sudah terisi oleh address dari Alokasi Index di List Linier
{
    address Pe;
    Pe=AlokasiL(Index);
    (*B).TI[Index].P = Pe;
    return (Pe);
}


void AddToLPemain (Player *Pe, Player *Pm, BangunanTot *T,  IdxType Idx, int JPasNetto)
//Membuat Bangunan menjadi berubah kepemilikan
//Proses: Misal Bangunan milik P1 baru dikuasai maka LIST L1 berkurang 1  LIST L2 bertambah, Bangunan TOtal tetap
{
    address PP;
    if ((*T).TI[Idx].B.Milik==0)
    {
        PP=AlokasiL(Idx);
        (*T).TI[Idx].P = PP;
        ResetBANGUNAN(&((*T).TI[Idx].B),JPasNetto,(*Pe).playerKe);
        //InsertLastL(&La,PP);
        InsVLastL(&(*Pe).bangunanPlayer,Idx);

    }
    else
    {
        PP=SearchL((*Pm).bangunanPlayer,Idx);
        ResetBANGUNAN(&(*T).TI[Idx].B,JPasNetto,(*Pe).playerKe);
        InsVLastL(&(*Pe).bangunanPlayer,Idx);
        Del1Urut(T,PP,Idx,JPasNetto,2);
        DelPL(&(*Pm).bangunanPlayer,Idx);
    }
}

void MakeBangunanPemain (Player *Pe, Player *Pm, BangunanTot *T,  IdxType Idx, int Jmlh)
//INPUTAN Jmlh Awal harus Valid
//Artinya Jmlh harus lebih dari 0 namun harus kurang dari sama dengan JPas Daftar Bangunan
{
    address P;
    int JHDiserang;
    ACUAN Ac;
    Inisialisasi(&Ac);
    List La= (*Pe).bangunanPlayer;
    List Lb= (*Pm).bangunanPlayer;
    
    //Saat Belum dikuasai siapa2. Maka Minimal yang harus diserang adalah Sebanyak U
    //Jika Jumlahnya lebih dari diserang
    if (IsAdaPertahanan((*T).TI[Idx].B))
    {
        
        if ((*T).TI[Idx].B.Milik==0) //Kalau Bangunannya belom dikuasai siapa2
        {
            JHDiserang=CariDariAcuan(Ac,(*T).TI[Idx].B.Jenis,(*T).TI[Idx].B.Level,'U');
            if ( (int)floor((3*Jmlh/4))>=JHDiserang)
            {
                
                //Jika belom menyentuh nilai max
                if (JumlahPasukanValid((*T).TI[Idx].B, (int)floor(3*Jmlh/4)-JHDiserang))
                {
                    AddToLPemain(Pe, Pm,T,Idx,(int)floor(3*Jmlh/4)-JHDiserang);
                }
                
                //Jika sudah menyentuh nilai max
                else
                {
                    AddToLPemain(Pe, Pm,T,Idx,CariDariAcuan(Ac,(*T).TI[Idx].B.Jenis,(*T).TI[Idx].B.Level,'M'));
                }
            }
            //Jika jumlahnyaa kurang dari diserang
            else 
            {
                printf("Bangunan gagal direbut.\n");
            }
         }
         //Saat bangunan sudah dikuasasi Pemain yang laain
         else
         {
             
            JHDiserang=(*T).TI[Idx].B.Jpas;
            if ( (int)floor(3/4)*Jmlh>=JHDiserang)
            {
                 //Jika belom menyentuh nilai max
                if (JumlahPasukanValid((*T).TI[Idx].B, (int)floor(3*Jmlh/4)-JHDiserang))
                {
                    AddToLPemain(Pe,Pm,T,Idx,(int)floor(3*Jmlh/4)-JHDiserang);
                }
                
                //Jika sudah menyentuh nilai max
                else
                {
                    AddToLPemain(Pe,Pm,T,Idx,CariDariAcuan(Ac,(*T).TI[Idx].B.Jenis,(*T).TI[Idx].B.Level,'M'));
                }
            }
            else
            {
                printf("Bangunan gagal direbut.\n");
                    (*T).TI[Idx].B.Jpas=JHDiserang- (int)floor(3*Jmlh/4);
                
            }
         }
         
    }
    else
    {
        if ((*T).TI[Idx].B.Milik==0) //Kalau Bangunannya belom dikuasai siapa2
        {
            JHDiserang=CariDariAcuan(Ac,(*T).TI[Idx].B.Jenis,(*T).TI[Idx].B.Level,'U');
            if ( Jmlh>=JHDiserang)
            {
                //Jika belom menyentuh nilai max
                if (JumlahPasukanValid((*T).TI[Idx].B,Jmlh-JHDiserang))
                {
                    AddToLPemain(Pe,Pm,T,Idx,Jmlh-JHDiserang);
                }
                
                //Jika sudah menyentuh nilai max
                else
                {
                    AddToLPemain(Pe,Pm,T,Idx,CariDariAcuan(Ac,(*T).TI[Idx].B.Jenis,(*T).TI[Idx].B.Level,'M'));
                }
            }
            //Jika jumlahnyaa kurang dari diserang
            else 
            {
                printf("Bangunan gagal direbut.\n");
            }
         }
         //Saat bangunan sudah dikuasasi Pemain yang laain
         else
         {
            JHDiserang=(*T).TI[Idx].B.Jpas;
            if ( Jmlh>=JHDiserang)
            {
                 //Jika belom menyentuh nilai max
                if (JumlahPasukanValid((*T).TI[Idx].B, Jmlh-JHDiserang))
                {
                    AddToLPemain(Pe,Pm,T,Idx,Jmlh-JHDiserang);
                }
                
                //Jika sudah menyentuh nilai max
                else
                {
                    AddToLPemain(Pe,Pm,T,Idx,CariDariAcuan(Ac,(*T).TI[Idx].B.Jenis,(*T).TI[Idx].B.Level,'M'));
                }
            }
            else
            {
                printf("Bangunan gagal direbut.\n");
                    (*T).TI[Idx].B.Jpas=JHDiserang- Jmlh;
                
            }
         }
    }    
}


void CetakDaftarBangunan (BangunanTot T, Player Pe)
//Mencetak daftar bangunan dari pemain 1
//I.S L adalah List1 YANG SUDAH TERDEFINISI dimana Info(L).Milik=1 
{
    int N;
    address P;
    int no=1;
    boolean Empty=true;
    
    printf("Daftar bangunan:\n");

    P=First(Pe.bangunanPlayer);
    if (IsEmptyL(Pe.bangunanPlayer)) {
        printf("Kamu belom punya bangunan\n");
    }
    else {
        Empty= false;
    }


    if(Empty==false) {
        while((P)!=Nil) {
            printf("%d. ",no);
            //Cetak nama bangunannya
            if (T.TI[Info(P)].B.Jenis =='C') {printf("Castle ");}
            else if ((T.TI[Info(P)].B.Jenis )=='T') {printf("Tower ");}
            else if ((T.TI[Info(P)].B.Jenis )=='V') {printf("Village ");}
            else if ((T.TI[Info(P)].B.Jenis )=='F') {printf("Fort ");}

            //Cetak lokasinya
            printf("(%d,%d) ",T.TI[Info(P)].B.Lok.X,T.TI[Info(P)].B.Lok.Y);

            //Cetak jumlah pasukannya
            printf ("%d ",T.TI[Info(P)].B.Jpas);

            //cetak level
            printf("lv. %d\n", T.TI[Info(P)].B.Level);

            no++;
            P=Next(P);
        }
    }
}

void Attack(Graph G, BangunanTot *T, Player *Pe, Player *Pm)
{
    int N,M,Pas;
    address P;
    ArrayVertex A;

    
    do {
        CetakDaftarBangunan((*T),*Pe);
        printf("Bangunan yang digunakan untuk menyerang: ");
        scanf("%d",&N);
        P=First((*Pe).bangunanPlayer);
        int i = 1;
        while (i < N && P != Nil) {
            P = Next(P);
            i++;
        }
        if (P == Nil) {
            printf("Bangunan tidak ada ~~\n");
        }
        printf("\n");
    } while (P == Nil);
    
    A = (Neighbors(G,Info(P)));
    if (A.Neff == 0) {
        printf("Tidak ada bangunan yang dapat diserang\n");
    } else {
        do {
            //Masukin nilai Index hubung ke array
            printf("Bangunan yang dapat diserang:\n");
            for (int j=1;j<=A.Neff;j++) {
                if (A.TI[j]!=0) {
                    printf("%d. ",j);
                        
                    //Cetak nama bangunannya
                    if ((*T).TI[A.TI[j]].B.Jenis =='C') {printf("Castle ");}
                    else if (((*T).TI[A.TI[j]].B.Jenis )=='T') {printf("Tower ");}
                    else if (((*T).TI[A.TI[j]].B.Jenis )=='V') {printf("Village ");}
                    else if (((*T).TI[A.TI[j]].B.Jenis )=='F') {printf("Fort ");}

                    //Cetak lokasinya
                    printf("(%d,%d) ",(*T).TI[A.TI[j]].B.Lok.X,(*T).TI[Info(P)].B.Lok.Y);

                    //Cetak jumlah pasukannya
                    printf ("%d ",(*T).TI[A.TI[j]].B.Jpas);

                    //cetak level
                    printf("lv. %d\n", (*T).TI[A.TI[j]].B.Level);

                }
            }
                
            printf("Bangunan yang diserang: ");
            scanf("%d",&M);

            if (M > A.Neff) {
                printf("Bangunan tidak ada ~~\n");
            }
            printf("\n");
        } while (M > A.Neff);
        
        printf("Jumlah pasukan: ");
        scanf("%d",&Pas);

        //Check apakah jumlah pasukan valid atau tidak
        while ((*T).TI[Info(P)].B.Jpas < Pas || Pas<0){
            printf("Masukan jumlah pasukan salah ~~\n");
            printf("Jumlah pasukan: ");
            scanf("%d",&Pas);
        }
        MakeBangunanPemain(Pe, Pm, T,Info(P),Pas);
    }
}


