#ifndef STATE_H
#define STATE_H

#include "array.h"
#include "bangunan.h"
#include "graph.h"


typedef struct {
    BangunanTot listbtot;
    int JBang;
    int turn;
    MATRIKS peta;
    Graph Hubungan;
    char lastaction[];
}STATE;

#endif