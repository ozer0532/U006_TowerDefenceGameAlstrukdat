#ifndef PLAYER_H
#define PLAYER_H

#include "queue.h"
#include "listlinier.h"
#include "boolean.h"

typedef struct
{
    List bangunanPlayer;
    Queue skillQueue;
    int shieldCooldown;
    boolean extraTurn;
    int playerKe;
} Player;


#endif