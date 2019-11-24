#include "player.h"

void InitPlayer (Player * P) {
/*I.S Player belom terdefinisi */
/*F.S Player sudah terdefinisi / terinisialisasi */
/* Proses : Inisialisasi dilakukan dengan create empty ListLinier, Queue*/
/*          Selain itu membuant integer tipe bentukan menjadi 0 semua */

    // ALGORITMA
    CreateEmptyL(&(P -> bangunanPlayer));
    CreateEmptyQ(&(P -> skillQueue), 30);
    P -> shieldCooldown = 0;
    P -> extraTurn = false;
    P -> playerKe = 0;
}