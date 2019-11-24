#include <stdio.h>
#include "queue.h"

int main(){
Queue Q;
int x,y;
CreateEmptyQ(&Q,10); // membuat queue dengan maskimum 10
while(!IsFullQ(Q)){
    scanf("%d", &x);
    AddQ(&Q,x);
}
while (!IsEmptyQ(Q))
{
    DelQ(&Q,&y);
    printf("Masukan Queue Anda: %d\n", y);
}




    return 0;
}