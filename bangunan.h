//TUBES ASTRUKDAT
//ADT Tipe Bangunan

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include <stddef.h>
#define Nil NULL


#include "boolean.h"
#include "point.h"
#include "queue.h"
#include "matriks.h"

typedef struct {
	int A;     // Nilai penambahan pasukan 
    int M;     // Jumlah pasukan maksimum
    int P;     // 1 untuk Yes dan 0 untuk No
    int U;     // Jumlah pasukkan diawal
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
}BANGUNAN;

void Inisialisasi(ACUAN *Ac);
//Jika ingin menggunakan acuan harus diinisialisasikan dulu
//I.S Acuan belom terinisialisasi
//F.S Acuan sudah bisa di pakai

void InisialisasiShieldNo(ACUAN *Ac);
//Jika ingin menggunakan acuan KHUSUS untuk Shield
//I.S Acuan belom terinisialisasi
//F.S Acuan sudah bisa di pakai

int CariDariAcuan (ACUAN Ac, char Jenis, int Lvl, char AMPU);
//I.S Acuan harus sudah di INISIALISASIKAN
//F.S Keluaran berupa integer

void MakeBANGUNANEmpty (BANGUNAN *B);
//Inisialisasi Bangunan dengan membuat semua elemennya 0
//I.S BANGUNAN belom ada/ belum terdefinisi
//F.S BANGUNAN sudah terinisialisasi

BANGUNAN MakeBANGUNAN (int Milik, int Jpas, int Level, char Jenis,  POINT Lok);
//Merancang BANGUNAN dari komponen-komponen yang ada
// I.S BANGUNAN sembarang
// F.S BANGUNAN terdefinisi

boolean JumlahPasukanValid (BANGUNAN B, int JPas);
//Menghasilkn True jika jumlah pasukan  <=M dan lebih dari nol
//Menghasilkan false untuk sebaliknya

boolean IsAdaPertahanan(BANGUNAN B);
//Menghasilkn True jika BANGUNAN memiliki pertahanan
//Menghasilkan false untuk sebaliknya

void ResetBANGUNAN(BANGUNAN *B, int  JPasNetto, int Milik);
//Reset bangunan dilakukan saat bangunan diambil alih
//I.S BANGUNAN masih kondisi sebelom diambil alih
//F.S BANGUNAN sudah kondisi setelah diambil alih

void CopyBANGUNAN(BANGUNAN Bin, BANGUNAN *Bout);
/* I.S. Bin terdefinisi, Bout sembarang */
/* F.S. Bout berisi salinan dari Bin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Bin ke Bout */

int getA(BANGUNAN B, ACUAN a);
// Berguna untuk mengambil nilai A dari Acuan
// I.S Acuan suda terinisialisasi
//F.S Menghasilkan keluar nilai integer dari nilai acuan A

int getM(BANGUNAN B, ACUAN a);
// Berguna untuk mengambil nilai M dari Acuan
// I.S Acuan suda terinisialisasi
//F.S Menghasilkan keluar nilai integer dari nilai acuan M

int getP(BANGUNAN B, ACUAN a);
// Berguna untuk mengambil nilai P dari Acuan
// I.S Acuan suda terinisialisasi
//F.S Menghasilkan keluar nilai integer dari nilai acuan P

int getU(BANGUNAN B, ACUAN a);
// Berguna untuk mengambil nilai U dari Acuan
// I.S Acuan suda terinisialisasi
//F.S Menghasilkan keluar nilai integer dari nilai acuan U

#endif