#include <stdio.h>
#include "listlinier.h"
#include "boolean.h"

int main () {
	List L;
	CreateEmptyL(&L);
	int N,M,X;
	scanf("%d",&N);
	for (int i=1;i<=N;i++) {
		InsVLastL(&L,i);
	}
	PrintInfoL(L);
	printf("\n");

	int Y;
	DelVLastL(&L,&Y);
	InsVLastL(&L,100);
	PrintInfoL(L);
	printf("\n");

return 0;
}