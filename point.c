//TUBES ALSTRUKDAT

#include "point.h"
#include <stdio.h>


POINT MakePOINT (int X, int Y)
//Merancang POINT dari komponen komponennya
{
	POINT p;
	p.X = X;
	p.Y = Y;
	return p;
}

boolean IsDalamMatriks (POINT P, int i, int j)
//Menghasilkan True jika Komponen  X<=i dan Y<=j dimana i adalah baris matriks dan j adalah kolom matriks
{
    return ((P.X<=i && P.X>0)&&(P.Y<=j && P.Y>0));
}