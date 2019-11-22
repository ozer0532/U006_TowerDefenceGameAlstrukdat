
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmptyBangunanTot (BangunanTot * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    int i;
    (*T).TI = (ElType*) malloc ((IdxMax+1)*sizeof(ElType));
    //mulai dari 1
    for (i=IdxMin;i<=IdxMax;i++)
    {
        MakeBANGUNANEmpty(&((*T).TI[i].B));
        (*T).TI[i].P=0;
    }
}

void Dealokasi(BangunanTot *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    free((*T).TI);
}


/* *** Daya tampung container *** */
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

int MaxNbEl (BangunanTot T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return (IdxMax-IdxMin+1);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(BangunanTot T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
    return(IdxMin);
}

IdxType GetLastIdx(BangunanTot T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
    return (IdxMin+NbElmt(T)-1);
}
/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(BangunanTot T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return ((i<=IdxMax)&&(i>=IdxMin));
}
boolean IsIdxEff(BangunanTot T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return (i>=IdxMin && i<=GetLastIdx(T));
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

IdxType SearchBangunanTotByAddress (BangunanTot T, address PP)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
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


void CopyBangunanTot (BangunanTot Tin, BangunanTot * Tout, IdxType in, IdxType out)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
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

/* ********** SORTING ********** */
void InsSortAsc (BangunanTot * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
//Misalnya tabelnya maxnya 5 dan isinya POINT (8,2) (2,8) (4,5)  maka tabel arraynya akan menjadi (2,7)(2,8)(4,5) * * (Pendefinisian tabel harus SELALU terurut menaik berdasar lokasi)
//Array Terurut berdasarkan Lokasinya 
//Contoh : Lokasinya (8,2) (2,8) (4,5) * * (2,7) 
//Maka akan terurut dari baris kemudian kolom (2,7)(2,8)(4,5)(8,2) * *
// Metode searching dilakukan hingga menemukan ElUndef
// Saat menghapus satu elemen maka elemen lainnya akan menggeser. Misal (2,7) dihapus maka jadi (2,8)(4,5)(8,2) * * *
// Mirip PrioQueue
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
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */

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



void Del1Urut (BangunanTot *T, address Pe, IdxType Idx, int JPasNetto, int PEMAINKE)
//I.S BangunanTot belom terapus elemennya
//F.S Saat dihapus dari array artinya
//Elemen Array berubah MILIK
//address menjadi 0
//AKan terupdate JPas Awal sebanyak JUMLAH AKHIR nETTO. SUdah Hasil bersih dan bukan harus dikurang dari jumlah acuan

{
    IdxType i=Idx;
    (*T).TI[i].P=Pe;
    (*T).TI[i].B.Milik=PEMAINKE;
    (*T).TI[i].B.Jpas=JPasNetto;
}

