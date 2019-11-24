#include <stdio.h>
#include "point.h"
#include "boolean.h"
#include <math.h>

int main()
{

	//Realisasi TulisPOINT dan MakePOINT
	POINT p1,p2,p3,p4;
	p3=MakePOINT(30,60);
	p4=MakePOINT(50,60);
	TulisPOINT(p3);
	printf(" dan ");
	TulisPOINT(p4);
	printf("\n");

	//Realisasi EQ
	if (EQP(p3,p4))
	{
		printf("sama\n");
	}
	else
	{
		printf("tidak equivalen\n");
	}

	//Realisasi NEQ
	if (NEQP(p3,p4))
	{
		printf("tidak equivalen\n");
	}
	else
	{
		printf("sama\n");
	}

	//Realisasi IsOrign, isOnSbX, isOnSbX dan Kuadran
	if (IsOrigin(p3))
	{
		printf("p1 di titik pusat\n");
	}
	else if (IsOnSbX(p3))
	{
		printf("p1 di sumbu x\n");
	}
	else if (IsOnSbY(p3))
	{
		printf("p1 di sumbu y\n");
	}
	else 
	{
		printf("p1 ada di kuadran %d\n", Kuadran(p1));
	}
	
	//Realisasi NextX, NextY, PlusDelta
	TulisPOINT(NextX(p3));
	TulisPOINT(NextY(p4));
	printf("\njika x1 digabungkan dengan y2 akan menjadi\n");
	TulisPOINT(PlusDelta(p3,1,1));
	
	//Realisasi miror,jarak0,panjang
	printf("Hasil cerminnya : ");
	TulisPOINT(MirrorOf(PlusDelta(p3,1,1), true));
	TulisPOINT(MirrorOf(PlusDelta(p4,1,1), false));
	printf("\nJarak p1 dengan Origin = %.2f\n",Jarak0(p3));
	printf("Jarak p1 dengan p2 = %.2f\n",Panjang(p3,p4));	

	return 0;
}
