#include "STATE.h"
#include "stackt.h"
#include "mesininput.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    STATE S;
    Stack sss;

    CreateEmpty(&sss);
    LoadFile(&S);
    Poosh(&sss,S);
    PrintState(S);

}