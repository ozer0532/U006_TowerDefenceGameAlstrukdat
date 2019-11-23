#ifndef STATE_H
#define STATE_H

#include "array.h"
#include "attack.h"
#include "bangunan.h"
#include "graph.h"
#include "player.h"
#include "skill.h"

typedef struct {
    Player P1,P2;
    BangunanTot listbtot;
    TabInt flagAttack;
    int JBang;
    int turn;
    MATRIKS peta;
    Graph Hubungan;
    char lastaction[30];
}STATE;

typedef struct {
    // GLOBAL
    BANGUNAN daftarBangunan[100];
    char lastaction[30];
    int flagAttack[100];
    int sizeFlagAttack;

    // PLAYER 1
    int bangunanPlayer1[30];
    int skillPlayer1[10];
    int shieldPlayer1;
    boolean extraTurnPlayer1;
    boolean attackUpPlayer1;
    boolean critHitPlayer1;

    // PLAYER 2
    int bangunanPlayer2[30];
    int skillPlayer2[10];
    int shieldPlayer2;
    boolean extraTurnPlayer2;
    boolean attackUpPlayer2;
    boolean critHitPlayer2;

} SAVEDSTATE;

void makeemptypeta(STATE *s);
void printpeta(STATE s);
SAVEDSTATE DuplicateSTATE(STATE S);
void SETSTATE(STATE * S, SAVEDSTATE s);
#endif