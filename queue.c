//Nama : Kevin Austin Stefano
//NIM  : 13518104

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmptyQ (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((Head(Q)==0)&&(Tail(Q)==0));
}
boolean IsFullQ (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmtQ(Q)==MaxEl(Q));
}
int NBElmtQ (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmptyQ(Q))
    {
        return 0;
    }
    else
    {
        if (Tail(Q)<Head(Q))
        {
            return (Tail(Q)+MaxEl(Q)-Head(Q)+1);
        }
        else
        {
            return (Tail(Q)-Head(Q)+1);
        }
    }
}

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    ((*Q).T)=(int *) malloc ((Max+1)*sizeof(int));
    if (((*Q).T)==0)
    {
        MaxEl(*Q)=0;
    }
    else
    {
        MaxEl(*Q)=Max;
        Head(*Q) = 0;
	    Tail(*Q) = 0;
    }
    
}

/* *** Destruktor *** */
void DeAlokasiQ(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    free((*Q).T);
    MaxEl(*Q)=0;
}

/* *** Primitif Add/Delete *** */
void AddQ (Queue * Q, int X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (Tail(*Q)==0)
    {
        Head(*Q)=1;
        Tail(*Q)=1;
    }
    else 
    {
        if (Tail(*Q)==MaxEl(*Q))
        {
             Tail(*Q)=1;
        }
        else
        {
            Tail(*Q)=(Tail(*Q)+1);
        }
    }
    InfoTail(*Q)=X;
    
}
void DelQ (Queue * Q, int * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = 0ai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
{
    (*X)=InfoHead(*Q);
    if (Head(*Q)==Tail(*Q))
    {
        Head(*Q)=0;
        Tail (*Q)=0;
    }
    else
    {
        if (Head(*Q)==MaxEl(*Q))
        {
            Head(*Q)=1;
        }
        else
        {
            Head(*Q)=((Head(*Q)+1));
        }
    } 
}