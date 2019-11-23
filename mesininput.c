#include "mesininput.h"
#include <stdio.h>
#include "bangunan.h"
#include "state.h"
#include "graph.h"
#include <string.h>
#include "listlinier.h"

boolean EndKata;
Kata CKata;

#define bs(s,j) s.listbtot.TI[i].B.j

/* KONSTRUKTOR */
void TulisKata (Kata K){
  /*I.S K terdefinisi
    F.S K dituliskan ke layar pengguna
    MENULIS KATA, PEMAKAIAN LEBIH UNTUK DEBUGGING MESINKATA DKK*/
    for (int i = 1; i <= K.Length; i++){
        printf("%c",K.TabKata[i]);
    }
    printf("\n");
}

void IgnoreBlank(){
  /* I.S Pita bisa berada pada manapun yang bukan MARK 
     F.S Pita berada pada cc yang bukan ENTER maupun BLANK*/
    while ((CC == '\n' || CC==BLANK) && CC!= MARK) ADV();
}


void STARTSTDKATA(){
  /*UNTUK MEMBACA COMMAND DARI KEYBOARD*/
    STARTSTD();
    if (CC == MARK) EndKata = true;
    else
    {
      EndKata = false;
      SalinKata();
    }
}

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
  // KAMUS LOKAL

  // ALGORITMA
    START();
    if (CC == MARK) EndKata = true;
    else
    {
      EndKata = false;
      SalinKata();
    }
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
 // KAMUS LOKAL

 // ALGORITMA
    IgnoreBlank();
    if (CC == MARK) EndKata = true;
    else SalinKata();
    IgnoreBlank();
}

boolean IsKataSama (Kata K1, Kata K2)
/*  Mengembalikan true jika K1 = K2; dua kata dikatakan sama jika panjangnya sama 
  dan urutan karakter yang menyusun kata juga sama */
{
  /*  KAMUS LOKAL */
  int i;

  /*  ALGORITMA */
  if (K1.Length==K2.Length) 
  {
    i = 1;
    while ((i<K1.Length)&&(K1.TabKata[i]==K2.TabKata[i])) 
    {
      i++;
    }
    return (K1.TabKata[i]==K2.TabKata[i]);
  } 
  else 
  {
    return (K1.Length==K2.Length);
  }
}

int katatoint(Kata K){
  /*Mereturn nilai K berupa integer, karena isi dari Kata adalah char sehingga tidak bisa langsung diproses sebagai integer*/
    int bil=0;
    for (int i=1; i<=K.Length;i++){
      switch (K.TabKata[i]){
        case '1': bil = bil*10 + 1;break;
        case '2': bil = bil*10 + 2;break;
        case '3': bil = bil*10 + 3;break;
        case '4': bil = bil*10 + 4;break;
        case '5': bil = bil*10 + 5;break;
        case '6': bil = bil*10 + 6;break;
        case '7': bil = bil*10 + 7;break;
        case '8': bil = bil*10 + 8;break;
        case '9': bil = bil*10 + 9;break;
        default : bil = bil*10;break;
      }
    }
    return bil;
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
  // KAMUS LOKAL
    int i;

  // ALGORITMA
    i = 1;
    while ((CC != MARK) &&  (CC != BLANK) && (CC != '\n') && i <= NMax)
    {
      CKata.TabKata[i] = CC;
      ADV();
      i++;
    }
    CKata.Length = i - 1;
}

void LoadFile(STATE *s){
  /*I.S STATE s kosong
    F.S isi STATE s sesuai file konfigurasi*/
  int X,Y;
  ACUAN Ac;
  Inisialisasi(&Ac);

  char type;
  Graph G;
  ACUAN A;

    Inisialisasi(&A);
    s->P1.playerKe = 1;
    s->P2.playerKe = 2;
    STARTKATA();
    (*s).peta.NBrsEff = katatoint(CKata)+1;
    ADVKATA();
    (*s).peta.NKolEff = katatoint(CKata)+1;
    makeemptypeta(s);
    MakeEmptyBangunanTot(&(*s).listbtot);
    ADVKATA();
    (*s).JBang = katatoint(CKata);
    for (int i = 1; i <=(*s).JBang; i++){
        ADVKATA();
        s->listbtot.TI[i].B.Jenis = CKata.TabKata[1];
        type = CKata.TabKata[1];
        ADVKATA();
        (*s).listbtot.TI[i].B.Lok.X = katatoint(CKata);
        X = katatoint(CKata);
        ADVKATA();
        (*s).listbtot.TI[i].B.Lok.Y = katatoint(CKata);
        Y = katatoint(CKata);

        (*s).peta.Mem[X][Y].C = type;
        
        (*s).listbtot.TI[i].B.Level = 1;
        (*s).listbtot.TI[i].B.Jpas = getU((*s).listbtot.TI[i].B,Ac);
        //(*s).listbtot.TI[i].B.Jpas = CariDariAcuan(A, type, 0, 'U');
        
        if (i == 1) {
          (*s).listbtot.TI[i].B.Milik = 1;
          InsVLastL(&(s->P1.bangunanPlayer), i);
        }
        else if (i == 2) {
          (*s).listbtot.TI[i].B.Milik = 2;
          InsVLastL(&(s->P2.bangunanPlayer), i);
        }
        else {(*s).listbtot.TI[i].B.Milik = 0;}
    }
    s -> Hubungan = CreateEmptyGraph();
    for (int i = 1; i <= (*s).JBang; i++) {
        for (int j = 1; j <= (*s).JBang; j++) {
            ADVKATA();
            if(katatoint(CKata) == 1) AddRelation(&(s->Hubungan),i,j);
        }
    }
    for(int j =0; j <= (*s).JBang; j++){
        (*s).peta.Mem[(*s).listbtot.TI[j].B.Lok.X][(*s).listbtot.TI[j].B.Lok.Y].p = (*s).listbtot.TI[j].B.Milik;
    }
}

void SaveFile(STATE s,char nama[]){
  /*I.S s terdefinisi dan merupakan STATE di tengah permainan
    F.S terbentuk file bernama nama[] yang berisi data dari s*/
  FILE *f;
  f = fopen(nama,"w");
  fprintf(f,"%d %d\n",s.peta.NBrsEff,s.peta.NKolEff);
  fprintf(f, "%d\n",s.JBang);
  for (int i = 1; i <= s.JBang; i ++){
    fprintf(f, "%c %d %d %d %d %d\n",s.listbtot.TI[i].B.Jenis,s.listbtot.TI[i].B.Lok.X,s.listbtot.TI[i].B.Lok.Y,s.listbtot.TI[i].B.Level,s.listbtot.TI[i].B.Milik,s.listbtot.TI[i].B.Jpas);
  }
  int temp;
  while (IsEmptyQ(s.P1.skillQueue) == false){
    DelQ(&(s.P1.skillQueue),&temp);
    fprintf(f,"%d ",temp);
  }
  fprintf(f," !\n");
  while (IsEmptyQ(s.P2.skillQueue) == false){
    DelQ(&(s.P2.skillQueue),&temp);
    fprintf(f,"%d ",temp);
  }
  fprintf(f," !\n");
  addrRow G;  
  G = s.Hubungan.First;
  addrCol GN;
  while(G!=Nil){
     fprintf(f,"%d ",G->info);
     GN = G->branch;
     while (GN != Nil){
       fprintf(f,"%d ",GN->info);
       GN = Next(GN);
     }
      fprintf(f,"!\n");
      G = Next(G);
  }
  fprintf(f,"   .");
 
  fclose(f);
}

void STARTKATALOAD(){
  /*I.S diminta nama file untuk di load
    F.S dibuka pita untuk mengeload dan pita ditempatkan pada karakter pertama file tsb*/
    char filename[30];
    printf("Masukkan nama file untuk di load : ");scanf("%s",&filename);
    STARTLOAD(filename);
    IgnoreBlank();
    if (CC == MARK) EndKata = true;
    else
    {
      EndKata = false;
      SalinKata();
    }
}
void LoadSafeFile(STATE *s){
  /*I.S filename yang diminta di STARTKATALOAD() terisi hasil save
    F.S s berisi data STATE permainan sesuai filename*/
    STARTKATALOAD();
    CreateEmptyQ(&(s->P1.skillQueue),10);
    CreateEmptyQ(&(s->P1.skillQueue),10);
    s->P1.playerKe = 1;
    s->P2.playerKe = 2;
    (*s).peta.NBrsEff = katatoint(CKata);
    ADVKATA();
    (*s).peta.NKolEff = katatoint(CKata);
    ADVKATA();
    (*s).JBang = katatoint(CKata);
    makeemptypeta(s);
    char c;
    int x,y,l,j,m;
    MakeEmptyBangunanTot(&(s->listbtot));
    for (int i = 1; i <=(*s).JBang; i++){
        ADVKATA();
        c = CKata.TabKata[1];
        s->listbtot.TI[i].B.Jenis = c;
        ADVKATA();
        x= katatoint(CKata);
        s->listbtot.TI[i].B.Lok.X = x;
        ADVKATA();
        y = katatoint(CKata);
        s->listbtot.TI[i].B.Lok.Y = y;
        ADVKATA();
        l = katatoint(CKata);
        s->listbtot.TI[i].B.Level = l;
        ADVKATA();
        m = katatoint(CKata);
        s->listbtot.TI[i].B.Milik = m;
        ADVKATA();
        j = katatoint(CKata);
        (*s).peta.Mem[(*s).listbtot.TI[i].B.Lok.X][(*s).listbtot.TI[i].B.Lok.Y].C = c;
        s->listbtot.TI[i].B.Jpas = j;
        // (*s).listbtot.TI[i].B = MakeBANGUNAN(m,j,l,c,MakePOINT(x,y));
        if (m == 1) InsVLastL(&(s->P1.bangunanPlayer),i);
        else if (m == 2) InsVLastL(&(s->P2.bangunanPlayer),i);
    }
    ADVKATA();
    while(CKata.TabKata[1] != '!'){
        AddQ(&(s->P1.skillQueue),katatoint(CKata));
        ADVKATA();
    }
    ADVKATA();
    while(CKata.TabKata[1] != '!'){
        AddQ(&(s->P2.skillQueue),katatoint(CKata));
        ADVKATA();
    }

    for(int j =0; j <= (*s).JBang; j++){
        (*s).peta.Mem[(*s).listbtot.TI[j].B.Lok.X][(*s).listbtot.TI[j].B.Lok.Y].p = (*s).listbtot.TI[j].B.Milik;
    }
    
    int i ,je;
    s->Hubungan = CreateEmptyGraph();
    ADVKATA();
    while (EndKata == false){
      i = katatoint(CKata);
      AddElmtG(&(*s).Hubungan,i);
      ADVKATA();
      while(CKata.TabKata[1] != '!'){
        je = katatoint(CKata);
        AddRelation(&((*s).Hubungan),i,je);
        ADVKATA();
      }
    ADVKATA();
    }
}


void PrintState(STATE S){
  printf("besar peta %d x %d\n",S.peta.NBrsEff-2,S.peta.NKolEff-2);
  printf("ada %d bangunan : \n",S.JBang);
  for (int i = 1; i <=S.JBang; i++){
    printf("%d. %c di lokasi %d %d level %d milik %d\n",i,S.listbtot.TI[i].B.Jenis,S.listbtot.TI[i].B.Lok.X,S.listbtot.TI[i].B.Lok.Y,S.listbtot.TI[i].B.Level,S.listbtot.TI[i].B.Milik);
  }
} 

STATE CopyState(STATE S){
  STATE undo;
  undo = S;
  return undo;
}