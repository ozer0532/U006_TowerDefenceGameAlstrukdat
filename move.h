#ifndef MOVE_H_
#define MOVE_H_

#include "STATE.h"
#include "attack.h"
#include "player.h"

void move(STATE * S, Player * CP);
// Move digunakan untuk memindahkan pasukan dari suatu bangunan ke bangunan lain milik pemain 
// Adapun bangunan yang bisa dilakukan move adalah bangunan yang terhubung dengan bangunan tersebut. \
// MOVE hanya dapat dilakukan sekali untuk tiap bangunan pada tiap gilirannya
// I.S Move belom dilakukan sama sekali
//     State harus sudah terdefinisi dan terhubung satu sama lainnya
//     Pemain harus terdefinisi
// F.S Melakukan proses move dengan ketentuan diatas
//     Menampilkan ke layar jika move berhasil ataupun jika tidak berhasil

#endif