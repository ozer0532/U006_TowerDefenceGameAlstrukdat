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
<<<<<<< HEAD
    PrintState(S);
    printpeta(S);
=======
    Push(&sss,S);
    PrintState(S);
    Undo(&sss,&S);
    PrintState(S);
    
>>>>>>> cac2320d8ff764b6509a03c85fec1841527ca878

}