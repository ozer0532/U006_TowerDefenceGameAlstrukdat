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
	ElType TI[5]; /* memori tempat penyimpan elemen (container) */
}CASTLE;

typedef struct {
	ElType TI[5]; /* memori tempat penyimpan elemen (container) */
}TOWER;

typedef struct {
	ElType TI[5]; /* memori tempat penyimpan elemen (container) */
}FORT;

typedef struct {
	ElType TI[5]; /* memori tempat penyimpan elemen (container) */
}VILLAGE;

typedef struct {
	CASTLE C;
    TOWER T;
    FORT F;
    VILLAGE V;
}JNS;


typedef struct {
	char Milik; //Terdiri dari A untuk player 1, B untuk player 2, X untuk bangunan yang belum dikuasai
    JNS Jenis;  //Jenis Bangunannya
    int Jpas;   //Jumlah pasukan
    int Level;  //Level
    POINT Lok;  //Menunjukkan Lokasi. Diakses dengan Lok.X dan Lok.Y
}BANGUNAN;


#endif