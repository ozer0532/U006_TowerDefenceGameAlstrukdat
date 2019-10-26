#include "graph.h"

/* Neff = V.length */
/* Graph berisi matriks adjacency hubungan antar V menurut E */
/* Memori yang dipakai mulai dari indeks 1,1 */
Graph CreateEmptyGraph (vertex V[], edge E[]) {
    // KAMUS LOKAL
    Graph G;
    int i, j;

    // ALGORITMA
    Neff(G) = sizeof(V);
    for (i = 1; i <= Neff(G); i++) {
        for (j = 1; j <= Neff(G); j++) {
            ElmtM(G, i, j) = false;
        }
    }
    for (i = 0; i < sizeof(E); i++) {
        ElmtM(G, Absis(E[i]), Ordinat(E[i])) = true;
        ElmtM(G, Ordinat(E[i]), Absis(E[i])) = true;
    }
    return G;
}

/* Neff = 0 */
boolean IsEmpty (Graph G) {
    return Neff(G) == 0;
}

/* Mengetes bila terdapat relas v1->v2 */
boolean Adjacent (Graph G, vertex v1, vertex v2) {
    return ElmtM(G, v1, v2);
}

/* Mengetes bila v dan e berhubungan */
boolean Incident (Graph G, vertex v, edge e) {
    return (v == Absis(e)) || (v == Ordinat(e));
}

/* Mengoutput semua vertex yang merupakan relasi dari v */
ArrayVertex Neighbors (Graph G, vertex v) {
    // KAMUS LOKAL
    ArrayVertex verts;
    int j = 1;

    // ALGORITMA
    for (int i = 1; i <= IdxMaxG; i++) {
        Elmt(verts, i) = ElUndef;
    }
    for (int i = 1; i <= Neff(G); i++) {
        if (Adjacent(G, v, ElmtM(G, v, i))) {
            Elmt(verts, j) = i;
            j++;
        }
    }

    return verts;
}