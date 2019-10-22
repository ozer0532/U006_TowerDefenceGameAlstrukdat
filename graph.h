/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "point.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define IdxMin 1
#define IdxMax 30

typedef struct {
    int Mem[IdxMax][IdxMax];
    int Neff; /* banyaknya/ukuran baris yg terdefinisi */
} Graph;
/* Jika x = Baris dan y = Kolom, maka Mem[x][y] = 1 menunjukkan bahwa terdapat relasi x->y */

/* *** Selektor *** */
#define Neff(M) (M).Neff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

#define vertex int
#define edge POINT

Graph CreateEmptyGraph (vertex V[], edge E[]);
/* Neff = V.length */
/* Graph berisi matriks adjacency hubungan antar V menurut E */
/* Memori yang dipakai mulai dari indeks 1,1 */

boolean IsEmpty (Graph G);
/* Neff = 0 */

boolean Adjacent (Graph G, vertex v1, vertex v2);
/* Mengetes bila terdapat relas v1->v2 */

boolean Incident (Graph G, vertex v, edge e);
/* Mengetes bila v dan e berhubungan */

vertex * Neighbors (Graph G, vertex v);
/* Mengoutput semua vertex yang merupakan relasi dari v */

/* Gak aku buat karena gak bakal dipake juga...
void AddV (Graph * G, vertex v);

void DeleteV (Graph * G, vertex v);

void AddE (Graph * G, edge e);

void DeleteE (Graph * G, edge e);
*/

#endif
