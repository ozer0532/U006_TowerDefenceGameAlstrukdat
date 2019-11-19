#ifndef STATE_H
#define STATE_H

#include "array.h"
#include "bangunan.h"
#include "graph.h"
#include "player.h"
#include "skill.h"

typedef struct {
    Player P1,P2;
    BangunanTot listbtot;
    int JBang;
    int turn;
    Queue S;
    MATRIKS peta;
    Graph Hubungan;
    char lastaction[30];
}STATE;


void makeemptypeta(STATE *s);
void printpeta(STATE s);
#endif