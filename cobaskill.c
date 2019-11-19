#include <stdio.h>
#include "skill.h"

int  main(){
    BangunanTot Ba;
    Player P;

    Shield(&P);
    printf("%d", P.shieldCooldown);

}