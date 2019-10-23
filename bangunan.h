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
    char P;     // y untuk Yes dan 'n' untuk No
    int U;
}KOMPONEN;

typedef KOMPONEN ElType;   /* type elemen tabel */

typedef struct {
	ElType C[5]; /* memori tempat penyimpan elemen (container) */
    ElType T[5]; /* memori tempat penyimpan elemen (container) */
    ElType F[5]; /* memori tempat penyimpan elemen (container) */
    ElType V[5]; /* memori tempat penyimpan elemen (container) */
}JNS;



typedef struct {
	char Milik; 
    //Terdiri dari A untuk player 1, B untuk player 2, X untuk bangunan yang belum dikuasai
    
    JNS JenisAcuan;
    /*Cara akses buat jenis acuan
    Bangunan B;
    B.C[1].A   -- nandain kalau ngeliat acuan dari Castle(C) Level 1 untuk bagian A nya 
    B.F[5].P   -- melihat acuan dari Fort(F) Level 5 bagian P nya
    */

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
    BANGUNAN listb[31];
    int JBang;
    int turn;
    Queue sA, sB;
    MATRIKS peta;
}STATE;

typedef struct {
    Queue SA;
    Queue SB;
} Skill;


#endif