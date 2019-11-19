#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "queue.h"
#include "mesinkata.h"
#include "bangunan.h"
#include "listlinier.h"
#include "STATE.h"
#include "stackt.h"
#include "player.h"

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

    // ALGORITMA
      Inisialisasi(&Ac);
      n = 1;
      P = First((*Pe).bangunanPlayer);

      CetakDaftarBangunan(*T, *Pe);
      printf("Bangunan yang akan di level up:");scanf("%d", &pilih);

      while (n != pilih)
      {
          P = Next(P);
          n++;
      }

      pas = (*T).TI[Info(P)].B.Jpas;
      jns = (*T).TI[Info(P)].B.Jenis;
      lvl = (*T).TI[Info(P)].B.Level;

      M = CariDariAcuan(Ac, jns, lvl, 'M');
      if (pas >= M)
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

void Move(BangunanTot *T, Player *Pe)
// I.S. T dan Pe terdefinisi
// F.S. Sejumlah pasukan pemain di bangunan A pindah ke
//      bangunan B
{
    // KAMUS LOKAL
        int pilih;
        ACUAN Ac;
        address P;

    // ALGORITMA
        Inisialisasi(&Ac);
        P = First((*Pe).bangunanPlayer);

        CetakDaftarBangunan(*T, *Pe);
        printf("Pilih bangunan:");scanf("%d", &pilih);
        
}

int main()
{
    // KAMUS
      /* Konstanta */
        char atk[] = "ATTACK";
        char lup[] = "LEVEL_UP";
        char skl[] = "SKILL";
        char ext[] = "EXIT";
        char undo[] = "UNDO";
        char end[] = "END_TURN";
        char sav[] = "SAVE";
        char mov[] = "MOVE";

      /* Variabel */
      // Variabel inti
        boolean masihMain;              // True bila permainan sedang berlangsung
        int menu;                       // Input pilihan menu
        char command[8];                // Berisi command yang akan diinput pada game

      // Variabel laju game
        STATE S;
        Stack stackofstate;
        CreateEmpty(&stackofstate);
        Player P1;
        Player P2;
        BangunanTot BT;                  // Array bangunan pada game
        Player * currentPlayer;
        Player * opposingPlayer;

    // ALGORITMA
        printf("********** AVATAR WORLD WAR **********\n");
        printf("======================================\n");
        printf("Silakan pilih salah satu menu berikut:\n");
        printf("1. Permainan Baru\n");
        printf("2. Muat Permainan yang Tersimpan\n");
        scanf("%d", &menu);

        if (menu == 1)
        {
            /* ALOKASI KONDISI AWAL PERMAINAN */
            /*  - Masukin data konfigurasi ke peta */
            makeemptypeta(&(S.peta));
            LoadFile(&S);
            /*  - Dll. */
            S.turn = 1;
            CreateEmptyQ(&(P1.skillQueue), 30); CreateEmptyQ(&(P2.skillQueue), 30);     // Init Queue Skill
            CreateEmptyL(&(P1.bangunanPlayer)); CreateEmptyL(&(P2.bangunanPlayer));    
            P1.playerKe = 1; P2.playerKe = 2;
            // Init List Bangunan
            MakeEmptyBangunanTot(&BT);                  // ? - Ini apaan?
            masihMain = true;                          // Aktivasi permainan

            currentPlayer = &P1;
            opposingPlayer = &P2;

            // LOOP GAME INTI
            do
            {
              /* TODO: Cetak peta ke layar */
              printpeta(S.peta);
              while (masihMain)
              {
                Poosh(&stackofstate,S); //tiap awal giliran di push state permainan, jadi bisa undo kapan aja
                //nanti juga tiap akhir suatu aksi, jadiin perubahan di STATE, dan entar state di push ke stack of states, ini bsia gw implementasiin habis gamenya udh fungsional
                printf("Player %d\n", pemainKe(S.turn));
                /* TODO: Cetak bangunan yang dimiliki pemain */


                printf("ENTER COMMAND: ");scanf("%s", command);

                if (!strcmp(command, atk)) /* command == "ATTACK" */
                {

                  strcpy(S.lastaction,"ATTACK");
                }

                if (!strcmp(command, lup)) /* command == "LEVEL_UP" */
                {
                    levelUp(&BT, currentPlayer);
                }

                if (!strcmp(command, skl)) /* command == "SKILL" */
                {

                }

                if (!strcmp(command, ext)) /* command == "EXIT" */
                {
                  masihMain = false;
                }

                if (!strcmp(command, end)) /* command == "END_TURN" */
                {
                    S.turn++;
                    if (!(*currentPlayer).extraTurn) {
                      if (currentPlayer == &P1) {
                        currentPlayer = &P2;
                        opposingPlayer = &P1;
                      } else {
                        currentPlayer = &P1;
                        opposingPlayer = &P2;
                      }
                    }
                }

                if(!strcmp(command, mov)) /* command == "MOVE" */
                {

                }

                if (!strcmp(command, sav)) /* command == "SAVE" */
                {
                  char namafile[20];
                  printf("Save kedalam file bernama : ");scanf(" %s",&namafile);
                  SaveFile(S,namafile);
                }

                if (!strcmp(command, undo)){
                  printf("Kamu mengundo aksi %s", S.lastaction);
                  Undo(&stackofstate,&S);
                }
                Poosh(&stackofstate,S);
              }

              /* while pemain ke-2 */
              /* Tinggal copas + edit sedikit yang atas kalau udah jadi */
            }
            while(masihMain);

            printf("Permainan telah berakhir.");
        }
        else
        {
          LoadSafeFile(&S);
          //load save file udh dibuat, perbedaannya dikit doang ama file
        }
}
