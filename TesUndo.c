#include <stdlib.h>
#include "stackt.h"
#include "mesininput.h"
#include <stdio.h>

void Action(STATE *s);
void Action(STATE *s){
    (*s).peta.NBrsEff += 5;
}



int main(){
    Stack sss;
    // Stack *sa;
    // sa = &states;
    STATE UNDO;
    STATE S;
    char c;
    CreateEmpty(&sss);
    LoadFile(&S);   //inisialissasi State pertama
    PrintState(S);
    // Top(sss) += 1;
    // InfoTop(sss) = S;
    Poosh(&sss,S); //state pertama di push sebelum aksi
    printf("action?");scanf(" %c",&c); // aksi tes
    Action(&S);
    PrintState(S); // print state setelah aksi
    printf("undo?");scanf(" %c",&c);
    Undo(&sss,&S); //undo, state di pop ke curstate
    PrintState(S);  
    return 0;   
}