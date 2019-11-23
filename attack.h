//ADT ATTACK

//TUBES ASTRUKDAT
//ADT Tipe Bangunan

#ifndef ATTACK_H
#define ATTACK_H

#include "listlinier.h"
#include "array.h"
#include "boolean.h"
#include <math.h>
#include "graph.h"
#include "player.h"
#include "STATE.h"
#include <stdlib.h>

void MakeEmptyarr (TabInt * T);
void Dealokasiarr(TabInt *T);
void AddAsLastElarr (TabInt * T, int X);
int NbElmtarr (TabInt T);
boolean Searcharr (TabInt T, int X);

address AlokasiLTambahBangunan (BangunanTot *B, IdxType Index);
//Saat ingin Alokasi / Buat List Liniear
//F.S address di BangunanTOt sudah terisi oleh address dari Alokasi Index di List Linier

void AddToLPemain (Player *Pe, Player *Pm, STATE *T,  IdxType Idx, int JPasNetto);
//Bangunan menjadi berubah kepemilikan
//Proses: Misal Bangunan milik P1 baru dikuasai maka LIST L1 berkurang 1  LIST L2 bertambah, Bangunan TOtal tetap
//F.S Bangunan sudah beralih milik dan sudah di RESETBANGUNAN


void MakeBangunanPemain (Player *Pe, Player *Pm, STATE *T, IdxType Idx, int Jmlh, boolean AttackUp);
//INPUTAN Jmlh Awal harus Valid
//Artinya Jmlh harus lebih dari 0 namun harus kurang dari sama dengan JPas Daftar Bangunan


//Mengambil alih bangunan menjadi milik player "PEMAINKE"
//I.S Jmlh adalah JUMLAH PASUKAN Bruto
//Pros Check dahulu dengan IsBangunanNon Jika True, Maka TIDAK ADA RESET KEPEMILIKAN, 
// Search
//F.S Jika jumlah pasukkan kurang (Pe.L1.JPas< Pe.L1.JenisBangunanTot[1].) maka Pe.L1.Jpas-Jmlh dan bangunan tidak diambil alih
//    Jika jumlah pasukkan le

void CetakDaftarBangunan (BangunanTot T, Player Pe, boolean *bol);
//Mencetak daftar bangunan dari pemain ke A atau B
//I.S L adalah List1 YANG SUDAH TERDEFINISI dimana Info(L).Milik='A'

void Attack(Graph G, STATE *T, Player *Pe, Player *Pm, TabInt *Tab,boolean AttackUp);

void UpdateStorageTakNol (Player *Pe, Player *Pm, BangunanTot B);


#endif