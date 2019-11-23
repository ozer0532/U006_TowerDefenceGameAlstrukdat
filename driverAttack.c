#include <stdio.h>
#include "boolean.h"
#include "queue.h"
#include "mesininput.h"
#include "bangunan.h"
#include "listlinier.h"
#include "STATE.h"
#include "attack.h"
#include "stackt.h"

//Cara compile gcc -o driverAttack driverAttack.c queue.c mesininput.c bangunan.c listlinier.c stackt.c STATE.c array.c graph.c matriks.c mesinkar.c pcolor.c point.c skill.c player.c attack.c

int main()
{
    //Kamus
    boolean booleanAttackUp;
    boolean bol;
    STATE S;
    Player * currentPlayer;
    Player * opposingPlayer;

    // ALGORITMA
    printf("Simulasi Attack\n");
    
    //Inisialisasi Awal untuk flag
    TabInt Tab;
    MakeEmptyarr(&Tab); //insialisasi awal flag atatck di tiap giliran main 
    
    currentPlayer = &S.P1;
    opposingPlayer = &S.P2;
    S.turn = 1;
    InitPlayer(&S.P1); InitPlayer(&S.P2); 
    S.P1.playerKe = 1; S.P2.playerKe = 2;                   
    currentPlayer = &S.P1;
    opposingPlayer = &S.P2;

    //Load State
    LoadFile(&S);
    
    //Memulai Attack
    booleanAttackUp=false;
    Attack(S.Hubungan, &(S), currentPlayer, opposingPlayer, &Tab, booleanAttackUp);


    return 0;
}