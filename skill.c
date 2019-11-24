#include "skill.h"
#include <stdio.h>
#include "attack.h"

void InisialisasiStatus(Status *S) {
/* pprosedur ini digunakan untuk melakukan inisialisasi status pemain */
    (*S).JumlahBangunan=0;
    MakeEmptyBangunanTot(&(*S).LevelBangunan);
    (*S).JumlahFort=0;
    (*S).JumlahTower=0;
    (*S).XtraTurn =false;
}

void InstantUpgrade (Player Pe, BangunanTot *Ba)
    /* Pemain mendapatkan skill ini pada skill awal
        I.S Penain mungkin belom punya bangunan
        F.S Setiap banguna yang dimiliki pemain naik satu level*/
{
    address P;
    P = First(Pe.bangunanPlayer);
    while(P != Nil){
        if((*Ba).TI[Info(P)].B.Level <4){
        (*Ba).TI[Info(P)].B.Level+=1;
        }
        P = Next(P);
    }
    printf("Instant Upgrade Telah Diaktifkan\n");
    printf("Level Bangunan Anda Diupgrade\n");
}
void Shield (Player *Pe){ 
    (*Pe).shieldCooldown = 3; // ET P1 S = 2, ET P1 S = 1
    printf("Shield Anda Telah Aktif \n");
}

void ExtraTurn (Player *Pe)
    /*setelah pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain yang sama*/
{
    (*Pe).extraTurn = true;
    printf("Extra Turn Telah Aktif!!\n");
}
void AttackUp( Player *Pe) //Bonus
 /*Jika pemain mengaktifkan skill ini, maka pertahanan lawan tidak akan mempengaruhi penyerangan.
    Syarat: Pemain baru saja melakukan penyerangan ke tower lawan dan tower pemain menjadi berjumlah 3 */
    {
        (*Pe).AttackUp = true;
        printf("Attack Up Anda Telah Aktif!\n");
    }
void CriticalHit (Player *Pe) //Bonus
    /* Syarat: Musuh baru saja melakukan skill Extra Turn
        F.S: pada bangunan yang melakukan serangan tepat selanjutnya hanya berkurang 1/2 dari jumlah seharusnya. */
    {
        (*Pe).CriticalHit = true;
        printf("Critical Hit Anda Aktif!!\n");
    }
void InstantReinforcement(Player Pe, BangunanTot *Ba)
    /* Syarat : Diakhir gilirannya, bila semua bangunan yang ia miliki memiliki level 4
        F.S: Seluruh bangunan yang ia miliki bertambah 5 pasukannya*/
        {
            ACUAN AC;
            Inisialisasi(&AC);
            int lvl;
            char jns;
            address P;
                P = First(Pe.bangunanPlayer);
                while(P != Nil){
                    lvl = (*Ba).TI[Info(P)].B.Level;
                    jns = (*Ba).TI[Info(P)].B.Jenis;
                    if(jns == 'C'){
                        if((*Ba).TI[Info(P)].B.Jpas <= (AC.C[lvl].M - 5)){
                            (*Ba).TI[Info(P)].B.Jpas = (*Ba).TI[Info(P)].B.Jpas + 5;
                            printf("Instant Reinforcment Aktif\n");
                        }else{
                            printf("Jumlah bangunan dibatas maksimum!\n");
                        }
                    }
                    else if(jns == 'T'){
                        if((*Ba).TI[Info(P)].B.Jpas <= (AC.T[lvl].M-5)){
                            (*Ba).TI[Info(P)].B.Jpas = (*Ba).TI[Info(P)].B.Jpas + 5;
                            printf("Instant Reinforcment Aktif\n");
                        }else{
                            printf("Jumlah bangunan dibatas maksimum!\n");
                        }
                    }
                    else if(jns == 'F'){
                        if((*Ba).TI[Info(P)].B.Jpas <= (AC.F[lvl].M-5)){
                            (*Ba).TI[Info(P)].B.Jpas = (*Ba).TI[Info(P)].B.Jpas + 5;
                            printf("Instant Reinforcment Aktif\n");
                        }else{
                            printf("Jumlah bangunan dibatas maksimum!\n");
                        }
                    }
                    else if(jns == 'V'){
                        if((*Ba).TI[Info(P)].B.Jpas <= (AC.V[lvl].M-5)){
                            (*Ba).TI[Info(P)].B.Jpas = (*Ba).TI[Info(P)].B.Jpas + 5;
                            printf("Instant Reinforcment Aktif\n");
                        }else{
                            printf("Jumlah bangunan dibatas maksimum!\n");
                        }
                    }
                   P = Next(P);
                }

        }
void Barrage (Player Pe, BangunanTot *Ba)
    /* Syarat: Jumalah bangunan lawan baru saja menjadi 10
        F.S: Jumlah pasukan pada setiap bangunan lawan berkurang 10 */
        {
            address P;
                P = First(Pe.bangunanPlayer);
                while(P != Nil){
                    if((*Ba).TI[Info(P)].B.Jpas >= 10){
                    (*Ba).TI[Info(P)].B.Jpas -= 10;
                    }else{
                        (*Ba).TI[Info(P)].B.Jpas = 0;
                    }
                    P = Next(P);
                }
            printf("Barrage Aktif!!\n");
        }
void IntToSkill(int SkillKe, Player *Pe,Player *Pm,  BangunanTot *Ba){
/* Akan karena keluaran dari queue itu berbentuk integer maka kita perlu
    bentuk integer tersebut ke skill dengan menggunakan prosedur ini */
    if(SkillKe == 1){
        InstantUpgrade(*Pe, Ba);
    }
    if(SkillKe == 2){
        Shield(Pe);
    }
    if(SkillKe == 3){
        ExtraTurn(Pe);
    }
    if(SkillKe == 4){
        AttackUp(Pe);
    }
    if(SkillKe == 5){
        CriticalHit(Pe);
    }
    if(SkillKe == 6){
        InstantReinforcement(*Pe, Ba);
    }
    if(SkillKe == 7){
        Barrage(*Pm, Ba);
    }
}

void Sebelum(Player CurrentPlayer,Player OppsingPlayer, Status *StCurPlyr,Status *StOpsPlyr, BangunanTot Ba){
/* Prosedur ini digunakan untuk mengecek status pemain setiap sebelum attack, baik status oppsing
    ataupun current, status tersebut akan dimasukan kedalam tipe bentukan Status */
    /*KAMUS*/
    address PCur;
    address POps;


    /*ALGORITMA*/

    (*StCurPlyr).JumlahBangunan = NbElmtL(CurrentPlayer.bangunanPlayer);
    (*StOpsPlyr).JumlahBangunan = NbElmtL(OppsingPlayer.bangunanPlayer);

    PCur = First(CurrentPlayer.bangunanPlayer);
    POps = First(OppsingPlayer.bangunanPlayer);
    
    if (POps == Nil ) {
         (*StOpsPlyr).LevelBangunan.TI[Info(POps)].B.Level=1;
         (*StOpsPlyr).JumlahTower =0;
        (*StOpsPlyr).JumlahFort = 0;
    }
    while(POps != Nil){
        if(Ba.TI[Info(POps)].B.Jenis == 'F'){
            (*StOpsPlyr).JumlahFort += 1;
        }
        if(Ba.TI[Info(POps)].B.Jenis == 'T'){
            (*StOpsPlyr).JumlahTower += 1;
        }
        (*StOpsPlyr).LevelBangunan.TI[Info(POps)].B.Level = Ba.TI[Info(POps)].B.Level;
        POps = Next(POps);
    }
    if(PCur == Nil){
        (*StCurPlyr).LevelBangunan.TI[Info(POps)].B.Level=1;
        (*StCurPlyr).JumlahTower =0;
        (*StCurPlyr).JumlahFort = 0;
    }
    while(PCur != Nil){
        if(Ba.TI[Info(PCur)].B.Jenis == 'F'){
            (*StCurPlyr).JumlahFort += 1;
        }
        if(Ba.TI[Info(PCur)].B.Jenis == 'T'){
            (*StCurPlyr).JumlahTower += 1;
        }
        (*StCurPlyr).LevelBangunan.TI[Info(PCur)].B.Level = Ba.TI[Info(PCur)].B.Level;
        PCur = Next(PCur);
    }
    (*StCurPlyr).XtraTurn = CurrentPlayer.extraTurn;
    
}
void Sesudah (Player CurrentPlayer,Player OppsingPlayer, Status *StCurPlyr,Status *StOpsPlyr, BangunanTot Ba){
/* prosedur ini digunakan untuk mengecek kondisi pemain setelah meakukan attack atau command lain */
    
    /*KAMUS*/
    address PCur;
    address POps;


    /*ALGORITMA*/

    (*StCurPlyr).JumlahBangunan = NbElmtL(CurrentPlayer.bangunanPlayer);
    (*StOpsPlyr).JumlahBangunan = NbElmtL(OppsingPlayer.bangunanPlayer);

    PCur = First(CurrentPlayer.bangunanPlayer);
    POps = First(OppsingPlayer.bangunanPlayer);
    
    if (POps == Nil ) {
         (*StOpsPlyr).LevelBangunan.TI[Info(POps)].B.Level=1;
         (*StOpsPlyr).JumlahTower =0;
        (*StOpsPlyr).JumlahFort = 0;
    }
    while(POps != Nil){
        if(Ba.TI[Info(POps)].B.Jenis == 'F'){
            (*StOpsPlyr).JumlahFort += 1;
        }
        if(Ba.TI[Info(POps)].B.Jenis == 'T'){
            (*StOpsPlyr).JumlahTower += 1;
        }
        (*StOpsPlyr).LevelBangunan.TI[Info(POps)].B.Level = Ba.TI[Info(POps)].B.Level;
        POps = Next(POps);
    }
    if(PCur == Nil){
        (*StCurPlyr).LevelBangunan.TI[Info(POps)].B.Level=1;
        (*StCurPlyr).JumlahTower =0;
        (*StCurPlyr).JumlahFort = 0;
    }
    while(PCur != Nil){
        if(Ba.TI[Info(PCur)].B.Jenis == 'F'){
            (*StCurPlyr).JumlahFort += 1;
        }
        if(Ba.TI[Info(PCur)].B.Jenis == 'T'){
            (*StCurPlyr).JumlahTower += 1;
        }
        (*StCurPlyr).LevelBangunan.TI[Info(PCur)].B.Level = Ba.TI[Info(PCur)].B.Level;
        PCur = Next(PCur);
    }
    (*StCurPlyr).XtraTurn = CurrentPlayer.extraTurn;
}
void GetSkill(Player *CurrentPlayer, Player *OpposingPlayer,Status PrevCurPlayer, Status PrevOpsPlayer,Status AfterCurPlayer,Status AfterOpsPlayer){
    /*Kalo mengecek syarat - syarat untuk mendapatkan skill, kalo memenuhi syarat maka skill akan di add
        ke queue. kalol tidak mememnnuhi maka diabaikan. Untuk mengecek syarat - syaratnya menggunakan prosedur 
        sebelum sama sesudah */ 

        //shield
        if(AfterOpsPlayer.JumlahBangunan == 2 && PrevOpsPlayer.JumlahBangunan ==3){
            if(!IsFullQ((*OpposingPlayer).skillQueue)){
                AddQ(&(*OpposingPlayer).skillQueue,2);
            }
        }
        //ExtraTurn
        if((AfterOpsPlayer.JumlahFort -1) ==  PrevOpsPlayer.JumlahFort){
            if(!IsFullQ((*OpposingPlayer).skillQueue)){
                AddQ(&(*OpposingPlayer).skillQueue,3);
            }
        }
        //Attack Up
        if(PrevCurPlayer.JumlahTower == 2 && AfterCurPlayer.JumlahTower == 3){
            if(!IsFullQ((*CurrentPlayer).skillQueue)){
                AddQ(&(*CurrentPlayer).skillQueue, 4);
             }
        }
        //Barrage
        if(AfterCurPlayer.JumlahBangunan == 10 && PrevCurPlayer.JumlahBangunan == 9){
            if(!IsFullQ((*CurrentPlayer).skillQueue)){
                AddQ(&(*CurrentPlayer).skillQueue,7);
            }
        }
}
void GetSkillIR(Player *CurrentPlayer, Status AfterCurPlayer){
/* untuk mengecek apakah pemain mendapatkan skill Instant Reinforce,ent apa tidak */
        address P;
        P = First((*CurrentPlayer).bangunanPlayer);
        boolean Check;
        Check = true;
        while(P != Nil && Check == true){
            if(AfterCurPlayer.LevelBangunan.TI[Info(P)].B.Level != 4){
                Check = false;
            }
            P = Next(P); 
        }
        if(Check == true){
            if(!IsFullQ((*CurrentPlayer).skillQueue)){
            AddQ(&(*CurrentPlayer).skillQueue,6);
            }
        }
}
void GetSkillCH(Player *CurrentPlayer, Player *OpposingPlayer, Status AfterCurPlayer){
/* Untuk mengecek apakah pemain mendapatkan skill critical hit atau tidak */
        //Critical Hit
        if(AfterCurPlayer.XtraTurn == true){
            if(!IsFullQ((*OpposingPlayer).skillQueue)){
            AddQ(&(*OpposingPlayer).skillQueue,5);
            }
        }
}

void InisialisasiQueue (Player *Pe, Player *Pm){
/* Prosedur ini digunakan untuk menginisialisasi Queue pemain yang telah dibuat */
    Queue Qpe, Qpm;
    CreateEmptyQ(&(*Pe).skillQueue,10);
    CreateEmptyQ(&(*Pm).skillQueue,10);
    AddQ(&(*Pe).skillQueue,1);
    AddQ(&(*Pm).skillQueue,1);
}
void skillOff (Player *Pe){
// Mengnonaktifkan skill setiap end turn /*
if((*Pe).extraTurn == true){
    if((*Pe).AttackUp == true){ //mengnon aktifak attack up
        (*Pe).AttackUp = false;
    }
}
else{
    if((*Pe).shieldCooldown >= 0){
        (*Pe).shieldCooldown -= 1;
    }
}
}
void skillOffCH (Player *Pe){
    // mengnonaktifkan skill critical hit 
    if((*Pe).CriticalHit == true){
        (*Pe).CriticalHit = false;
    }
}



