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
// Menambah jumlah pasukkan
// I.S Player terdefinisi
// F.S Jumlah Pasukkan yang ada diinisialisasikan 

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
//Prosedur untuk mencetak status ke layar
//I.S STATE harus sudah terdefinisi
//F.S Status tercetak kelayar

    printf("\n\n\n\n\n");
    boolean(bol);
    printpeta(S);
    printf("Player %d\n", Pe -> playerKe);
    CetakDaftarBangunan(S.listbtot, *Pe, &bol);
    printf("Skill Available: ");
    int SkillKe = (*Pe).skillQueue.T[Pe->skillQueue.HEAD];    
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
      //Digunakan untuk membaca inputan user dalam command 
      //Implementasi menggunakan mesin kata
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
        CreateEmpty(&stackofstate);     //Inisialisasi stack
        Player * currentPlayer;
        Player * opposingPlayer;
        boolean operationFailed;



printf("                                                                                                                                                         .###% \n");
printf("                                                                                                                                                     #%######%#  \n");
printf("                                                                                                                                               /%######%%%%%%, \n");
printf("                                                                                                                                        ,%#######%%%%%,       \n");
printf("                                                                                     ,#,,,,,     *#.                            %#%%#######%%%&(              \n");
printf("                                                                                  (   ,,,,,          ,                 (     ,%######%%%%%.                   \n");
printf("                                                                      ,*,.      *     ,,,,,            #           /(   ,%########%%%.                        \n");
printf("                                                                 .#///////////%,     ,,,,,.             .         ,.,,. %#%%%&%%%%                            \n");
printf("                                                               %//////////////,.     ,,,,,,              #    *%###/%.    (                                   \n");
printf("                                                             %///////////////%,      ,,,,,,,,,,,          %#####,,..#,(/                                      \n");
printf("                                                           ,#(((/////////////%,  .,,,,,,,,,,,,,           (//%,....#                                          \n");
printf("                                                (////#(,##(((((((((((////////%*    ,,,,,,,,,,,            (,.//#..*                                           \n");
printf("                                               (//////////((////////////////%%,      ,,,,,,,   ,%%        *,* /(,.                                            \n");
printf("                                    //       #/////////////////////////////#,%/,,,%%(  ,,,. *%%&&&&*     /*.# #(                                              \n");
printf("                                  %,,,#     (/////////////////////(((((((((**/#*.. %/*.     , * %/      ,,. (*/#                                              \n");
printf("               /,,..              ,,, (    #////////////////////////(((((((%,*,,, %((          // ,      #(.#//#                                              \n");
printf("               *,,,              .,,, #    (((((((((((((((((((((((((%(((((((((,(.                       .  (//(                                               \n");
printf("               #,,,,,             ,,, (    (((((((((((((((((((#%((((((((((((((&%,     #,.,,/            #////,                                                \n");
printf("                ,,,,..            ,,, ,     #(((((((((((#%%((((((((((((((((((%(,,                       (//(                                                  \n");
printf("                ,,,,,./           ,,,     ,////////////((((((((((((((((((((((((*(,    *,,(#,    (     .#///                                                   \n");
printf("                 .,,,,, *         ,,,, %///(%%#(////((((((((((((((((((((((#((#(%,,(,  /%      .(/   /..*//(                                                   \n");
printf("                  #,,,,, #        /,,,.#//%(((%/////////////////(((((((((((#(#((#,,,%(,    ,*.    #....///%                                                   \n");
printf("*,,,#               (,,(,, *       *,,,..((((((((%(((((((((((/////////(((((((#((((#,,,(,*#,     %.......(//,                                                   \n");
printf("%,,,,,*.             #,,,,. ,      /,,,. %((%(%.  %(((####(/(#(((////////(((((%(((((%,,,#,......,,.....%//%                                                    \n");
printf(",/,,,,,,(.           *,,,,,  /    (,,,, *%(   (,%#((#%#(((((((%///////////((((#((((((##..,#....*((((%#///                                                     \n");
printf("   %,,,,,,,.#         .,,,,,,,,,,,,,,,,       %,,,,,,,(((%(,,,##/////////(//((((#((((((((%#((#%/%////////                                                     \n");
printf("     ,*,,,,,,..&/      %,,,,,#,,,,,,,,,,  . /,,,....,,,#((%,,,,#////////////((((#((((((((((%(((///////(                                                       \n");
printf("        */,,,,,,*.  **,#,,,,,,,,,,,,,,,,* /,,,.........,,((,,,,,///////////////(((((((((///,,(//////#                                                         \n");
printf("            %,,,,,,,,*,,,,,,,,,,,,,,,,,,,, (,#/........,,#(/,,,,#//////////((/////////////#/* ,////                                                           \n");
printf("               %,,,(,,,,,,,,,,,,,,,,,,,,,, .,,(.........,((,,,,,#%///((((((//////////////%    */*                                                         .   \n");
printf("(,,*##*,,,//,,*/##,/,,,,,,,,,,,,,,,,,,,,,,,,, .,,........,/(#,,%#,#(%,%////////////////////,,,,,/,,,.........**                                            .    \n");
printf("(#,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,*(#(,,,..,  #.......,/(/,,#,,,,#(#,,,,,*(#%///////////,,,,,,...............*                                              . \n");
printf(" .%*,,,,,,,,,,,,,#,,,,,,,,,,(,,,,,,,,,**,,,,   .#,,#  #*(#,,,,,,,,##((%*,,,,,,#///////#,,,,,...................,                                        .     \n");
printf("                #,,,,,,*#(,,,,,,,,,%,,,,,,,,,,,,,,   ,# (,,,,,,,,,,,,,#####%##*%////#,,,,,......................#                                         . ..\n");
printf("                  (,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.     ..   #,,,,,,,,,,(,,,(/(,,,,,,,,,,,,,,,,,,,,...........                                            \n");
printf("                    .&*,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,**,,,#,,,,,,,,,,,,,,,(,,,,,,,,,,,,,,,,,,,,,,..........#                                         . \n");
printf("                       (,,,,,,,,,,,,,,,,,,,,,,,/#/*/##/,,,,,,,*(,,,,,,,,/,,,,,,,,,,,,,,,,,,,,,,,,,,,.,,..,,......,                                          . \n");
printf("                         %,,,,,,,,((,,,(####,,,.#   ,,,,,,,,,,,,,,,,(#(.    .######%%#*,,,,,,,,,,,,,,,,,,...,,,,,#                                       .    \n");
printf("                                   #,,,,*#(//(/  ,,,,,,,,,,,,,,,*/          /#####((,.%#(#(%#*,,,,,,,,,,,,,,,,,,*                                            .\n");
printf("                                                 /,,,,,,,,,,,*,            #######(.      ((#(#%(#,,,,,,,,,,,,,,.                                           . \n");
printf("                                                *#%,,,,,,,*#              %(#(##((           .%#(#(*,,,,,,,,,,#                                          .  . \n");
printf("                                               (#####(%((/.              #%%%##((.            /,*/*,,,,,,,,,/#                                              . \n");
printf("                                              #(#####                    ,%%%%##                (,,,,,*(                                                    . \n");
printf("                                           ,%%##%,                        %%%%#,                                                                         .  . \n");
printf("                                          ##((%                                                                                                               \n");
printf("                                       ,#(#((#                                                                                                               .\n");
printf("                                       %%##%%                                                                                                            ..  .\n");
printf("                                       ##,                                                                                                                     \n");



                                                                                                                                     
                                                                                                                                     
printf("               AAA   VVVVVVVV           VVVVVVVV   AAA         TTTTTTTTTTTTTTTTTTTTTTT         AAA               RRRRRRRRRRRRRRRRR   \n");
printf("              A:::A  V::::::V           V::::::V  A:::A        T:::::::::::::::::::::T        A:::A              R::::::::::::::::R  \n");
printf("             A:::::A V::::::V           V::::::V A:::::A       T:::::::::::::::::::::T       A:::::A             R::::::RRRRRR:::::R \n");
printf("            A:::::::AV::::::V           V::::::VA:::::::A      T:::::TT:::::::TT:::::T      A:::::::A            RR:::::R     R:::::R\n");
printf("           A:::::::::AV:::::V           V:::::VA:::::::::A     TTTTTT  T:::::T  TTTTTT     A:::::::::A             R::::R     R:::::R\n");
printf("          A:::::A:::::AV:::::V         V:::::VA:::::A:::::A            T:::::T            A:::::A:::::A            R::::R     R:::::R\n");
printf("         A:::::A A:::::AV:::::V       V:::::VA:::::A A:::::A           T:::::T           A:::::A A:::::A           R::::RRRRRR:::::R \n");
printf("        A:::::A   A:::::AV:::::V     V:::::VA:::::A   A:::::A          T:::::T          A:::::A   A:::::A          R:::::::::::::RR  \n");
printf("       A:::::A     A:::::AV:::::V   V:::::VA:::::A     A:::::A         T:::::T         A:::::A     A:::::A         R::::RRRRRR:::::R \n");
printf("      A:::::AAAAAAAAA:::::AV:::::V V:::::VA:::::AAAAAAAAA:::::A        T:::::T        A:::::AAAAAAAAA:::::A        R::::R     R:::::R\n");
printf("     A:::::::::::::::::::::AV:::::V:::::VA:::::::::::::::::::::A       T:::::T       A:::::::::::::::::::::A       R::::R     R:::::R\n");
printf("    A:::::AAAAAAAAAAAAA:::::AV:::::::::VA:::::AAAAAAAAAAAAA:::::A      T:::::T      A:::::AAAAAAAAAAAAA:::::A      R::::R     R:::::R\n");
printf("   A:::::A             A:::::AV:::::::VA:::::A             A:::::A   TT:::::::TT   A:::::A             A:::::A   RR:::::R     R:::::R\n");
printf("  A:::::A               A:::::AV:::::VA:::::A               A:::::A  T:::::::::T  A:::::A               A:::::A  R::::::R     R:::::R\n");
printf(" A:::::A                 A:::::AV:::VA:::::A                 A:::::A T:::::::::T A:::::A                 A:::::A R::::::R     R:::::R\n");
printf("AAAAAAA                   AAAAAAAVVVAAAAAAA                   AAAAAAATTTTTTTTTTTAAAAAAA                   AAAAAAARRRRRRRR     RRRRRRR\n");
                                                                                                                                     
                                                                                                                                     
                                                                                                                                     
                                                                                                                                     
                                                                                                                                     
                                                                                                                                     
                                                                                                                                     





printf("\n\n\n");
    // ALGORITMA
        printf("********** AVATAR WORLD WAR **********\n");
        printf("======================================\n");
        printf("Silakan pilih salah satu menu berikut:\n");
        printf("1. Permainan Baru\n");
        printf("2. Muat Permainan yang Tersimpan\n");
        
        

        MakeEmptyarr(&S.flagAttack); //insialisasi awal flag atatck di tiap giliran main 
        currentPlayer = &S.P1;
        opposingPlayer = &S.P2;
        S.turn = 1;
        InitPlayer(&S.P1); InitPlayer(&S.P2); 
        S.P1.playerKe = 1; S.P2.playerKe = 2;
        masihMain = true;                          // Aktivasi permainan

        currentPlayer = &S.P1;
        opposingPlayer = &S.P2;

        
        printf("Masukkan menu : ");
        scanf("%d", &menu);

        //Validasi inputan menu
        while ((menu<1) || (menu>2)) {
            printf("inputan salah... Ulang lagi\n");
            printf("Masukkan menu : ");
            scanf("%d", &menu);
        };
        if (menu == 2){
            LoadSafeFile(&S);
            InisialisasiStatus(&PrevCurPlayer);
            InisialisasiStatus(&PrevOpsPlayer);
            InisialisasiStatus(&AfterCurPlayer);
            InisialisasiStatus(&AfterOpsPlayer);
        } else if (menu ==1){
            LoadFile(&S);
            InisialisasiQueue(currentPlayer,opposingPlayer);
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
            if (operationFailed) {
                operationFailed = false;
            } else {
                Push(&stackofstate, S); 
            }
            //nanti juga tiap akhir suatu aksi, setiap perubahannya dijadikkan ke dalam state
            //Agar mempermudah skill dan undo
            printf("ENTER COMMAND: ");
            STARTSTDKATA();
            if (IsKataSama(CKata, Attk)) /* command == "ATTACK" */
            {
                  strcpy(S.lastaction,"ATTACK");
                  int j;
                  //prosedur Sebelum(...) adalah prosedur yang digunakkan untuk mengecheck kondisi sebelom attack
                  //prosedur Sesudah(...) adalah prosedur yang digunakkan untuk mengecheck kondisi setelah attack
                  //GetSkill adakan diterima jika kondisi mendapatkan skill memenuhi
                  j = Info(First((*currentPlayer).bangunanPlayer));
                  Sebelum(*currentPlayer, *opposingPlayer, &PrevCurPlayer, &PrevOpsPlayer,S.listbtot);
                  booleanAttackUp=false;
                //   printf("a");
                  Attack(S.Hubungan, &(S), currentPlayer, opposingPlayer, &S.flagAttack, booleanAttackUp);
                //   printf("a");
                  Sesudah(*currentPlayer, *opposingPlayer, &AfterCurPlayer, &AfterOpsPlayer,S.listbtot);
                  GetSkill(currentPlayer,opposingPlayer,PrevCurPlayer,PrevOpsPlayer,AfterCurPlayer,AfterOpsPlayer);
                  skillOffCH(currentPlayer);
                  if(IsEmptyL(opposingPlayer->bangunanPlayer)){
                      masihMain = false;
                      printf("ANDA MENANG");
                  }
                printf("\n");
                PrintStatus(S, currentPlayer);
            }
            else
            if (IsKataSama(CKata, Lvup)) /* command == "LEVEL_UP" */
            {
                strcpy(S.lastaction,"LEVEL_UP");
                levelUp(&(S.listbtot), currentPlayer);
                printf("\n");
            }
            else
            if (IsKataSama(CKata, Skll)) /* command == "SKILL" */
            {
                  strcpy(S.lastaction,"SKILL");
                  int skl;
                  if(!IsEmptyQ((*currentPlayer).skillQueue)){
                  DelQ(&(*currentPlayer).skillQueue,&skl);
                  IntToSkill(skl,currentPlayer,opposingPlayer,&S.listbtot);
                  Sesudah(*currentPlayer, *opposingPlayer, &AfterCurPlayer, &AfterOpsPlayer,S.listbtot);
                  GetSkillCH(currentPlayer,opposingPlayer,AfterCurPlayer);
                  }else{
                      printf("Nggaa ADA SKILL :( !!\n");
                  }
                printf("\n");
            }else
            if (IsKataSama(CKata, Undo))
            {
                if (stackofstate.TOP > 1) {
                    int playerId;
                    if (currentPlayer == &S.P1) {
                        playerId = 1;
                    } else {
                        playerId = 2;
                    }

                    printf("Kamu meng-undo aksi %s\n", S.lastaction);
                    SAVEDSTATE previousState;
                    SAVEDSTATE currentState;
                    Pop(&stackofstate,&currentState);
                    Pop(&stackofstate,&previousState);
                    SETSTATE(&S, previousState);
                    
                    if (playerId == 1) {
                        currentPlayer = &S.P1;
                    } else {
                        currentPlayer = &S.P2;
                    }
                } else {
                    printf("Kamu tidak bisa meng-undo\n");
                }
                printf("\n");
            }
            else
            if (IsKataSama(CKata, Endt)) /* command == "END_TURN" */
            {
                S.turn++;
                Sesudah(*currentPlayer, *opposingPlayer, &AfterCurPlayer, &AfterOpsPlayer,S.listbtot);
                int j;
                j = Info(First((*currentPlayer).bangunanPlayer));
                GetSkillIR(currentPlayer,AfterCurPlayer);
                skillOff(currentPlayer);
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
                
                Dealokasiarr(&S.flagAttack);
                MakeEmptyarr(&S.flagAttack); //Inisialisasi flag 
                while(!IsEmptyST(stackofstate)) {
                    SAVEDSTATE temp;
                    Pop(&stackofstate, &temp);
                }
                printf("\n");
                PrintStatus(S, currentPlayer);
            }
            else
            if (IsKataSama(CKata, Save)) /* command == "SAVE" */
            {
                char namafile[20];
                printf("Save kedalam file bernama : ");scanf(" %s",&namafile);
                masihMain = false;
                SaveFile(S,namafile);
                printf("\n");
            }
            else
            if(IsKataSama(CKata, Move)) /* command == "MOVE" */
            {
                strcpy(S.lastaction,"MOVE");
                move(&S, currentPlayer);
                printf("\n");
            }
            else
            if (IsKataSama(CKata, Exit)) /* command == "EXIT" */
            {
                masihMain = false;
                printf("\n");
            }
            else {
                operationFailed = true;
                printf("\n");
            }
        }

        printf("Permainan telah berakhir.");
   

   return 0;
}
