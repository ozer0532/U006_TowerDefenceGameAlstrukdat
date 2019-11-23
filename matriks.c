#include "boolean.h"
#include "matriks.h"
#include <stdio.h>
#include <math.h>
#include "pcolor.h"

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValidM (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	// KAMUS LOKAL

	// ALGORITMA
		return (BrsMin <= i && i <= BrsMax && KolMin <= j && j <= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
int GetFirstIdxBrsM (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	// KAMUS LOKAL

	// ALGORITMA
		return BrsMin;
}

int GetFirstIdxKolM (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	// KAMUS LOKAL

	// ALGORITMA
		return KolMin;
}

int GetLastIdxBrsM (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	// KAMUS LOKAL

	// ALGORITMA
		return NBrsEff(M);
}

int GetLastIdxKolM (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	// KAMUS LOKAL

	// ALGORITMA
		return NKolEff(M);
}

boolean IsIdxEffM (MATRIKS M, int i, int j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	// KAMUS LOKAL

	// ALGORITMA
		return (GetFirstIdxBrsM(M) <= i && i <= GetLastIdxBrsM(M) && GetFirstIdxKolM(M) <= j && j <= GetLastIdxKolM(M));
}

/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	// KAMUS LOKAL

	// ALGORITMA
		(*M).NBrsEff = NB;
		(*M).NKolEff = NK;
}


/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	// KAMUS LOKAL
		int i, j;

	// ALGORITMA
		MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);

		for (i = GetFirstIdxBrsM(*MHsl); i <= GetLastIdxBrsM(*MHsl); i++)
		{
			for (j = GetFirstIdxKolM(*MHsl); j <= GetLastIdxKolM(*MHsl); j++)
			{
				Elm(*MHsl, i, j).C = Elm(MIn, i, j).C;
				Elm(*MHsl, i, j).p = Elm(MIn, i, j).p;
			}
		}
}



