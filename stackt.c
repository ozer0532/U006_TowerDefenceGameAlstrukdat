#include "stackt.h"

void CreateEmpty (Stack *S){
    Top(*S) = NilST;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */


/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyST (Stack S){
    return (Top(S) == NilST);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullST (Stack S){
    return (Top(S) == MaxElStack);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushSTATE(Stack * S, STATE X){
    if (IsEmptyST(*S) == true){
        Top(*S) = 1;
        InfoTop(*S) = X;
    }
    else{
        Top(*S) += 1;
        InfoTop(*S) = X;
    }
}

void Poosh(Stack *S,STATE X){
    if (Top(*S) == NilST){
        Top(*S) = 1;
        InfoTop(*S) = X;
    }
    else{
        Top(*S) += 1;
        InfoTop(*S) = X;
    }
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, STATE* X){
    *X = InfoTop(*S);
    Top(*S) -= 1;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void Undo(Stack *S,STATE *s){
    *s = InfoTop(*S);
    Top(*S) -= 1;
}