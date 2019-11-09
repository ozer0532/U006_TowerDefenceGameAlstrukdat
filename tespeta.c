#include "matriks.h"
#include "mesininput.h"
#include "STATE.h"
#include "mesinkar.h"


main(){
    STATE S;
    LoadFile(&S);
    PrintState(S);
    printpeta(S.peta);

}