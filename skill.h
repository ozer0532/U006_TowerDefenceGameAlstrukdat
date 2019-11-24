#ifndef SKILL_H
#define SKILL_H
#include "bangunan.h"
#include "listlinier.h"
#include "array.h"
#include "player.h"

typedef struct {
    int JumlahBangunan;
    BangunanTot LevelBangunan;
    int JumlahFort;
    int JumlahTower;
    boolean XtraTurn;
} Status;

void InisialisasiStatus(Status *S);
/* pprosedur ini digunakan untuk melakukan inisialisasi status pemain */

void InisialisasiQueue(Player *Pe, Player *Pm);
/* Prosedur ini digunakan untuk menginisialisasi Queue pemain yang telah dibuat */

void InstantUpgrade (Player Pe, BangunanTot *Ba);

    /* Pemain mendapatkan skill ini pada skill awal
        I.S Penain mungkin belom punya bangunan
        F.S Setiap banguna yang dimiliki pemain naik satu level*/

void Shield (Player *Pe); //Bonus
    /*Seluruh bangunan yang dimiliki pemain akan memiliki pertahanan selama 2 turn
        apabila pemain menggunakan skill ini 2 kali beturut-turut durasi tidak akan bertamabah, namun menjadi nilai maksimum    */

void ExtraTurn (Player *Pe);
    /*setelah pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain yang sama*/

void AttackUp( Player *Pe); //Bonus
 /*Jika pemain mengaktifkan skill ini, maka pertahanan lawan tidak akan mempengaruhi penyerangan.
    Syarat: Pemain baru saja melakukan penyerangan ke tower lawan dan tower pemain menjadi berjumlah 3 */
void CriticalHit (Player *Pe); //Bonus
    /* Syarat: Musuh baru saja melakukan skill Extra Turn
        F.S: pada bangunan yang melakukan serangan tepta selanjutnya hanya berkurang 1/2 dari jumlah seharusnya. */
void InstantReinforcement(Player Pe, BangunanTot *Ba);
    /* Syarat : Diakhir gilirannya, bila semua bangunan yang ia miliki memiliki level 4
        F.S: Seluruh bangunan yang ia miliki bertambah 5 pasukannya*/
void Barrage (Player Pe, BangunanTot *Ba);
    /* Syarat: Jumalah bangunan lawan baru saja menjadi 10
        F.S: Jumlah pasukan pada setiap bangunan lawan berkurang 10 */
void GetSkill(Player *CurrentPlayer, Player *OpposingPlayer,Status PrevCurPlayer, Status PrevOpsPlayer,Status AfterCurPlayer,Status AfterOpsPlayer);
    /* Menegcek kondisi apakah pemain mendapatkan suatu skill. Jika Mendapakatkan skill
        maka skill tersbut akan di addlast queue */


void IntToSkill(int SkillKe, Player *Pe, Player *Pm,  BangunanTot *Ba);
    /* mengubah keluaran di queue ke skill */
void GetSkillIR(Player *CurrentPlayer, Status AfterCurPlayer);
/* untuk mengecek apakah pemain mendapatkan skill Instant Reinforce,ent apa tidak */
void GetSkillCH(Player *CurrentPlayer, Player *OpposingPlayer, Status AfterCurPlayer);
/* Untuk mengecek apakah pemain mendapatkan skill critical hit atau tidak */
void Sebelum(Player CurrentPlayer,Player OppsingPlayer, Status *StCurPlyr,Status *StOpsPlyr, BangunanTot Ba);
/* Prosedur ini digunakan untuk mengecek status pemain setiap sebelum attack, baik status oppsing
    ataupun current, status tersebut akan dimasukan kedalam tipe bentukan Status */
void Sesudah(Player CurrentPlayer,Player OppsingPlayer, Status *StCurPlyr,Status *StOpsPlyr, BangunanTot Ba);
/* prosedur ini digunakan untuk mengecek kondisi pemain setelah meakukan attack atau command lain */
 
void skillOff (Player *Pe);
// Mengnonaktifkan skill setiap end turn /*
void skillOffCH (Player *Pe);
// mengnonaktifkan skill critical hit
#endif
