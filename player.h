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
    boolean AttackUp;
    boolean CriticalHit;
    int playerKe;
} Player;

void InitPlayer(Player * P);
/*I.S Player belom terdefinisi */
/*F.S Player sudah terdefinisi / terinisialisasi */
/* Proses : Inisialisasi dilakukan dengan create empty ListLinier, Queue*/
/*          Selain itu membuant integer tipe bentukan menjadi 0 semua */



#endif