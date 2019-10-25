//ADT ATTACK

//TUBES ASTRUKDAT
//ADT Tipe Bangunan

#ifndef ATTACK_H
#define ATTACK_H

#include "listlinier.h"
#include "array.h"
#include "boolean.h"


void CetakDaftarBangunan (Pemain Pe, int PEMAINKE);
//Mencetak daftar bangunan dari pemain ke A atau B
//I.S L adalah List1 YANG SUDAH TERDEFINISI dimana Info(L).Milik='A'

address SearchPOINT (List L, POINT Po);

void MakeBangunanPemain (Pemain *Pe, BangunanTot *B, POINT Po, int PEMAINKE, int Jmlh);
//Mengambil alih bangunan menjadi milik player "PEMAINKE"
//I.S Masukan berupa jenis bangunan yang akan diambil alih(Po.x,Po.y) dan Jmlh adalah jumlah pasukan
//Pros Check dahulu dengan IsBangunanNon(Po,*B) Jika True, Maka TIDAK ADA RESET KEPEMILIKAN, 
// Search
//F.S Jika jumlah pasukkan kurang (Pe.L1.JPas< Pe.L1.JenisBangunanTot[1].) maka Pe.L1.Jpas-Jmlh dan bangunan tidak diambil alih
//    Jika jumlah pasukkan le



void UpdateBangunan (Pemain *Pe, BangunanTot *B,  POINT Po, int PEMAINKE, int Jmlh);
//Bangunan menjadi berubah kepemilikan
//Proses: Misal Bangunan milik P1 baru dikuasai maka LIST L1 berkurang 1  LIST L2 bertambah, Bangunan TOtal tetap
//F.S Bangunan sudah beralih milik dan sudah di RESETBANGUNAN
#endif