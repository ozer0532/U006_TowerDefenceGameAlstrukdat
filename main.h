#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include "boolean.h"
#include "queue.h"
#include "mesininput.h"
#include "bangunan.h"
#include "listlinier.h"
#include "STATE.h"
#include "stackt.h"
#include "player.h"
#include "attack.h"
#include <string.h>
#include "move.h"


int pemainKe(int x);
/* Mengembalikan pemain yang gilirannya sedang berlangsung */

void levelUp(BangunanTot *T, Player *Pe);
/* I. S. T dan Pe terdefinisi */
/* F. S. Salah satu bangunan dari T yang dimiliki Pe */
/*       levelnya bertambah 1 dan jumlah pasukkannya */
/*       berkurang setengah dari M */

void MovePas(BangunanTot *T, Player *Pe);
// I.S. T dan Pe terdefinisi
// F.S. Sejumlah pasukan pemain di bangunan A pindah ke
//      bangunan B

void AddJumlahPasukan(Player * Pe, BangunanTot * T);
// Menambah jumlah pasukkan
// I.S Player terdefinisi
// F.S Jumlah Pasukkan yang ada diinisialisasikan

void PrintStatus(STATE S, Player * Pe);
//Prosedur untuk mencetak status ke layar
//I.S STATE harus sudah terdefinisi
//F.S Status tercetak kelayar

#endif