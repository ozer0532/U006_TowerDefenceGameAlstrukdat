#include "mesininput.h"
#include <stdio.h>
#include "bangunan.h"
#include "state.h"
#include "graph.h"
#include <string.h>

boolean EndKata;
Kata CKata;

#define writefile(a) fprintf(f,a)
#define bs(s,j) s.listbtot.TI[i].B.j

/* KONSTRUKTOR */
void CreateKata(Kata *K, char *s){
    int i = 0;
    while(s[i] != '\0'){ /* \0 itu NULL */
        (*K).TabKata[i+1] = s[i];
        i+= 1;
    }
    (*K).Length = i;
}
void BacaKata(Kata *K){
    int pjg;
    char inp;
    pjg=0;
    scanf("%c", &inp);
    while ((inp != ENTER) && (inp != BLANK) && (pjg < NMax)){
        pjg++;
        (*K).TabKata[pjg]=inp;
        scanf("%c", &inp);
    }
    (*K).Length = pjg;
}
void TulisKata (Kata K){
    for (int i = 1; i <= K.Length; i++){
        printf("%c",K.TabKata[i]);
    }
    printf("\n");
}

void IgnoreBlank(){
    while ((CC == '\n' || CC==BLANK) && CC!= MARK) ADV();
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
    IgnoreBlank();
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
  int X,Y;
  char type;
    STARTKATA();
    (*s).peta.NBrsEff = katatoint(CKata)+1;
    TulisKata(CKata);
    ADVKATA();
    TulisKata(CKata);
    (*s).peta.NKolEff = katatoint(CKata)+1;

    makeemptypeta(s);

    ADVKATA();
    TulisKata(CKata);
    (*s).JBang = katatoint(CKata);
    for (int i = 1; i <=(*s).JBang; i++){
        ADVKATA();
        (*s).listbtot.TI[i].B.Jenis = CKata.TabKata[1];
        type = CKata.TabKata[1];
        ADVKATA();
        (*s).listbtot.TI[i].B.Lok.X = katatoint(CKata);
        X = katatoint(CKata);
        ADVKATA();
        (*s).listbtot.TI[i].B.Lok.Y = katatoint(CKata);
        Y = katatoint(CKata);

        (*s).peta.Mem[X][Y].C = type;
        
        (*s).listbtot.TI[i].B.Level = 1;
        
        if (i == 1) {(*s).listbtot.TI[i].B.Milik = 1;}
        else if (i == 2) {(*s).listbtot.TI[i].B.Milik = 2;}
        else {(*s).listbtot.TI[i].B.Milik = 0;}
    }

          (*s).Hubungan.Neff = (*s).JBang;
          for (int i = 1; i <= (*s).Hubungan.Neff; i++) {
              for (int j = 1; j <= (*s).Hubungan.Neff; j++) {
                  (*s).Hubungan.Mem[i][j] = katatoint(CKata);
              }
          }
    for(int j =0; j <= (*s).JBang; j++){
        Elm((*s).peta,(*s).listbtot.TI[j].B.Lok.X,(*s).listbtot.TI[j].B.Lok.Y).p = (*s).listbtot.TI[j].B.Milik;
    }
    strcpy((*s).lastaction,"Load");
}

void SaveFile(STATE s,char nama[]){
  FILE *f;
  f = fopen(nama,"w");
  fprintf(f,"%d %d\n",s.peta.NBrsEff,s.peta.NKolEff);
  writefile(("%d\n",s.JBang));
  for (int i = 1; i <= s.JBang; i ++){
    writefile(("%c %d %d %d %d %d\n",s.listbtot.TI[i].B.Jenis,s.listbtot.TI[i].B.Lok.X,s.listbtot.TI[i].B.Lok.Y,s.listbtot.TI[i].B.Level,s.listbtot.TI[i].B.Milik,s.listbtot.TI[i].B.Jpas));
  }
  for (int i = 1; i <= s.JBang; i ++){
    for (int j = 1; j <= s.JBang; j ++){
      writefile(("%d ",s.listbtot.TI[i].B.hubungan[j]));
    }
    writefile("\n");
  }
  fclose(f);
}

void LoadSafeFile(STATE *s){
  STARTKATA();
    (*s).peta.NBrsEff = katatoint(CKata);
    ADVKATA();
    (*s).peta.NKolEff = katatoint(CKata);
    ADVKATA();
    (*s).JBang = katatoint(CKata);
    char c;
    int x,y,l,j,m;
    for (int i = 1; i <=(*s).JBang; i++){
        ADVKATA();
        c = CKata.TabKata[1];
        ADVKATA();
        x= katatoint(CKata);
        ADVKATA();
        y = katatoint(CKata);
        ADVKATA();
        l = katatoint(CKata);
        ADVKATA();
        m = katatoint(CKata);
        ADVKATA();
        j = katatoint(CKata);
        (*s).listbtot.TI[i].B = MakeBANGUNAN(m,j,l,c,MakePOINT(x,y));
    }

          (*s).Hubungan.Neff = (*s).JBang;
          for (int i = 1; i <= (*s).Hubungan.Neff; i++) {
              for (int j = 1; j <= (*s).Hubungan.Neff; j++) {
                  ADVKATA();
                  (*s).Hubungan.Mem[i][j] = katatoint(CKata);
              }
          }
}


void PrintState(STATE S){
  printf("besar peta %d x %d\n",S.peta.NBrsEff-2,S.peta.NKolEff-2);
  printf("ada %d bangunan : \n",S.JBang);
  for (int i = 1; i <=S.JBang;i++){
    printf("%d. %c di lokasi %d %d level %d milik %d\n",i,S.listbtot.TI[i].B.Jenis,S.listbtot.TI[i].B.Lok.X,S.listbtot.TI[i].B.Lok.Y,S.listbtot.TI[i].B.Level,S.listbtot.TI[i].B.Milik);
  }
}

STATE CopyState(STATE S){
  STATE undo;
  undo = S;
  return undo;
}