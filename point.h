//TUBES ALSTRUKDAT

#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct {
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;

#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/* Konstruktor */
POINT MakePOINT (int X, int Y);
//Merancang POINT dari komponen komponennya

boolean IsDalamMatriks (POINT P, int i, int j);
//Menghasilkan True jika Komponen  X<=i dan Y<=j dimana i adalah baris matriks dan j adalah kolom matriks

#endif
