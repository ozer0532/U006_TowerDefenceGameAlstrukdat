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


void AddToLPemain (Pemain *Pe, BangunanTot *T,  IdxType Idx, int PEMAINKE, int JPasNetto)
//Membuat Bangunan menjadi berubah kepemilikan
//Proses: Misal Bangunan milik P1 baru dikuasai maka LIST L1 berkurang 1  LIST L2 bertambah, Bangunan TOtal tetap
{
    address PP;
    if (PEMAINKE==1){

        if ((*T).TI[Idx].B.Milik==0)
        {
            PP=AlokasiL(Idx);
            (*T).TI[Idx].P = PP;
            ResetBANGUNAN(&((*T).TI[Idx].B),JPasNetto,PEMAINKE);
            //InsertLastL(&La,PP);
            InsVLastL(&(*Pe).L1,Idx);

        }
        else
        {
            PP=SearchL((*Pe).L2,Idx);
            ResetBANGUNAN(&(*T).TI[Idx].B,JPasNetto,PEMAINKE);
            InsVLastL(&(*Pe).L1,Idx);
            Del1Urut(T,PP,Idx,JPasNetto,2);
            DelPL(&(*Pe).L2,Idx);
        }
    }

    if (PEMAINKE==2){
        if ((*T).TI[Idx].B.Milik==0)
        {
            PP=AlokasiL(Idx);
            (*T).TI[Idx].P = PP;
            ResetBANGUNAN(&(*T).TI[Idx].B,JPasNetto,PEMAINKE);
             InsVLastL(&(*Pe).L2,Idx);

        }
        else
        {
            
            PP=SearchL((*Pe).L1,Idx);
            ResetBANGUNAN(&(*T).TI[Idx].B,JPasNetto,PEMAINKE);
            InsVLastL(&(*Pe).L2,Idx);
            Del1Urut(T,PP,Idx,JPasNetto,1);
            DelPL(&(*Pe).L1,Idx);
        }
    }
}

void MakeBangunanPemain (Pemain *Pe, BangunanTot *T,  IdxType Idx, int PEMAINKE, int Jmlh)
//INPUTAN Jmlh Awal harus Valid
//Artinya Jmlh harus lebih dari 0 namun harus kurang dari sama dengan JPas Daftar Bangunan
{
    address P;
    int JHDiserang;
    ACUAN Ac;
    Inisialisasi(&Ac);
    List La= (*Pe).L1;
    List Lb= (*Pe).L2;
    
    printf("%c\n",(*T).TI[Idx].B.Jenis);
    printf("%d\n", (int)floor(3*Jmlh/4));
    printf("%d\n",(*T).TI[Idx].B.Level);
    printf("%d\n",CariDariAcuan(Ac,(*T).TI[Idx].B.Jenis,(*T).TI[Idx].B.Level,'U'));
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
                    AddToLPemain(Pe,T,Idx,PEMAINKE,(int)floor(3*Jmlh/4)-JHDiserang);
                }
                
                //Jika sudah menyentuh nilai max
                else
                {
                    AddToLPemain(Pe,T,Idx,PEMAINKE,CariDariAcuan(Ac,(*T).TI[Idx].B.Jenis,(*T).TI[Idx].B.Level,'M'));
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
                    AddToLPemain(Pe,T,Idx,PEMAINKE,(int)floor(3*Jmlh/4)-JHDiserang);
                }
                
                //Jika sudah menyentuh nilai max
                else
                {
                    AddToLPemain(Pe,T,Idx,PEMAINKE,CariDariAcuan(Ac,(*T).TI[Idx].B.Jenis,(*T).TI[Idx].B.Level,'M'));
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
                    AddToLPemain(Pe,T,Idx,PEMAINKE,Jmlh-JHDiserang);
                }
                
                //Jika sudah menyentuh nilai max
                else
                {
                    AddToLPemain(Pe,T,Idx,PEMAINKE,CariDariAcuan(Ac,(*T).TI[Idx].B.Jenis,(*T).TI[Idx].B.Level,'M'));
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
                    AddToLPemain(Pe,T,Idx,PEMAINKE,Jmlh-JHDiserang);
                }
                
                //Jika sudah menyentuh nilai max
                else
                {
                    AddToLPemain(Pe,T,Idx,PEMAINKE,CariDariAcuan(Ac,(*T).TI[Idx].B.Jenis,(*T).TI[Idx].B.Level,'M'));
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


void CetakDaftarBangunan (BangunanTot T, Pemain Pe, int PEMAINKE)
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

void Attack(Graph G, BangunanTot *T, Pemain *Pe, int PEMAINKE, int no)
{
    int N,M,Pas;
    address P;
    int A[30];

    CetakDaftarBangunan((*T),*Pe,PEMAINKE);
    printf("Bangunan yang digunakan untuk menyerang: ");
    scanf("%d",&N);
    if (PEMAINKE==1) {
         P=First((*Pe).L1);
    }
    else{
        P=First((*Pe).L2);
    }
    
    //Mencari no adalah Listnya index ke berapa
    for(int i=1;i<no;i++) {
        P=Next(P);
    }

    //Masukin nilai Index hubung ke array
    printf("Bangunan yang dapat diserang:\n");
    for (int j=1;j<=30;j++) {
        A[j]=(Neighbors(G,Info(P)))[j];
        if A[j]!=0 {
            printf("%d. ",j);
                
            //Cetak nama bangunannya
            if (T.TI[A[j]].B.Jenis =='C') {printf("Castle ");}
            else if ((T.TI[A[j]].B.Jenis )=='T') {printf("Tower ");}
            else if ((T.TI[A[j]].B.Jenis )=='V') {printf("Village ");}
            else if ((T.TI[A[j]].B.Jenis )=='F') {printf("Fort ");}

            //Cetak lokasinya
            printf("(%d,%d) ",T.TI[A[j]].B.Lok.X,T.TI[Info(P)].B.Lok.Y);

            //Cetak jumlah pasukannya
            printf ("%d ",T.TI[A[j]].B.Jpas);

            //cetak level
            printf("lv. %d\n", T.TI[A[j]].B.Level);

        }
        
        printf("Bangunan yang diserang: ");
        scanf("%d",&M);
        
        printf("Jumlah pasukan: ");
        scanf("%d",&Pas);

        //Check apakah jumlah pasukan valid atau tidak
        while ((*T).TI[Info(P)].B.Jpas < Pas || Pas<0 && ){
            printf("Masukkan jumlah pasukan salah ~~\n");
            printf("Jumlah pasukan: ");
            scanf("%d",&Pas);
        }
        MakeBangunanPemain(Pe,T,Info(P),PEMAINKE,Pas);
    }
}


