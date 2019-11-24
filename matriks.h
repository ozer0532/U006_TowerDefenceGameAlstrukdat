/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef MATRIKS_H
#define MATRIKS_H

#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 1
#define BrsMax 20
#define KolMin 1
#define KolMax 30


typedef int indeks;
typedef struct {
    char C;
    int p;
}petainfo;
typedef struct {
    petainfo Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
    int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */


/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elm(M,i,j) (M).Mem[i][j]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValidM (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
int GetFirstIdxBrsM (MATRIKS M);
/* Mengirimkan indeks baris terkecil M */
int GetFirstIdxKolM (MATRIKS M);
/* Mengirimkan indeks kolom terkecil M */
int GetLastIdxBrsM (MATRIKS M);
/* Mengirimkan indeks baris terbesar M */
int GetLastIdxKolM (MATRIKS M);
/* Mengirimkan indeks kolom terbesar M */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M);
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* ********** Operasi lain ********** */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl);
/* Melakukan assignment MHsl  MIn */



#endif
