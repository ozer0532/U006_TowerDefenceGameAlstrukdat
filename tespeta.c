#include "matriks.h"
#include "mesininput.h"
#include "STATE.h"
#include "mesinkar.h"



int main(){
    STATE S;
    LoadFile(&S);
    PrintState(S);
    printpeta(S);
    return 0;
}