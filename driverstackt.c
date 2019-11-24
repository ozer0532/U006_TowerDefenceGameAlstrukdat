#include "stackt.h"
#include "STATE.h"
#include "mesininput.h"
#include <stdio.h>

int main () {
    // KAMUS LOKAL
    Stack S;
    STATE P;
    SAVEDSTATE SS;

    // ALGORITMA
    CreateEmpty(&S);

    P.turn = 1;
    InitPlayer(&P.P1); InitPlayer(&P.P2); 
    P.P1.playerKe = 1; P.P2.playerKe = 2;
    LoadFile(&P);

    printf("%d\n", IsEmptyST(S));
    printf("%d\n", IsFullST(S));

    Push(&S, P);

    printf("%d\n", IsEmptyST(S));
    printf("%d\n", IsFullST(S));
    
    Pop(&S, &SS);

    printf("%d\n", IsEmptyST(S));
    printf("%d\n", IsFullST(S));

    printf("Program Ran Till The End\n");
    return 0;
}