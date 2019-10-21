//TUBES ASTRUKDAT
//ADT Tipe Bangunan

#ifndef BANGUNAN_H
#define BANGUNAN_H

#include "boolean.h"
#include "point.h"

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
    POINT Lok;  //Menunjukkan Lokasi. Diakses dengan Lok.X dan Lok.Y
}BANGUNAN;


#endif