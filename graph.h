/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "graph.h"
#include "point.h"
#include "array.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define IdxMin 1
#define IdxMaxG 30

typedef struct {
    boolean Mem[IdxMaxG][IdxMaxG];
    int Neff; /* banyaknya/ukuran baris yg terdefinisi */
} Graph;
/* Jika x = Baris dan y = Kolom, maka Mem[x][y] = 1 menunjukkan bahwa terdapat relasi x->y */

typedef struct {
    boolean TI[IdxMaxG+1];
} ArrayVertex;

/* *** Selektor *** */
#define Neff(M) (M).Neff
#define ElmtM(M,i,j) (M).Mem[(i)][(j)]

#define vertex int
#define edge POINT

Graph CreateEmptyGraph (vertex V[], edge E[]);
/* Neff = V.length */
/* Graph berisi matriks adjacency hubungan antar V menurut E */
/* Memori yang dipakai mulai dari indeks 1,1 */

boolean IsEmptyGR (Graph G);
/* Neff = 0 */

boolean Adjacent (Graph G, vertex v1, vertex v2);
/* Mengetes bila terdapat relas v1->v2 */
/* Mengouput nilai ElmtM(G, v1, v2); */

boolean Incident (Graph G, vertex v, edge e);
/* Mengetes bila v dan e berhubungan */

ArrayVertex Neighbors (Graph G, vertex v);
/* Mengoutput semua vertex yang merupakan relasi dari v */

/* Gak aku buat karena gak bakal dipake juga...
void AddV (Graph * G, vertex v);

void DeleteV (Graph * G, vertex v);

void AddE (Graph * G, edge e);

void DeleteE (Graph * G, edge e);
*/

#endif
