#include "player.h"
#include <stdio.h>

int main () {
    Player P;
    InitPlayer(&P);
    PrintInfoL(P.bangunanPlayer);
    printf("\n");
    printf("%d\n",P.shieldCooldown);
}