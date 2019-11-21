#include "player.h"

void InitPlayer (Player * P) {
    // KAMUS LOKAL

    // ALGORITMA
    CreateEmptyL(&(P -> bangunanPlayer));
    CreateEmptyQ(&(P -> skillQueue), 30);
    P -> shieldCooldown = 0;
    P -> extraTurn = false;
    P -> playerKe = 0;
}