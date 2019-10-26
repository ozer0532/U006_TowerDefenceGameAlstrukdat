// Nama / NIM : Chokyi  Ozer / 13518107
// Tanggal : 17 Oktober 2019
// Topik : ADT STACK
// Desripsi : ADT STACK

#include "stackt.h"

/* ************ Prototype ************ */

/* *** Konstruktor/Kreator *** */

/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
void CreateEmpty (Stack *S) {
    Top(*S) = Nil;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */

/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsEmpty (Stack S) {
    return Top(S) == Nil;
}

/* Mengirim true jika tabel penampung nilai elemen stack penuh */
boolean IsFull (Stack S) {
    return Top(S) == MaxEl;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */

/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
void Push (Stack * S, infotype X) {
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */

/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void Pop (Stack * S, infotype* X) {
    *X = InfoTop(*S);
    Top(*S)--;
}