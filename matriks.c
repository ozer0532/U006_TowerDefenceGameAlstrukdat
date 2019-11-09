/* Nama		: Izharulhaq */
/* NIM		: 13518092 */
/* Tanggal	: Sabtu, 14 September 2019 */

/* File 	: matriks.c */

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>
#include <math.h>

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
boolean IsIdxValid (int i, int j)
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

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
	// KAMUS LOKAL

	// ALGORITMA
		return (GetFirstIdxBrs(M) <= i && i <= GetLastIdxBrs(M) && GetFirstIdxKol(M) <= j && j <= GetLastIdxKol(M));
}

int GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
	// KAMUS LOKAL

	// ALGORITMA
		return Elm(M, i, i);
}

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

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
	// KAMUS LOKAL
		indeks i, j;

	// ALGORITMA
		if (IsIdxValid(NB, NK))
		{
			MakeMATRIKS(NB, NK, M);
			for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
			{
				for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
				{
					scanf("%d", &Elm(*M, i, j));
				}
			}
		}
}

void makeemptypeta(MATRIKS *p)
{
    for (int i = 0; i <= (*p).NBrsEff;i ++){
		for (int j = 0; j <= (*p).NKolEff; j ++){
            Elm((*p),i,j) = 'e';
        }
    }
}


void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
	// KAMUS LOKAL
		indeks i, j;

	// ALGORITMA
		for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
		{
			for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
			{
				if (j < GetLastIdxKol(M)) printf("%d ", Elm(M, i, j));
				else printf("%d", Elm(M, i, j));
			}
			if (i < GetLastIdxBrs(M)) printf("\n");
		}

}

// /* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
// MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
// /* Prekondisi : M1  berukuran sama dengan M2 */
// /* Mengirim hasil penjumlahan matriks: M1 + M2 */
// {
// 	// KAMUS LOKAL
// 		indeks i, j;
// 		MATRIKS M3;

// 	// ALGORITMA
// 		MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M3);

// 		for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
// 		{
// 			for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
// 			{
// 				Elm(M3, i, j) = Elmt(M1, i, j) + Elm(M2, i, j);
// 			}
// 		}

// 		return M3;
// }

// MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
// /* Prekondisi : M berukuran sama dengan M */
// /* Mengirim hasil pengurangan matriks: salinan M1 � M2 */
// {
// 	// KAMUS LOKAL
// 		indeks i, j;
// 		MATRIKS M3;

// 	// ALGORITMA
// 		MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M3);

// 		for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++)
// 		{
// 			for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++)
// 			{
// 				Elm(M3, i, j) = Elm(M1, i, j) - Elm(M2, i, j);
// 			}
// 		}

// 		return M3;
// }

// MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
// /* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
// /* Mengirim hasil perkalian matriks: salinan M1 * M2 */
// {
// 	// KAMUS LOKAL
// 		indeks i, j, k;
// 		MATRIKS M3;

// 	// ALGORITMA
// 		MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M3);

// 		for (i = GetFirstIdxBrs(M3); i <= GetLastIdxBrs(M3); i++)
// 		{
// 			for (j = GetFirstIdxKol(M3); j <= GetLastIdxKol(M3); j++)
// 			{
// 				Elm(M3, i, j) = 0;

// 				for (k = GetFirstIdxBrs(M2); k <= GetLastIdxBrs(M2); k++)
// 				{
// 					Elm(M3, i, j) += Elmt(M1, i, k) * Elmt(M2, k, j);
// 				}
// 			}
// 		}

// 		return M3;
// }

// MATRIKS KaliKons (MATRIKS M, int X)
// /* Mengirim hasil perkalian setiap elemen M dengan X */
// {
// 	// KAMUS LOKAL
// 		indeks i, j;
// 		MATRIKS M3;

// 	// ALGORITMA
// 		MakeMATRIKS(NBrsEff(M), NKolEff(M), &M3);

// 		for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
// 		{
// 			for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++)
// 			{
// 				Elm(M3, i, j) = X * Elm(M, i, j);
// 			}
// 		}

// 		return M3;
// }
// void PKaliKons (MATRIKS * M, int K)
// /* I.S. M terdefinisi, K terdefinisi */
// /* F.S. Mengalikan setiap elemen M dengan K */
// {
// 	// KAMUS LOKAL

// 	// ALGORITMA
// 		*M = KaliKons(*M, K);
// }

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
// boolean EQM (MATRIKS M1, MATRIKS M2)
// /* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
// /* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
// /* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
//    dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
// {
// 	// KAMUS LOKAL
// 		indeks i, j;

// 	// ALGORITMA
// 		if (!EQSize(M1, M2)) return false;
// 		else
// 		{
// 			i = GetFirstIdxBrs(M1);
// 			while (i <= GetLastIdxBrs(M1))
// 			{
// 				j = GetFirstIdxKol(M1);
// 				while (j <= GetLastIdxKol(M1))
// 				{
// 					if (Elmt(M1, i, j) != Elmt(M2, i, j)) return false;
// 					j++;
// 				}
// 				 i++;
// 			}
// 			return true;
// 		}
// }

// boolean NEQM (MATRIKS M1, MATRIKS M2)
// /* Mengirimkan true jika M1 tidak sama dengan M2 */
// {
// 	// KAMUS LOKAL

// 	// ALGORITMA
// 		return (!EQ(M1, M2));
// }

// boolean EQSizeM (MATRIKS M1, MATRIKS M2)
// /* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
// /* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
// {
// 	// KAMUS LOKAL

// 	// ALGORITMA
// 		return (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2));
// }

// /* ********** Operasi lain ********** */
// int NBElmtM (MATRIKS M)
// /* Mengirimkan banyaknya elemen M */
// {
// 	// KAMUS LOKAL

// 	// ALGORITMA
// 		return NBrsEff(M) * NKolEff(M);
// }

// /* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
// boolean IsBujurSangkar (MATRIKS M)
// /* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
// {
// 	// KAMUS LOKAL

// 	// ALGORITMA
// 		return NBrsEff(M) == NKolEff(M);
// }

// boolean IsSimetri (MATRIKS M)
// /* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
//    dan untuk setiap elemen M, M(i,j)=M(j,i) */
// {
// 	// KAMUS LOKAL
// 		indeks i, j;
// 		boolean equal;

// 	// ALGORITMA
// 		if(!IsBujurSangkar(M)) return false;
// 		else
// 		{
// 			i = GetFirstIdxBrs(M);
// 			equal = true;

// 			while (equal && i <= GetLastIdxBrs(M))
// 			{
// 				j = i;

// 				while (equal && j <= GetLastIdxKol(M))
// 				{
// 					equal = Elmt(M, i, j) == Elmt(M, j, i);
// 					j++;
// 				}

// 				i++;
// 			}

// 		}
// 		return equal;
// }

// boolean IsSatuan (MATRIKS M)
// /* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
//    setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
// {
// 	// KAMUS LOKAL
// 		indeks i, j;
// 		boolean equal;

// 	// ALGORITMA
// 		if(!IsBujurSangkar(M)) return false;
// 		else
// 		{
// 			i = GetFirstIdxBrs(M);
// 			j = GetFirstIdxKol(M);
// 			equal = true;

// 			while (equal && i <= GetLastIdxBrs(M))
// 			{
// 				while (equal && j <= GetLastIdxKol(M))
// 				{
// 					if (i == j) equal = Elmt(M, i, j) == 1;
// 					else equal = Elmt(M, i, j) == 0;
// 					j++;
// 				}

// 				i++;
// 			}

// 			return equal;
// 		}
// }

// boolean IsSparse (MATRIKS M)
// /* Mengirimkan true jika M adalah matriks sparse: mariks �jarang� dengan definisi:
//    hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
// {
// 	// KAMUS LOKAL
// 		int maxSize;
// 		float ratio;

// 	// ALGORITMA
// 		maxSize = BrsMax * KolMax;
// 		ratio = NBElmt(M) / maxSize;

// 		return ratio <= 0.05;
// }

// MATRIKS Inverse1 (MATRIKS M)
// /* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
// {
// 	// KAMUS LOKAL

// 	// ALGORITMA
// 		return KaliKons(M, -1);
// }

// float Determinan (MATRIKS M)
// /* Prekondisi: IsBujurSangkar(M) */
// /* Menghitung nilai determinan M */
// {
// 	// KAMUS LOKAL
// 		indeks i, j, k, l;
// 		float det;
// 		MATRIKS minor;

// 	// ALGORITMA
// 		if (NKolEff(M) == 1) det = Elmt(M, GetFirstIdxBrs(M), GetFirstIdxBrs(M));
// 		else
// 		{
// 			det = 0;
// 			MakeMATRIKS(NBrsEff(M) - 1, NKolEff(M) - 1, &minor);

// 			for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++)
// 			{
// 				for (j = GetFirstIdxBrs(M) + 1; j <= GetLastIdxBrs(M); j++)
// 				{
// 					l = 0;
// 					for (k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++)
// 					{
// 						if (k == i) l =- 1;
// 						else Elmt(minor, j - 1, k + l) = Elmt(M, j, k);
// 					}
// 				}
// 				if (Elmt(M, GetFirstIdxBrs(M), i) != 0) det += pow(-1, i + 1) * Elmt(M, GetFirstIdxBrs(M), i) * Determinan(minor);
// 			}
// 		}
// 		return det;
// }
// void PInverse1 (MATRIKS * M)
// /* I.S. M terdefinisi */
// /* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
// {
// 	// KAMUS LOKAL

// 	// ALGORITMA
// 		*M = Inverse1(*M);
// }

// void Transpose (MATRIKS * M)
// /* I.S. M terdefinisi dan IsBujursangkar(M) */
// /* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
// {
// 	// KAMUS LOKAL
// 		int i, j;
// 		MATRIKS M2;

// 	// ALGORITMA
// 		CopyMATRIKS(*M, &M2);

// 		for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++)
// 		{
// 			for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++)
// 			{
// 				Elm(*M, i, j) = Elm(M2, j , i);
// 			}
// 		}
// }

void printpeta(MATRIKS p){
	for (int i = 0; i <= p.NBrsEff;i ++){
		for (int j = 0; j <= p.NKolEff; j ++){
			if ((i == 0)||(j == 0)||(i == p.NBrsEff)||(j == p.NKolEff)){
				printf("*");
			}
			else {
				if (Elm(p,i,j) == 'e') printf(" ");
				else printf("%c",Elm(p,i,j));
			}
			if (j == p.NKolEff) printf("\n");
		}
	}
}