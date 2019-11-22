/* Nama		: Izharulhaq */
/* NIM		: 13518092 */
/* Tanggal	: Sabtu, 14 September 2019 */

/* File 	: matriks.c */

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>
#include <math.h>
#include "pcolor.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
	// KAMUS LOKAL

	// ALGORITMA
		NBrsEff(*M) = NB;
		NKolEff(*M) = NK;
}





/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValidM (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
	// KAMUS LOKAL

	// ALGORITMA
		return (BrsMin <= i && i <= BrsMax && KolMin <= j && j <= KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
	// KAMUS LOKAL

	// ALGORITMA
		return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
	// KAMUS LOKAL

	// ALGORITMA
		return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
	// KAMUS LOKAL

	// ALGORITMA
		return NBrsEff(M);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
	// KAMUS LOKAL

	// ALGORITMA
		return NKolEff(M);
}

boolean IsIdxEffM (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	// KAMUS LOKAL

	// ALGORITMA
		return (GetFirstIdxBrs(M) <= i && i <= GetLastIdxBrs(M) && GetFirstIdxKol(M) <= j && j <= GetLastIdxKol(M));
}

// int GetElmtDiagonal (MATRIKS M, indeks i)
// /* Mengirimkan elemen M(i,i) */
// {
// 	// KAMUS LOKAL

// 	// ALGORITMA
// 		return Elm(M, i, i);
// }

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
	// KAMUS LOKAL
		indeks i, j;

	// ALGORITMA
		MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);

		for (i = GetFirstIdxBrs(*MHsl); i <= GetLastIdxBrs(*MHsl); i++)
		{
			for (j = GetFirstIdxKol(*MHsl); j <= GetLastIdxKol(*MHsl); j++)
			{
				Elm(*MHsl, i, j) = Elm(MIn, i, j);
			}
		}
}
