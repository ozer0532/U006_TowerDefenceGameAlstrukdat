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
		(*M).NBrsEff = NB;
		(*M).NKolEff = NK;
}



