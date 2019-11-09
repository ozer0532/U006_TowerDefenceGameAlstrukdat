#include <stdlib.h>
#include "stackt.h"
#include "mesininput.h"
#include <stdio.h>




int main(){
    Stack sss;
    // Stack *sa;
    // sa = &states;
    STATE UNDO;
    STATE S;
    char c;
    CreateEmpty(&sss);
    LoadFile(&S);
    PrintState(S);
    // Top(sss) += 1;
    // InfoTop(sss) = S;
    Poosh(&sss,S);
    PrintState(InfoTop(sss));
    printf("action?");scanf(" %c",&c);
    Action(&S);
    PrintState(S);
    printf("undo?");scanf(" %c",&c);
    Undo(&sss,&S);
    PrintState(S); 
    return 0;
}