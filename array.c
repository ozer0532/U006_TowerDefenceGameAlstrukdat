
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
        MakeBANGUNANEmpty(&((*T).TI[i].B));
        (*T).TI[i].P=0;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */

int NbElmt (BangunanTot T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    int k=0;
    int i=IdxMin;
    while (T.TI[i].B.Lok.X!=0 || T.TI[i].B.Lok.Y!=0 ) {
            k=k+1;
            i++;
    }
    return k;
}


boolean IsEmpty (BangunanTot T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    for (int i=IdxMin;i<=IdxMax;i++) {
        if(T.TI[i].B.Lok.X!=0 || T.TI[i].B.Lok.Y!=0 ) {
            return false;
        }
    }
    return true;
}


void CopyBangunanTot (BangunanTot Tin, BangunanTot * Tout, IdxType in, IdxType out)
{
    CopyBANGUNAN(Tin.TI[in].B,&((*Tout).TI[out].B));
    (*Tout).TI[out].P=(Tin).TI[in].P;

}

void AddAsLastEl (BangunanTot *T, BANGUNAN Ba)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    CopyBANGUNAN(Ba,&(*T).TI[NbElmt(*T)+1].B);
}

void InsSortAsc (BangunanTot * T)
{
    int i,j,index;
    BangunanTot min;
    MakeEmptyBangunanTot(&min);
    for (i=IdxMin;i<=NbElmt(*T);i++)
    {
        CopyBangunanTot((*T),&min,i,1);
        
        index = i;
        for (j=i+1;j<=NbElmt(*T);j++)
        {
            if ((*T).TI[j].B.Lok.X <= min.TI[1].B.Lok.X)
            {
                if ((*T).TI[j].B.Lok.Y < min.TI[1].B.Lok.Y)
                {
                    index = j;
                    CopyBangunanTot((*T),&min,j,i) ;
                }
            }
        }
        CopyBangunanTot((*T),&(*T),i,index);
        CopyBangunanTot(min,&(*T),1,i);
    }
}

void Add1Urut (BangunanTot *T, BANGUNAN Ba)
{
    if (IsEmpty(*T))
    {
        CopyBANGUNAN(Ba,&(*T).TI[IdxMin].B);
    }
    else 
    {
        AddAsLastEl(&(*T),Ba);
        InsSortAsc(T);
    }
}


IdxType SearchBangunanTotByAddress (BangunanTot T, address PP)
{
    
    int i;
    i=IdxMin;
    if (IsEmpty(T))
    {
        return IdxUndef;
    }
    else
    {
        while(i<=NbElmt(T))
        {
            if(T.TI[i].P==PP)
            {
                return i;
            }
            else
            {
                i=i+1;
            }
        }
        return IdxUndef;
    }
}


void Del1Urut (BangunanTot *T, address Pe, IdxType Idx, int JPasNetto, int PEMAINKE)
{
    IdxType i=Idx;
    (*T).TI[i].P=Pe;
    (*T).TI[i].B.Milik=PEMAINKE;
    (*T).TI[i].B.Jpas=JPasNetto;
}

