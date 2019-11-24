//TUBES ALSTRUKDAT

#include "point.h"
#include <stdio.h>
#include <math.h>



POINT MakePOINT (int X, int Y)
//Merancang POINT dari komponen komponennya
{
	POINT p;
	p.X = X;
	p.Y = Y;
	return p;
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */

void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
	float a,b;
	scanf ("%d %d",&a,&b);
	*P = MakePOINT (a,b);
}

void TulisPOINT (POINT P)
{
	printf("(%d,%d)",P.X, P.Y);
}
/* Nilai P ditulis ke layar dengan format "(X,Y)"
   tanpa spasi, enter, atau karakter lain di depan, belakang,
   atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQP (POINT P1, POINT P2)
{
	return ((P1.X==P2.X)&&(P1.Y==P2.Y));
}

/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQP (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
	return ((P1.X!=P2.X)&&(P1.Y!=P2.Y));
}
/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
{
	return((P.X==0)&(P.Y==0));
}
/* Menghasilkan true jika P adalah titik origin */
boolean IsOnSbX (POINT P)
{
	return(P.Y==0);
}
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P)
{
	return(P.X==0);
}
/* Menghasilkan true jika P terletak pada sumbu Y */
int Kuadran (POINT P)
{
	int i;
	if ((P.X>0)&(P.Y>0)){
		i=1;}
	else if ((P.X<0)&(P.Y>0)){
		i=2;}
	else if ((P.X<0)&(P.Y<0)){
		i=3;}
	else if ((P.X>0)&(P.Y<0)){
		i=4;}
	return i;
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
POINT NextX (POINT P)
{
	return (MakePOINT(P.X+1,P.Y));
}
/* Mengirim salinan P dengan absis ditambah satu */
POINT NextY (POINT P)
{
	return (MakePOINT(P.X,(P.Y+1)));
}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PlusDelta (POINT P, float deltaX, float deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
	return (MakePOINT((P.X+deltaX),(P.Y+deltaY)));
}

POINT MirrorOf (POINT P, boolean SbX)
{
	POINT p0;
	if (SbX == true)
	{
		p0.X=(-1)*P.X;
		p0.Y=P.Y;
	}
	else if (SbX == false)
	{
		p0.X=P.X;
		p0.Y=(-1)*P.Y;
	}	
	return p0;
}
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
float Jarak0 (POINT P)
{
	return (sqrt(((P.Y)*(P.Y))+((P.X)*(P.X))));
}
/* Menghitung jarak P ke (0,0) */
float Panjang (POINT P1, POINT P2)
{
	return (sqrt((P2.Y-P1.Y)*(P2.Y-P1.Y))+((P2.X-P1.X)*(P2.X-P1.X)));
}
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */

