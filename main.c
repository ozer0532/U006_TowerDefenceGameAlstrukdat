#include <stdio.h>
#include <string.h>
#include "boolean.h"
#include "queue.h"
#include "mesinkata.h"
#include "bangunan.h"
#include "listlinier.h"
#include "state.h"

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

void levelUp(BangunanTot *T, Pemain *Pe, int PEMAINKE)
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

    // ALGORITMA
      Inisialisasi(&Ac);
      n = 1;
      if (PEMAINKE == 1)
        P = First((*Pe).L1);
      else if (PEMAINKE == 2)
        P = First((*Pe).L2);

      CetakDaftarBangunan(*T, *Pe, PEMAINKE);
      printf("Bangunan yang akan di level up:");scanf("%d", &pilih);

      while (n != pilih)
      {
          P = Next(P);
          n++;
      }

      pas = (*T).TI[Info(P)].B.Jpas;
      jns = (*T).TI[Info(P)].B.Jenis;
      lvl = (*T).TI[Info(P)].B.Level;

      if (pas >= CariDariAcuan(Ac, jns, lvl, 'M'))
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

int main()
{
    // KAMUS
      /* Konstanta*/
        char atk[] = "ATTACK";
        char lup[] = "LEVEL_UP";
        char skl[] = "SKILL";
        char ext[] = "EXIT";
        char end[] = "END_TURN";
        char sav[] = "SAVE";

      /* Variabel */
      // Variabel inti
        boolean masihMain;              // True bila permainan sedang berlangsung
        int menu;                       // Input pilihan menu
        char command[8];                // Berisi command yang akan diinput pada game

      // Variabel laju game
        STATE S;                        // Berisi state saat ini
        // TODO: Insert undo disini
        SKILL QS;                       // Queue skill yang dimiliki tiap kedua pemain
        Pemain Pe;                      // List bangunan yang dimiliki tiap kedua player
        BangunanTot BT;                  // Array bangunan pada game

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
            /*  - Dll. */
            S.turn = 1;
            CreateEmptyQ(&(QS.SA), /* Maks gedung*/); CreateEmptyQ(&(QS.SB), /* Maks gedung*/);     // Init Queue Skill
            CreateEmptyL(&(Pe.L1)); CreateEmptyL(&(Pe.L2));                                         // Init List Bangunan
            MakeEmptyBangunanTot(&BT);                  // ? - Ini apaan?
            masihMain = true;                          // Aktivasi permainan

            // LOOP GAME INTI
            do
            {
              /* TODO: Cetak peta ke layar */

              while (masihMain && S.turn % 2 == 1)
              {
                printf("Player %d\n", pemainKe(S.turn));
                /* TODO: Cetak bangunan yang dimiliki pemain */

                printf("ENTER COMMAND: ");scanf("%s", command);

                if (!strcmp(command, atk)) /* command == "ATTACK" */
                {

                }

                if (!strcmp(command, lup)) /* command == "LEVEL_UP" */
                {
                    levelUp(&BT, &Pe, pemainKe(S.turn));
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
                    if (skillP1 == /* akronim extra turn */)
                        S.turn ++;
                }

                if (!strcmp(command, sav)) /* command == "SAVE" */
                {

                }
              }

              /* while pemain ke-2 */
              /* Tinggal copas + edit sedikit yang atas kalau udah jadi */
            }
            while(masihMain);

            printf("Permainan telah berakhir.");
        }
}
