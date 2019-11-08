# Tubes_Alstrukdat

Tubes Alstrukdat K2

## Cara input ke graph pake sistem macam matriks:

``` c
for (vertex i = 1; i <= Neff(G); i++) {
    for (vertex j = 1; j <= Neff(G); j++) {
        G.Mat[i][j] = ... // Apapun yang pengen dimasukkan
    }
}
```

## Cara cari building yang bersebelahan:

``` c
vertex v; // Index building yang ditinjau
Graph G; // Graph relasi antar building
for (vertex i = 1; i <= Neff(G); i++) {
    if (Adjacent(G, v, i)) {
        // Lakukan sesuatu hal pada building di index i;
    }
}
```

## Things to do

- Print Map
- Print List Bangunan yang masih ada

## Daftar scripts

- Array : Array of bangunan yang ada di lapangan
- Attack : ?
- Bangunan : Ada tipe data komponen (AMPU), tipe data acuan (referensi data), tipe data skill (Queue Player A & B), dan tipe data Bangunan
- Graph : Matriks keterhubungan antar bangunan
- List Linear : List of bangunan yang dimiliki Pemain
- Matriks : ?
- Mesin Input : ?
- Mesin Karakter : Input karakter (?)
- Point : Tipe data koordinat kartesian
- Queue : Queue skill dalam representasi integer (?)
- Skill : Berisi fungsi void tiap skill
- Stack : Tipe data tumpukan state untuk Undo
- State : Berisi tipe data state

## Refactoring yang perlu dilakukan:

- Tipe data player sebaiknya mengandung List bangunan yang dimiliki & queue skill

## Reminder u/ asistensi selanjutnya:
- Tanyain aksi move, kenapa bisa ke tempat musuh