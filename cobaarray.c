#include <stdio.h>
#include "array.c"
#include "bangunan.c"

int main () {
    BangunanTot B;
    MakeEmptyBangunanTot(&B);
    printf("%d",B.TI[3].Level);
    return 0;
}