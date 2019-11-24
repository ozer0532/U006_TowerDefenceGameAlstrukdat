#include "matriks.h"
#include "mesininput.h"
#include "STATE.h"
#include "mesinkar.h"

void PrintStatus(STATE S, Player * Pe) {
    printf("\n\n\n\n\n");
    boolean(bol);
    printpeta(S);
    printf("Player %d\n", Pe -> playerKe);
    CetakDaftarBangunan(S.listbtot, *Pe, &bol);
}


int main(){
     // Variabel laju game

        STATE S;
        Player * currentPlayer;
        Player * opposingPlayer;

        currentPlayer = &S.P1;
        opposingPlayer = &S.P2;
        S.turn = 1;
        S.P1.playerKe = 1; S.P2.playerKe = 2;      

        currentPlayer = &S.P1;
        opposingPlayer = &S.P2;

        LoadFile(&S);
 
        PrintStatus(S, currentPlayer);
}