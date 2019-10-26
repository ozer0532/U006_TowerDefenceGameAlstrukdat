# Tubes_Alstrukdat
Tubes Alstrukdat K2


### Cara input ke graph pake sistem macam matriks:
```
for (vertex i = 1; i <= Neff(G); i++) {
    for (vertex j = 1; j <= Neff(G); j++) {
        G.Mat[i][j] = ... // Apapun yang pengen dimasukkan
    }
}

```
### Cara cari building yang bersebelahan:
``` 
vertex v; // Index building yang ditinjau
Graph G; // Graph relasi antar building
for (vertex i = 1; i <= Neff(G); i++) {
    if (Adjacent(G, v, i)) {
        // Lakukan sesuatu hal pada building di index i;
    }
}
```