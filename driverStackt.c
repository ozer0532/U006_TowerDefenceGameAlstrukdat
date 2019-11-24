#include "stackt.h"
#include <stdio.h>

int main ()
{
	Stack S,T;
	CreateEmpty(&S);
	CreateEmpty(&T);
	
	int m,n,x,x2,x3;
	scanf("%d",&m);
	scanf("%d",&n);
	if (m==0 && n==0)
	{
		printf("Sama\n");
	}
	else
	{
		int i=1;
		while (i<=m)
		{
			scanf("%d",&x);
			if ((x!=0))
			{
				if (!(IsFull(S)))
				{
					Push(&S,x);
				}
			}
			else
			{
				 if ((!IsEmpty(S)))
				 {
					Pop(&S,&x);
				 }
			}
			i++;
		}
		int j=1;
		while (j<=n)
		{
			scanf("%d",&x2);
			if ((x2!=0))
			{
				if (!(IsFull(T)))
				{
					Push(&T,x2);
				}
			}
			else
			{
				if ((!IsEmpty(T)))
				{
					Pop(&T,&x2);
				}
			}
			j++;	
		}
		if (IsSame(S,T))
		{
			printf("Sama\n");
		}
		else
		{
			printf("Tidak sama\n");
		}
			
	}

return 0;
}