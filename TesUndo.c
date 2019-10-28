#include <stdlib.h>
#include "stackt.h"
#include "mesininput.h"
#include <stdio.h>


void Action(STATE *s){
    (*s).peta.NBrsEff += 5;
}


int main(){
    Stack states;
    STATE UNDO;
    STATE S;
    char c;
    LoadFile(&S);
    PrintState(S);
    Push(&states,S);
    printf("action?");scanf("%c",&c);
    Action(&S);
    PrintState(S);
    printf("undo?");scanf("%c",&c);
    Undo(&states,&UNDO);
    PrintState(S); 
    return 0;
}