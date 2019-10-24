//TUBES ASTRUKDAT
//ADT Tipe Bangunan

#ifndef BANGUNAN_H
#define BANGUNAN_H

#define Nil NULL

#include "boolean.h"
#include "point.h"
#include "queue.h"
#include "matriks.h"

typedef struct {
	int A; 
    int M;
    int P;     // 1 untuk Yes dan 0 untuk No
    int U;
}KOMPONEN;

typedef KOMPONEN EllType;   /* type elemen tabel */


typedef struct {   
    EllType C[5]; /* memori tempat penyimpan elemen (container) */
    EllType T[5]; /* memori tempat penyimpan elemen (container) */
    EllType F[5]; /* memori tempat penyimpan elemen (container) */
    EllType V[5]; /* memori tempat penyimpan elemen (container) */
    /*Cara akses buat jenis acuan
    Acuan A;
    A.C[1].A   -- nandain kalau ngeliat acuan dari Castle(C) Level 1 untuk bagian A nya 
    B.F[5].P   -- melihat acuan dari Fort(F) Level 5 bagian P nya
    */
}ACUAN;

typedef struct {
	int Milik; 
    //Terdiri dari 1 untuk player 1, 2 untuk player 2, X untuk bangunan yang belum dikuasai
    //Milik = 0 jika belom dimiliki siapa-siapa
    int Jpas;       //Jumlah pasukan
    int Level;      //Level
    char Jenis;     //ini bisa dijadiin buat jenis bangunan saat ini
    POINT Lok;      //Menunjukkan Lokasi. Diakses dengan Lok.X dan Lok.Y
    int hubungan[31];

    //btw kayanya ngga akan kepake
    int A[5],M[5],U;
    boolean P[5];  
}BANGUNAN;


typedef struct {
    Queue SA;
    Queue SB;
} SKILL;

typedef struct {
    BANGUNAN listb[31];
    int JBang;
    int turn;
    SKILL S;
    MATRIKS peta;
}STATE;



void Inisialisasi(ACUAN *Ac);
//Jika ingin menggunakan acuan harus diinisialisasikan dulu

//Cari acuan
int CariDariAcuan (ACUAN Ac, char Jenis, int Lvl, char AMPU);
//I.S Acuan harus sudah di INISIALISASIKAN
//F.S Keluaran berupa integer

void MakeBANGUNANEmpty (BANGUNAN *B);
//Inisialisasi Bangunan dengan membuat semua elemennya 0

BANGUNAN MakeBANGUNAN(BANGUNAN *B, int Milik, int Jpas, int Level, char Jenis,  POINT Lok);
//Merancang BANGUNAN dari komponen-komponen yang ada
// I.S BANGUNAN sembarang
// F.S BANGUNAN terdefinisi

boolean JumlahPasukanValid (BANGUNAN B, int JPas);
//True jika jumlah pasukan  <=M

void ResetBANGUNAN(BANGUNAN *B, int JPasAwal, int Milik);
//Reset bangunan dilakukan saat bangunan diambil alih
#endif