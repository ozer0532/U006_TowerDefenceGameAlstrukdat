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
            P=AlokasiLTambahBangunan((B),Idx);
            ResetBANGUNAN(&(*B).TI[Idx].B,JPasNetto,PEMAINKE);
            InsertLastL(&La,P);
            Del1Urut(B,P,Idx,JPasNetto,PEMAINKE);

        }
        else
        {
            P=SearchL(Lb,Idx);
            ResetBANGUNAN(&(*B).TI[Idx].B,JPasNetto,PEMAINKE);
            InsertLastL(&La,P);
            Del1Urut(B,P,Idx,JPasNetto,PEMAINKE);
            DelPL(&Lb,Idx);
        }
    }

    if (PEMAINKE==2){
        if ((*B).TI[Idx].B.Milik=0)
        {
            P=AlokasiLTambahBangunan((B),Idx);
            ResetBANGUNAN(&(*B).TI[Idx].B,JPasNetto,PEMAINKE);
            InsertLastL(&Lb,P);
            Del1Urut(B,P,Idx,JPasNetto,PEMAINKE);

        }
        else
        {
            P=SearchL(La,Idx);
            ResetBANGUNAN(&(*B).TI[Idx].B,JPasNetto,PEMAINKE);
            InsertLastL(&Lb,P);
            Del1Urut(B,P,Idx,JPasNetto,PEMAINKE);
            DelPL(&La,Idx);
        }
    }
}

void MakeBangunanPemain (Pemain *Pe, BangunanTot *B,  IdxType Idx, int PEMAINKE, int Jmlh)
//INPUTAN Jmlh Awal harus Valid
//Artinya Jmlh harus lebih dari 0 namun harus kurang dari sama dengan JPas Daftar Bangunan
{
    address P;
    int JHDiserang;
    ACUAN Ac;
    Inisialisasi(&Ac);
    List La= (*Pe).L1;
    List Lb= (*Pe).L2;

    //Saat Belum dikuasai siapa2. Maka Minimal yang harus diserang adalah Sebanyak U
    JHDiserang=CariDariAcuan(Ac,(*B).TI[Idx].B.Jenis,(*B).TI[Idx].B.Level,'U');
    //Jika Jumlahnya lebih dari diserang
    if (IsAdaPertahanan((*B).TI[Idx].B))
    {
         
            if ( (int)floor(3/4)*Jmlh>=JHDiserang)
            {
                //Jika belom menyentuh nilai max
                if (JumlahPasukanValid((*B).TI[Idx].B, (int)floor(3/4*Jmlh)-JHDiserang))
                {
                    AddToLPemain(Pe,B,Idx,PEMAINKE,3/4*Jmlh-JHDiserang);
                }
                
                //Jika sudah menyentuh nilai max
                else
                {
                    AddToLPemain(Pe,B,Idx,PEMAINKE,CariDariAcuan(Ac,(*B).TI[Idx].B.Jenis,(*B).TI[Idx].B.Level,'M'));
                }
            }
            //Jika jumlahnyaa kurang dari diserang
            else 
            {
                printf("Bangunan gagal direbut.\n");
                if ((*B).TI[Idx].B.Milik!=0)
                {  
                    (*B).TI[Idx].B.Jpas=JHDiserang- (int)floor(3/4*Jmlh);
                }
            }
    }
    else
    {
        if (Jmlh>=JHDiserang)
        {
            //Jika belom menyentuh nilai max
            if (JumlahPasukanValid((*B).TI[Idx].B,Jmlh-JHDiserang))
            {
                AddToLPemain(Pe,B,Idx,PEMAINKE,Jmlh-JHDiserang);
            }
            
            //Jika sudah menyentuh nilai max
            else
            {
                AddToLPemain(Pe,B,Idx,PEMAINKE,CariDariAcuan(Ac,(*B).TI[Idx].B.Jenis,(*B).TI[Idx].B.Level,'M'));
            }
        }
        //Jika jumlahnyaa kurang dari diserang
        else 
        {
            printf("Bangunan gagal direbut.\n");
            if ((*B).TI[Idx].B.Milik!=0)
            {  
                (*B).TI[Idx].B.Jpas=JHDiserang-Jmlh;
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
        while(Next(P)!=Nil) {
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


