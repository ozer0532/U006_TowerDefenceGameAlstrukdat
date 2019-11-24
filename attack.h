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
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

void Dealokasiarr(TabInt *T);
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

void AddAsLastElarr (TabInt * T, int X);
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */

int NbElmtarr (TabInt T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

boolean Searcharr (TabInt T, int X);
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */

address AlokasiLTambahBangunan (BangunanTot *B, IdxType Index);
//Saat ingin Alokasi tambah isi List Bangunan milik pemain
//I.S List Bangunan sudah terdefinisi milik pemain
//F.S Bangunan pemain bertambah yang ditujukkan dengan 
//1. Pertambahan List milik pemain
//2. address di BangunanTOt sudah terisi oleh address dari Alokasi Index di List Linier

void AddToLPemain (Player *Pe, Player *Pm, STATE *T,  IdxType Idx, int JPasNetto);
//Bangunan menjadi berubah kepemilikan
//Proses: Misal Bangunan milik P1 baru dikuasai maka LIST pemain 1 berkurang 1  LIST L2 bertambah, Bangunan TOtal tetap
//Sedangkan jika Bangunan tidak berpemilik, maka akan mengubah di Array Bangunan Tot kepemilikan dimana dari 0(tak berpemilik) jadi berpemilik
//I.S Player terdefinisi dan Jumlah Pasukkan yang akan dimasukkan ke list pemain sudah Jumlah Pasukkan bersih/netto
//Artinya sudah dikurangkan dengan Jumlah pasukkan awal di bangunan (lewat prosedur MakeBangunanPemain)
//F.S Bangunan sudah beralih milik dan sudah di RESETBANGUNAN

void MakeBangunanPemain (Player *Pe, Player *Pm, STATE *T, IdxType Idx, int Jmlh, boolean AttackUp);
//INPUTAN Jmlh Awal harus Valid
//Artinya Jmlh harus lebih dari 0 namun harus kurang dari sama dengan JPas Daftar Bangunan
//Mengambil alih bangunan menjadi milik player sekarang
//I.S Jmlh adalah JUMLAH PASUKAN Bruto
//Prosesnya adalah mengolah Jumlah pasukkan
//Jika IsPertahanan nya True maka pengurangan jumlah pasukkan hanya akan sebesar 3/4
//Jika tidak maka Jumlah pengurangannyaa akan sama dengan jumlah pasukkan yang akan masuk
//F.S Jika jumlah pasukkan kurang (Pe.L1.JPas< Pe.L1.JenisBangunanTot[1].) maka Pe.L1.Jpas-Jmlh dan bangunan tidak diambil alih
//    Jika jumlah pasukkan lebih maka bangunan akan berhasil terebut
//    Jika Jumlah pasukan lebih namun sudah melebihi nilai M atau batas Maks maka pasukkan selebihnya akan diabaikan

void CetakDaftarBangunan (BangunanTot T, Player Pe, boolean *bol);
//Mencetak daftar bangunan dari pemain ke A atau B
//I.S L adalah List1 YANG SUDAH TERDEFINISI 
//F.S Tercetak ke layar status dari Bangunan yang dimiliki oleh Player

void Attack(Graph G, STATE *T, Player *Pe, Player *Pm, TabInt *Tab,boolean AttackUp);
//Melakukan serangan ke musuh
//I.S Attack belom terdefinisi sama sekali
//F.S ditampilkan kelayar status player dengan CetakDaftar Bangunan
//    Sudah Memanggil MakeBangunanPemain untuk melakukan mekanisme ambil alih
//    Sudah Mengurangkan pasukkan di bangunan awal


#endif