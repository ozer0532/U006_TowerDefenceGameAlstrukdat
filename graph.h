/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "point.h"
#include "array.h"

#define vertex int
#define edge POINT

//Pendefinisian tipe bentukan
typedef struct tElmtRow * addrRow;
typedef struct tElmtCol * addrCol;

typedef struct tElmtRow {
    vertex info;
    addrCol branch;
    addrRow next;
} elmtRow;

typedef struct tElmtCol{
    vertex info;
    addrCol next;
} elmtCol;

typedef struct {
    addrRow First;
} Graph;

typedef struct {
    vertex TI[31];
    int Neff;
} ArrayVertex;

#define Branch(P) (P)->branch

/* *** Selektor *** */
#define Neff(M) (M).Neff
#define ElmtM(M,i,j) (M).Mem[(i)][(j)]

//Inisialisasi Awal
Graph CreateEmptyGraph ();
/* Neff = V.length */
/* Graph berisi matriks adjacency hubungan antar V menurut E */
/* Memori yang dipakai mulai dari indeks 1,1 */

addrRow AlokRow (vertex X);
//Address untuk Row belom terdefinisi awalnya
//addrRow sudah terdefinisi lewat AlokRow

addrCol AlokCol (vertex X);
//Address untuk Col belom terdefinisi awalnya
//addrRow sudah terdefinisi lewat AlokCol

int NbElmtRow (Graph G);
/* Mengirimkan banyaknya row graph; mengirimkan 0 jika list kosong */

int NbElmtCol (addrRow R);
/* Mengirimkan banyaknya column row; mengirimkan 0 jika list kosong */

void AddElmtG (Graph * G, vertex X);
/* I.S. G terdefinisi */
/* F.s. X ditambahkan di akhir list graph G */

void AddElmtR (addrRow * R, vertex X);
/* I.S. R terdefinisi */
/* F.s. X ditambahkan di akhir list row R */

void AddRelation (Graph * G, vertex from, vertex to);
/* Belom ada relasi dalam graph*/
/* Graph sudah terdefinisi dengan relasi yang ada dalam graph*/

boolean IsEmptyG (Graph G);
/* Akan mengembalikan true jika Neff = 0 */
/* False untuk sebaliknya */

boolean Adjacent (Graph G, vertex v1, vertex v2);
/* Mengetes bila terdapat relasi v1->v2 */

boolean Incident (Graph G, vertex v, edge e);
/* Mengetes bila v dan e berhubungan */
/* Akan mengembalikan true jika v dan e saling berelasi/berhubungan*/

addrCol NeighborsList (Graph G, vertex v);
/* Mengoutput semua vertex yang merupakan relasi dari v */

ArrayVertex Neighbors (Graph G, vertex v);
/* Mengoutput semua vertex yang merupakan relasi dari v */

#endif
