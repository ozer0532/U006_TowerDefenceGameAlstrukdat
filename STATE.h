#ifndef STATE_H
#define STATE_H

#include "array.h"
#include "bangunan.h"
#include "mesinkar.h"
#include "mesinkata.h"


typedef struct {
    BangunanTot listbtot;
    int JBang;
    int turn;
    SKILL S;
    MATRIKS peta;
}STATE;

#endif