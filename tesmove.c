#include "attack.h"
#include "STATE.h"
#include "array.h"
#include <stdio.h>

int main(){
    STATE s;
    LoadSafeFile(&s);
    printf("shit");
    s.turn = 1;
    move(&s,&s.P1);
    move(&s,&s.P1);
    move(&s,&s.P1);
}