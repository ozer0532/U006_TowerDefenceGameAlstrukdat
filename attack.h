//ADT ATTACK

//TUBES ASTRUKDAT
//ADT Tipe Bangunan

#ifndef ATTACK_H
#define ATTACK_H

#include "listlinier.h"
#include "array.h"
#include "boolean.h"

void PrintDaftarBangunan1 (Pemain Pe);
//Mencetak daftar bangunan dari pemain 1
//I.S L adalah List1 YANG SUDAH TERDEFINISI dimana Info(L).Milik='A'


void PrintDaftarBangunan2 (Pemain Pe);


boolean IsBangunanNon (Point Po, BangunanTot B);
//True jika ada di bangunantot atau bangunan belom dikuasai siapa2

void ResetKepemilikan (Pemain *Pe, Point Po);
//I.S Masukkan saat Tidak IsBangunanNon dan MakeBangunanPemain1 / 2
//F.S Level bangunan akan berpindah menjadi 1

void MakeBangunanPemain1 (Pemain *Pe, BangunanTot *B, POINT Po, int Jmlh);
//Mengambil alih bangunan menjadi milik player pertama
//I.S Masukan berupa jenis bangunan yang akan diambil alih(Po.x,Po.y) dan Jmlh adalah jumlah pasukan
//Pros Check dahulu dengan IsBangunanNon(Po,*B) Jika True, Maka TIDAK ADA RESET KEPEMILIKAN
//F.S Jika jumlah pasukkan kurang (Pe.L1.JPas< Pe.L1.Jns) maka Pe.L1.Jpas-Jmlh dan bangunan tidak diambil alih
//    Jika jumlah pasukkan le

void MakeBangunanPemain1 (Pemain *Pe, BangunanTot *B);


void UpdateBangunan (List1 *L1, List2 *L2, BangunanTot *PTot);
//Membuat Bangunan menjadi berubah kepemilikan
//Proses: Misal Bangunan milik P1 baru dikuasai maka LIST L1 berkurang 1  LIST L2 bertambah, Bangunan TOtal tetap
#endif