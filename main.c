#include <stdio.h>
#include "boolean.h"
#include "queue.h"
#include "mesininput.h"
#include "bangunan.h"
#include "listlinier.h"
#include "STATE.h"
#include "stackt.h"
#include "player.h"
#include "attack.h"
#include <string.h>
#include "move.h"

int pemainKe(int x)
/* Mengembalikan pemain yang gilirannya sedang berlangsung */
{
    // KAMUS LOKAL

    // ALGORITMA
        if (x % 2 == 1)
            return 1;
        else
            return 2;
}

void levelUp(BangunanTot *T, Player *Pe)
/* I. S. T dan Pe terdefinisi */
/* F. S. Salah satu bangunan dari T yang dimiliki Pe */
/*       levelnya bertambah 1 dan jumlah pasukkannya */
/*       berkurang setengah dari M */
{
    // KAMUS LOKAL
      address P;
      int pilih, n, pas, lvl;
      ACUAN Ac;
      char jns;
      int M;
      boolean bol;

    // ALGORITMA
      Inisialisasi(&Ac);
      n = 1;
      P = First((*Pe).bangunanPlayer);
      CetakDaftarBangunan(*T, *Pe,&bol);
      printf("Bangunan yang akan di level up: ");scanf("%d", &pilih);

      while (n != pilih)
      {
          P = Next(P);
          n++;
      }

      pas = (*T).TI[Info(P)].B.Jpas;
      jns = (*T).TI[Info(P)].B.Jenis;
      lvl = (*T).TI[Info(P)].B.Level;

      M = CariDariAcuan(Ac, jns, lvl, 'M');
      if (pas >= (M/2))
      {
          (*T).TI[Info(P)].B.Level++;
          (*T).TI[Info(P)].B.Jpas -= M / 2;

          if (jns == 'C')
              printf("Level Castle-mu meingkat menjadi %d!\n", (*T).TI[Info(P)].B.Level);
          else if (jns == 'F')
              printf("Level Fort-mu meingkat menjadi %d!\n", (*T).TI[Info(P)].B.Level);
          else if (jns == 'T')
              printf("Level Tower-mu meingkat menjadi %d!\n", (*T).TI[Info(P)].B.Level);
          else if (jns == 'V')
              printf("Level Village-mu meingkat menjadi %d!\n", (*T).TI[Info(P)].B.Level);
      }
      else
      {
          if (jns == 'C')
             printf("Jumlah Pasukan Castle kurang untuk level up\n");
          else if (jns == 'F')
             printf("Jumlah Pasukan Fort kurang untuk level up\n");
          else if (jns == 'T')
             printf("Jumlah Pasukan Tower kurang untuk level up\n");
          else if (jns == 'V')
             printf("Jumlah Pasukan Village kurang untuk level up\n");
      }
}

void MovePas(BangunanTot *T, Player *Pe)
// I.S. T dan Pe terdefinisi
// F.S. Sejumlah pasukan pemain di bangunan A pindah ke
//      bangunan B
{
    // KAMUS LOKAL
        int pilih;
        ACUAN Ac;
        address P;
        boolean bol;

    // ALGORITMA
        Inisialisasi(&Ac);
        P = First((*Pe).bangunanPlayer);

        CetakDaftarBangunan(*T, *Pe,&bol);
        printf("Pilih bangunan:");scanf("%d", &pilih);


}


void AddJumlahPasukan(Player * Pe, BangunanTot * T) {
    // KAMUS LOKAL
    address P;
    ACUAN A;
    BANGUNAN * B;

    // ALGORITMA
    Inisialisasi(&A);
    P = First(Pe -> bangunanPlayer);
    while (P != Nil) {
        B = &(T->TI[Info(P)].B);
        B -> Jpas += CariDariAcuan(A, B -> Jenis, B -> Level, 'A');
        if (B -> Jpas > CariDariAcuan(A, B -> Jenis, B -> Level, 'M')) {
            B -> Jpas = CariDariAcuan(A, B -> Jenis, B -> Level, 'M');
        }
        P = Next(P);
    }
}

void PrintStatus(STATE S, Player * Pe) {
    printf("\n\n\n\n\n");
    boolean(bol);
    printpeta(S);
    printf("Player %d\n", Pe -> playerKe);
    CetakDaftarBangunan(S.listbtot, *Pe, &bol);
    printf("Skill Available: ");
    int SkillKe=Head((*Pe).skillQueue);    
    if (SkillKe==1) {   
        printf("Instant Upgrade\n");
    }
    else if(SkillKe == 2){
        printf("Shield\n");
    }
    else if(SkillKe == 3){
        printf("Extra Turn\n");
    }
    else if(SkillKe == 4){
        printf("Attack Up\n");
    }
   else if(SkillKe == 5){
        printf("Critical Hit\n");
    }
    else if(SkillKe == 6){
        printf("Instant Reinforcement\n");
    }
    else if(SkillKe == 7){
        printf("Barrage\n");
    }
    else {
        printf("Tidak ada Skill\n");
    }
    }

int main()
{
    // KAMUS
      /* Konstanta */
        Kata Attk, Lvup, Skll, Exit, Undo, Endt, Save, Move;
        Lvup.TabKata[1] = 'L';  Endt.TabKata[1] = 'E';
        Lvup.TabKata[2] = 'E';  Endt.TabKata[2] = 'N';
        Lvup.TabKata[3] = 'V';  Endt.TabKata[3] = 'D';
        Lvup.TabKata[4] = 'E';  Endt.TabKata[4] = '_';
        Lvup.TabKata[5] = 'L';  Endt.TabKata[5] = 'T';
        Lvup.TabKata[6] = '_';  Endt.TabKata[6] = 'U';
        Lvup.TabKata[7] = 'U';  Endt.TabKata[7] = 'R';
        Lvup.TabKata[8] = 'P';  Endt.TabKata[8] = 'N';
        Lvup.Length = 8;        Endt.Length = 8;

        Attk.TabKata[1] = 'A';  Skll.TabKata[1] = 'S';
        Attk.TabKata[2] = 'T';  Skll.TabKata[2] = 'K';
        Attk.TabKata[3] = 'T';  Skll.TabKata[3] = 'I';
        Attk.TabKata[4] = 'A';  Skll.TabKata[4] = 'L';
        Attk.TabKata[5] = 'C';  Skll.TabKata[5] = 'L';
        Attk.TabKata[6] = 'K';
        Attk.Length = 6;        Skll.Length = 5;

        Exit.TabKata[1] = 'E';  Undo.TabKata[1] = 'U';
        Exit.TabKata[2] = 'X';  Undo.TabKata[2] = 'N';
        Exit.TabKata[3] = 'I';  Undo.TabKata[3] = 'D';
        Exit.TabKata[4] = 'T';  Undo.TabKata[4] = 'O';
        Exit.Length = 4;        Undo.Length = 4;

        Save.TabKata[1] = 'S';  Move.TabKata[1] = 'M';
        Save.TabKata[2] = 'A';  Move.TabKata[2] = 'O';
        Save.TabKata[3] = 'V';  Move.TabKata[3] = 'V';
        Save.TabKata[4] = 'E';  Move.TabKata[4] = 'E';
        Save.Length = 4;        Move.Length = 4;

      /* Variabel */
      // Variabel inti
        boolean masihMain;              // True bila permainan sedang berlangsung
        int menu;                       // Input pilihan menu
        Kata command;
        boolean booleanAttackUp;
        boolean bol;

      // Variabel laju game
        Status PrevCurPlayer;
        Status AfterCurPlayer;
        Status PrevOpsPlayer;
        Status AfterOpsPlayer;

        STATE S;
        Stack stackofstate;
        CreateEmpty(&stackofstate);
        Player * currentPlayer;
        Player * opposingPlayer;

    // ALGORITMA
        printf("********** AVATAR WORLD WAR **********\n");
        printf("======================================\n");
        printf("Silakan pilih salah satu menu berikut:\n");
        printf("1. Permainan Baru\n");
        printf("2. Muat Permainan yang Tersimpan\n");
        

        TabInt Tab;
        MakeEmptyarr(&Tab); //insialisasi awal flag atatck di tiap giliran main 
        

        currentPlayer = &S.P1;
        opposingPlayer = &S.P2;
        S.turn = 1;
        InitPlayer(&S.P1); InitPlayer(&S.P2); 
        S.P1.playerKe = 1; S.P2.playerKe = 2;
        masihMain = true;                          // Aktivasi permainan

        currentPlayer = &S.P1;
        opposingPlayer = &S.P2;

        scanf("%d", &menu);
        if (menu == 2){
            LoadSafeFile(&S);
            InisialisasiStatus(&PrevCurPlayer);
            InisialisasiStatus(&PrevOpsPlayer);
            InisialisasiStatus(&AfterCurPlayer);
            InisialisasiStatus(&AfterOpsPlayer);
        } else {
            LoadFile(&S);
            InisialisasiQueue(currentPlayer,opposingPlayer);
            AddQ(&(*currentPlayer).skillQueue,1);
            AddQ(&(*currentPlayer).skillQueue,1);
            AddQ(&(*currentPlayer).skillQueue,1);
           // AddQ(&(*currentPlayer).skillQueue,7);
            InisialisasiStatus(&PrevCurPlayer);
            InisialisasiStatus(&PrevOpsPlayer);
            InisialisasiStatus(&AfterCurPlayer);
            InisialisasiStatus(&AfterOpsPlayer);
        }
        /* ALOKASI KONDISI AWAL PERMAINAN */
        /*  - Masukin data konfigurasi ke peta */
        /*  - Dll. */
        // LOOP GAME INTI
        PrintStatus(S, currentPlayer);
        while (masihMain)
        {
             //tiap awal giliran di push state permainan, jadi bisa undo kapan aja
            //nanti juga tiap akhir suatu aksi, jadiin perubahan di STATE, dan entar state di push ke stack of states, ini bsia gw implementasiin habis gamenya udh fungsion
            printf("ENTER COMMAND: ");
            STARTSTDKATA();
            if (IsKataSama(CKata, Attk)) /* command == "ATTACK" */
            {
                  strcpy(S.lastaction,"ATTACK");
                  int j;
                  j = Info(First((*currentPlayer).bangunanPlayer));
                //   printf("a");
                  Sebelum(*currentPlayer, *opposingPlayer, &PrevCurPlayer, &PrevOpsPlayer,S.listbtot);
                //   printf("a");
                  booleanAttackUp=false;
                //   printf("a");
                  Attack(S.Hubungan, &(S), currentPlayer, opposingPlayer, &Tab, booleanAttackUp);
                //   printf("a");
                  Sesudah(*currentPlayer, *opposingPlayer, &AfterCurPlayer, &AfterOpsPlayer,S.listbtot);
                //   printf("a");
                  GetSkill(currentPlayer,opposingPlayer,PrevCurPlayer,PrevOpsPlayer,AfterCurPlayer,AfterOpsPlayer);
            }
            else
            if (IsKataSama(CKata, Lvup)) /* command == "LEVEL_UP" */
            {
                strcpy(S.lastaction,"LEVEL_UP");
                levelUp(&(S.listbtot), currentPlayer);
            }
            else
            if (IsKataSama(CKata, Skll)) /* command == "SKILL" */
            {
                  strcpy(S.lastaction,"SKILL");
                  int skl;
                  if(!IsEmptyQ((*currentPlayer).skillQueue)){
                  DelQ(&(*currentPlayer).skillQueue,&skl);
                  IntToSkill(skl,currentPlayer,opposingPlayer,&S.listbtot);
                  }else{
                      printf("Nggaa ADA SKILL ASU!!\n");
                  }
            }else
            if (IsKataSama(CKata, Undo))
            {
                printf("Kamu mengundo aksi %s", S.lastaction);
                Pop(&stackofstate,&S);
            }
            else
            if (IsKataSama(CKata, Endt)) /* command == "END_TURN" */
            {
                S.turn++;
                Sesudah(*currentPlayer, *opposingPlayer, &AfterCurPlayer, &AfterOpsPlayer,S.listbtot);
                int j,d;
                j = Info(First((*currentPlayer).bangunanPlayer));
                printf("Level: %d",AfterCurPlayer.LevelBangunan.TI[j].B.Level);
                GetSkillIR(currentPlayer,AfterCurPlayer);
                int SkillKe=(*currentPlayer).skillQueue.HEAD;
                printf("Skill Ke: %d", SkillKe);
                AddJumlahPasukan(currentPlayer, &S.listbtot);
                if (!(*currentPlayer).extraTurn)
                {
                    if (currentPlayer == &S.P1)
                    {
                        currentPlayer = &S.P2;
                        opposingPlayer = &S.P1;
                    }
                    else{

                        currentPlayer = &S.P1;
                        opposingPlayer = &S.P2;
                    }
                }
                (*currentPlayer).extraTurn = false;
                
                    Dealokasiarr(&Tab);
                    MakeEmptyarr(&Tab); //Inisialisasi flag attack
                PrintStatus(S, currentPlayer);
            }
            else
            if (IsKataSama(CKata, Save)) /* command == "SAVE" */
            {
                char namafile[20];
                printf("Save kedalam file bernama : ");scanf(" %s",&namafile);
                SaveFile(S,namafile);
            }
            else
            if(IsKataSama(CKata, Move)) /* command == "MOVE" */
            {
                strcpy(S.lastaction,"MOVE");
                move(&S, currentPlayer);
            }
            else
            if (IsKataSama(CKata, Exit)) /* command == "EXIT" */
            {
                masihMain = false;
            }
        }

        printf("Permainan telah berakhir.");
   

   return 0;
}
