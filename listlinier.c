
#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "boolean.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyL (List L)
/* Mengirim true jika list kosong */
{
    return(First(L)==Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyL (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    First(*L)=Nil;
}

/****************** Manajemen Memori ******************/
address AlokasiL (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P;
    P = (address) malloc (sizeof(ElmtList));
    if (P!=Nil)
    {
        Info(P)=X;
        Next(P)=Nil;
        return P;
    }
    else
    {
        return Nil;
    }
}
void DealokasiL (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}
/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address SearchL (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P;
    boolean found=false;
    P=First(L);
    while (((P)!=Nil) && !(found))
    {
        if (Info(P)==X)
        {
            found=true;
        }
        else
        {
            P=Next(P);
        }
    }

    if (found=true)
    {
        return P;
    }
    else
    {
        return Nil;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P;
    P=AlokasiL(X);
    if (P!=Nil)
    { 
        InsertFirstL(L,P);
    }
}
void InsVLastL (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P;
    P=AlokasiL(X);
    if (P!=Nil){
        InsertLastL(L,P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstL (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address (P);
    DelFirstL(L,&P);
    (*X)=Info(P);
    DealokasiL(&P);
}
void DelVLastL (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P;
    DelLastL(L,&P);
    (*X)=Info(P);
    DealokasiL(&P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstL (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P)=First(*L);
    First(*L)=P;
}
void InsertAfterL (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    if(IsEmptyL(*L)) {
        InsertFirstL(L,P);
    }
    else {
        Next(P)=Next(Prec);
        Next(Prec)=P;
    }
}
void InsertLastL (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address Last;
    Last=First(*L);
    if (Last!=Nil)
    {
        while (Next(Last)!=Nil)
        {
            Last=Next(Last);
        }
        Next(Last)=P;
    }
    else
    {
        InsertFirstL(L,P);
    }
    
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstL (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    (*P)=(First(*L));
    First(*L)=Next(*P);
    Next(*P)=Nil;
}

void DelPL (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P;
    address Prec;
    boolean found=false;
    P=SearchL((*L),X);
    if (P!=Nil)
    {
        if (P==First(*L)){
            DelFirstL(L,&P);
        }
        else {
            Prec=First(*L);
            while(Next(Prec)!=P)
            {
                Prec=Next(Prec);
            }
            Next(Prec)=Next(P);
            Next(P)=Nil;
            DealokasiL(&P);
        }
    }
}
void DelLastL (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    address X;
    X=First(*L);
    if (Next(X)!=Nil)
    {
        while (((Next(Next(X)))!=Nil))
        {
            X=Next(X);
        }
        (*P)=Next(X);
        Next(X)=Nil;
    }
    else
    {
        DelFirstL(L,P);
    }
}

void DelAfterL (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    if ((Prec)==Nil) {
        (*Pdel)=First(*L);
        First(*L)=Nil;
    }
    else {
        (*Pdel)=Next(Prec);
        Next(Prec)=Next(Next(Prec));
        Next(*Pdel)=Nil;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfoL (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    if (!IsEmptyL(L)){
        address P=First(L);
        while (P!=Nil) {
            printf("%d",Info(P));
            if (Next(P)!=Nil) {
                printf(",");
            }
            P=Next(P);
        }
    }
    printf("]");
}
int NbElmtL (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int i=0;
    if(IsEmptyL(L)) {
        return 0;
    }
    else {
        address P=First(L);
        while (P!=Nil) {
           i+=1; 
           P=Next(P);
        }
        return i;
    }
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype MaxL (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    infotype maxi = Info(First(L));
    address P = Next(First(L));
    while (P!=Nil) {
        if (Info(P)>maxi) {
            maxi = Info(P);
        }
        else {
            P=Next(P);
        }
    }
    return maxi;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1L (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    address Last;
    CreateEmptyL(L3);
    if (!IsEmptyL(*L1)) {
        First(*L3)=First(*L1);
        First(*L1)=Nil;
    
        Last=First(*L3);
        while (Next(Last)!=Nil) {
            Last=Next(Last);
        }

        Next(Last)=First(*L2);
        First(*L2)=Nil;
    }
    
    else {
        First(*L3)=First(*L2);
        First(*L2)=Nil;
    }  
}
