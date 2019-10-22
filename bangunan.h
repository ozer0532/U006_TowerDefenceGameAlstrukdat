//TUBES ASTRUKDAT
//ADT Tipe Bangunan

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "boolean.h"
#include "point.h"
#include "queue.h"
#include "matriks.h"

typedef struct {
	int A; 
    int M;
    int P;
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
	char Milik; //Terdiri dari A untuk player 1, B untuk player 2, X untuk bangunan yang belum dikuasai
    JNS Jenis;  //Jenis Bangunannya
    int Jpas;   //Jumlah pasukan
    int Level;  //Level
    char jenis; //for now biar gw bisa progress mesininput gini, gw ga paham cara ngeassign jenis kalo bentuknya kaya diatas
    int A[5],M[5],U;
    boolean P[5];
    POINT Lok;  //Menunjukkan Lokasi. Diakses dengan Lok.X dan Lok.Y
    int hubungan[31];
}BANGUNAN;

typedef struct {
    BANGUNAN listb[31];
    int JBang;
    int turn;
    Queue sA, sB;
    MATRIKS peta;
}STATE;


#endif