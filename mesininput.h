/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"
#include "STATE.h"

#define NMax 50
#define BLANK ' '
#define ENTER '\n'

typedef struct {
  char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
  int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
void STARTFILE();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void TulisKata(Kata K);
  /*I.S K terdefinisi
    F.S K dituliskan ke layar pengguna
    MENULIS KATA, PEMAKAIAN LEBIH UNTUK DEBUGGING MESINKATA DKK*/

void STARTKATA();
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */


void STARTKATALOAD();
/*Proses membaca kata dari hasil LoadFile */
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void STARTSTDKATA();
/*UNTUK MEMBACA COMMAND DARI KEYBOARD*/
/* I.S Pita kata terdefinisi */
/* F.S Kata ENTER COMMAND inputan user terbaca dan terdefinisi */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

boolean IsKataSama (Kata K1, Kata K2);

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */



void SaveFile(STATE s, char nama[]);
/*I.S s terdefinisi dan merupakan STATE di tengah permainan
  F.S terbentuk file bernama nama[] yang berisi data dari s*/

void LoadFile(STATE *s);
/*I.S diminta nama file untuk di load
  F.S dibuka pita untuk mengeload dan pita ditempatkan pada karakter pertama file tsb*/
  

void LoadSafeFile(STATE *s);
/*I.S filename yang diminta di STARTKATALOAD() terisi hasil save
  F.S s berisi data STATE permainan sesuai filename*/

void PrintState(STATE S);
/* I.S State belom tercetak ke layar, State terdefinisi */
/* F.S State sudah tercetak ke layar */
/* Spesifikasi state : besar peta, bangunan, lokasi, dan milik */

#endif
