//ADT ATTACK

//TUBES ASTRUKDAT
//ADT Tipe Bangunan

#ifndef ATTACK_H
#define ATTACK_H

#include "listlinier.h"
#include "array.h"
#include "boolean.h"

address AlokasiLTambahBangunan (BangunanTot *B, IdxType Index);
//Saat ingin Alokasi / Buat List Liniear
//F.S address di BangunanTOt sudah terisi oleh address dari Alokasi Index di List Linier

void AddToLPemain (Pemain *Pe, BangunanTot *B,  IdxType Idx, int PEMAINKE, int JPasNetto);
//Bangunan menjadi berubah kepemilikan
//Proses: Misal Bangunan milik P1 baru dikuasai maka LIST L1 berkurang 1  LIST L2 bertambah, Bangunan TOtal tetap
//F.S Bangunan sudah beralih milik dan sudah di RESETBANGUNAN


void MakeBangunanPemain (Pemain *Pe, BangunanTot *B, IdxType Idx, int PEMAINKE, int Jmlh);
//Mengambil alih bangunan menjadi milik player "PEMAINKE"
//I.S Jmlh adalah JUMLAH PASUKAN Bruto
//Pros Check dahulu dengan IsBangunanNon Jika True, Maka TIDAK ADA RESET KEPEMILIKAN, 
// Search
//F.S Jika jumlah pasukkan kurang (Pe.L1.JPas< Pe.L1.JenisBangunanTot[1].) maka Pe.L1.Jpas-Jmlh dan bangunan tidak diambil alih
//    Jika jumlah pasukkan le

void CetakDaftarBangunan (Pemain Pe, int PEMAINKE);
//Mencetak daftar bangunan dari pemain ke A atau B
//I.S L adalah List1 YANG SUDAH TERDEFINISI dimana Info(L).Milik='A'

address SearchPOINT (List L, POINT Po);


#endif
