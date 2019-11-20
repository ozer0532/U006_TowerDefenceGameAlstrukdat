#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

/* Neff = V.length */
/* Graph berisi matriks adjacency hubungan antar V menurut E */
/* Memori yang dipakai mulai dari indeks 1,1 */
Graph CreateEmptyGraph () {
    // KAMUS LOKAL
    Graph G;

    // ALGORITMA
    First(G) = Nil;
    return G;
}

addrRow AlokRow (vertex X) {
    addrRow R;

    R = (addrRow)malloc(sizeof(elmtRow));
    Info(R) = X;
    Branch(R) = Nil;
    Next(R) = Nil;
    return R;
}

addrCol AlokCol (vertex X) {
    addrCol C;

    C = (addrCol)malloc(sizeof(elmtCol));
    Info(C) = X;
    Next(C) = Nil;
    return C;
}

int NbElmtRow (Graph G) {
    int count;
    addrRow R;

    count = 0;
    R = First(G);
    while (R != Nil) {
        R = Next(R);
        count++;
    }
    return count;
}

int NbElmtCol (addrRow R) {
    int count;
    addrCol C;

    count = 0;
    C = Branch(R);
    while (C != Nil) {
        C = Next(C);
        count++;
    }
    return count;
}

void AddElmtG (Graph * G, vertex X) {
    addrRow R;

    if (IsEmptyG(*G)) {
        First(*G) = AlokRow(X);
    } else {
        R = First(*G);
        while (Next(R) != Nil) {
            R = Next(R);
        }
        Next(R) = AlokRow(X);
    }
}

void AddElmtR (addrRow * R, vertex X) {
    addrCol C;

    if (NbElmtCol(*R) == 0) {
        Branch(*R) = AlokCol(X);
    } else {
        C = Branch(*R);
        while (Next(C) != Nil) {
            C = Next(C);
        }
        Next(C) = AlokCol(X);
    }
}

void AddRelation (Graph *G, vertex from, vertex to) {
    addrRow R;
    addrCol C;

    if (IsEmptyG(*G)) {
        R = AlokRow(from);
        First(*G) = R;
    } else {
        R = First(*G);
        while (Next(R) != Nil && Info(R) != from) {
            R = Next(R);
        }
        if (Info(R) != from) {
            Next(R) = AlokRow(from);
            R = Next(R);
        }
    }
    
    if (NbElmtCol(R) == 0) {
        C = AlokCol(to);
        Branch(R) = C;
    } else {
        C = Branch(R);
        while (Next(C) != Nil && Info(C) != to) {
            C = Next(C);
        }
        if (Info(C) != to) {
            Next(C) = AlokCol(to);
        }
    }
}

/* Neff = 0 */
boolean IsEmptyG (Graph G) {
    return NbElmtRow(G) == 0;
}

/* Mengetes bila terdapat relas v1->v2 */
boolean Adjacent (Graph G, vertex v1, vertex v2) {
    addrRow R;
    addrCol C;

    R = First(G);

    while (R != Nil && Info(R) != v1) {
        R = Next(R);
    }

    if (R == Nil) {
        return false;
    } else {
        C = Branch(R);
        while (C != Nil && Info(C) != v2) {
            C = Next(C);
        }

        if (C == Nil) {
            return false;
        } else {
            return true;
        }
    }

}

/* Mengetes bila v dan e berhubungan */
boolean Incident (Graph G, vertex v, edge e) {
    return (v == Absis(e)) || (v == Ordinat(e));
}

/* Mengoutput semua vertex yang merupakan relasi dari v */
addrCol Neighbors (Graph G, vertex v) {
    // KAMUS LOKAL
    addrRow R;

    // ALGORITMA
    R = First(G);
    while (R != Nil && Info(R) != v) {
        R = Next(R);
    }

    if (R == Nil) {
        return Nil;
    } else {
        return Branch(R);
    }
}