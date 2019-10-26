#include "mesinkata.h"
#include <stdio.h>
#include "bangunan.h"

boolean EndKata;
Kata CKata;

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
    for (int i; i<=K.Length;i++){
        bil = bil*10 + ((int) (K.TabKata[i] - '0'));
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
    while ((CC != MARK) &&  (CC != BLANK) && i <= NMax)
    {
      CKata.TabKata[i] = CC;
      ADV();
      i++;
    }
    CKata.Length = i - 1;
}

void SalinInput(STATE *s){
    int part = 1;
    STARTKATA();
    (*s).peta.NBrsEff = katatoint(CKata);
    ADVKATA();
    (*s).peta.NKolEff = katatoint(CKata);
    ADVKATA();
    (*s).JBang = katatoint(CKata);
    for (int i = 1; i <=(*s).JBang; i++){
        ADVKATA();
        (*s).listbtot.TI[i].B.Jenis = CKata.TabKata[1];
        ADVKATA();
        (*s).listbtot.TI[i].B.Lok.X = katatoint(CKata);
        ADVKATA();
        (*s).listbtot.TI[i].B.Lok.Y = katatoint(CKata);
        
        (*s).listbtot.TI[i].B.Level = 1;
        
        if (i == 1) {(*s).listbtot.TI[i].B.Milik = 'A';}
        else if (i == 2) {(*s).listbtot.TI[i].B.Milik = 'B';}
        else {(*s).listbtot.TI[i].B.Milik = 'X';}

        // switch ((*s).listb[i].jenis){
        //     case 'C':
        //         (*(*s).listb).A[5] = {0,10,15,20,25};
        //         (*(*s).listb).M = {0,40,60,80,100};
        //         (*(*s).listb).P = {false,false,false,false,false};
        //         (*(*s).listb).U = 40;
        //         break;
        //     case 'T':
        //         (*(*s).listb).A = {0,5,10,20,30};
        //         (*(*s).listb).M = {0,20,30,40,50};
        //         (*(*s).listb).P = {true,true,true,true,true};
        //         (*(*s).listb).U = 30;
        //         break;                             //ga perlu karna gw udh ngerti acuan yang make JNS
        //     case 'F':
        //         (*(*s).listb).A = {0,10,20,30,40};
        //         (*(*s).listb).M = {0,20,40,60,80};
        //         (*(*s).listb).P = {false,false,false,true,true};
        //         (*(*s).listb).U = 80;
        //         break;
        //     case 'V':
        //         (*(*s).listb).A = {0,5,10,15,20};
        //         (*(*s).listb).M = {0,20,30,40,50};
        //         (*(*s).listb).P = {false,false,false,false,false};
        //         (*(*s).listb).U = 20;
        //         break;
        //     default:
        //       break;
        // }
    }

    for (int j = 1; j <= (*s).peta.NBrsEff; j++){
        for (int k =1; k <= (*s).peta.NKolEff; k ++){
          ADVKATA();
          (*s).listbtot.TI[j].B.hubungan[k] = katatoint(CKata);
        }
    }

}


STATE CopyState(STATE S){
  STATE undo;
  undo = S;
  return undo;
}