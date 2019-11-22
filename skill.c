#include "skill.h"
#include <stdio.h>
#include "attack.h"


void InstantUpgrade (Player Pe, BangunanTot *Ba)
    /* Pemain mendapatkan skill ini pada skill awal
        I.S Penain mungkin belom punya bangunan
        F.S Setiap banguna yang dimiliki pemain naik satu level*/
{
    address P;
    P = First(Pe.bangunanPlayer);
    while(P != Nil){
        (*Ba).TI[Info(P)].B.Level+=1;
        P = Next(P);
    }
  

}
void Shield (Player *Pe){ 
    (*Pe).shieldCooldown = 2;
}
void ShieldSkill (Player Pe, BangunanTot Ba, ACUAN *Semi) //Bonus
    /*Seluruh bangunan yang dimiliki pemain akan memiliki pertahanan selama 2 turn
        apabila pemain menggunakan skill ini 2 kali beturut-turut durasi tidak akan bertamabah, namun menjadi nilai maksimum    */
{
    address P;

    P = First(Pe.bangunanPlayer);
    char Jns;
    char Lvl;
    while(P != Nil){
       Jns =  Ba.TI[Info(P)].B.Jenis;
       Lvl = Ba.TI[Info(P)].B.Level;
        if(Jns == 'C'){ (*Semi).C[Lvl].P = 1;}
        if(Jns == 'T'){(*Semi).T[Lvl].P = 1;}
        if(Jns == 'F'){(*Semi).F[Lvl].P = 1;}
        if(Jns == 'V'){(*Semi).F[Lvl].P = 1;}
        P = Next(P);

    }


}
void ExtraTurn (Player *Pe)
    /*setelah pengaktifan skill ini berakhir, pemain selanjutnya tetap pemain yang sama*/
{
    (*Pe).extraTurn = true;
}
void AttackUp( Player *Pe, BangunanTot Ba) //Bonus
 /*Jika pemain mengaktifkan skill ini, maka pertahanan lawan tidak akan mempengaruhi penyerangan.
    Syarat: Pemain baru saja melakukan penyerangan ke tower lawan dan tower pemain menjadi berjumlah 3 */
    {
        (*Pe).AttackUp = true;
    }
void CriticalHit (Player *Pe) //Bonus
    /* Syarat: Musuh baru saja melakukan skill Extra Turn
        F.S: pada bangunan yang melakukan serangan tepat selanjutnya hanya berkurang 1/2 dari jumlah seharusnya. */
    {
        (*Pe).CriticalHit = true;
    }
void InstantReinforcement(Player Pe, BangunanTot *Ba)
    /* Syarat : Diakhir gilirannya, bila semua bangunan yang ia miliki memiliki level 4
        F.S: Seluruh bangunan yang ia miliki bertambah 5 pasukannya*/
        {
            address P;
                P = First(Pe.bangunanPlayer);
                while(P != Nil){
                    (*Ba).TI[Info(P)].B.Jpas += 5;
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
                    (*Ba).TI[Info(P)].B.Jpas -= 10;
                    P = Next(P);
                }
        }
void IntToSkill(int SkillKe, Player Pe, ACUAN *Semi,  BangunanTot *Ba){
    if(SkillKe == 1){
        InstantUpgrade(Pe, Ba);
    }
    if(SkillKe == 2){
        Shield(&Pe);
    }
    if(SkillKe == 3){
        ExtraTurn(&Pe);
    }
    if(SkillKe == 4){
        AttackUp(&Pe, *Ba);
    }
    if(SkillKe == 5){
        CriticalHit(&Pe);
    }
    if(SkillKe == 6){
        InstantReinforcement(Pe, Ba);
    }
    if(SkillKe == 7){
        Barrage(Pe, Ba);
    }
}

void Sebelum(Player CurrentPlayer,Player OppsingPlayer, Status *StCurPlyr,Status *StOpsPlyr, BangunanTot Ba){
    /*KAMUS*/
    address PCur;
    address POps;

    /*ALGORITMA*/

    (*StCurPlyr).JumlahBangunan = NbElmtL(CurrentPlayer.bangunanPlayer);
    (*StOpsPlyr).JumlahBangunan = NbElmtL(OppsingPlayer.bangunanPlayer);

    PCur = First(CurrentPlayer.bangunanPlayer);
    POps = First(OppsingPlayer.bangunanPlayer);
    while(POps != Nil){
        (*StOpsPlyr).LevelBangunan.TI[Info(POps)].B.Level = Ba.TI[Info(POps)].B.Level;
        POps = Next(POps);
    }
    (*StOpsPlyr).JumlahFort = 0;
    while(POps != Nil){
        if(Ba.TI[Info(POps)].B.Jenis == 'F'){
            (*StOpsPlyr).JumlahFort += 1;
        }
        POps = Next(POps);
    }
    while(POps != Nil){
        if(Ba.TI[Info(POps)].B.Jenis == 'T'){
            (*StOpsPlyr).JumlahTower += 1;
        }
        POps = Next(POps);
    }
    (*StCurPlyr).XtraTurn = CurrentPlayer.extraTurn;
    

    
    
}
void Sesudah (Player CurrentPlayer,Player OppsingPlayer, Status *StCurPlyr,Status *StOpsPlyr, BangunanTot Ba){
    /*KAMUS*/
    address PCur;
    address POps;

    /*ALGORITMA*/

    (*StCurPlyr).JumlahBangunan = NbElmtL(CurrentPlayer.bangunanPlayer);
    (*StOpsPlyr).JumlahBangunan = NbElmtL(OppsingPlayer.bangunanPlayer);

    PCur = First(CurrentPlayer.bangunanPlayer);
    POps = First(OppsingPlayer.bangunanPlayer);
    while(POps != Nil){
        (*StOpsPlyr).LevelBangunan.TI[Info(POps)].B.Level = Ba.TI[Info(POps)].B.Level;
        POps = Next(POps);
    }
    (*StOpsPlyr).JumlahFort = 0;
    while(POps != Nil){
        if(Ba.TI[Info(POps)].B.Jenis == 'F'){
            (*StOpsPlyr).JumlahFort += 1;
        }
        POps = Next(POps);
    }
    while(POps != Nil){
        if(Ba.TI[Info(POps)].B.Jenis == 'T'){
            (*StOpsPlyr).JumlahTower += 1;
        }
        POps = Next(POps);
    }
    (*StCurPlyr).XtraTurn = CurrentPlayer.extraTurn;
}
void GetSkill(Player *CurrentPlayer, Player *OpposingPlayer, BangunanTot Ba){
    /*Kalo mengecek syarat - syarat untuk mendapatkan skill, kalo memenuhi syarat maka skill akan di add
        ke queue. kalol tidak mememnnuhi maka diabaikan. Untuk mengecek syarat - syaratnya menggunakan prosedur 
        sebelum sama sesudah */ 
        Status PrevCurPlayer;
        Status AfterCurPlayer;
        Status PrevOpsPlayer;
        Status AfterOpsPlayer;
        Sebelum(*CurrentPlayer, *OpposingPlayer, &PrevCurPlayer,&PrevOpsPlayer, Ba);
        Sesudah(*CurrentPlayer, *OpposingPlayer, &AfterCurPlayer,&AfterOpsPlayer, Ba);
        // Algoritma mendapatkan skill

        //shield
        if(AfterOpsPlayer.JumlahBangunan == 2 && PrevOpsPlayer.JumlahBangunan ==3){
            AddQ(&(*OpposingPlayer).skillQueue,2);
        }
        //ExtraTurn
        else if((AfterOpsPlayer.JumlahFort -1) ==  PrevOpsPlayer.JumlahFort){
            AddQ(&(*OpposingPlayer).skillQueue,3);
        }
        //Attack Up
        else if(PrevCurPlayer.JumlahTower == 2 && AfterCurPlayer.JumlahTower == 3){
            AddQ(&(*CurrentPlayer).skillQueue, 4);
        }
        //Critical Hit
        else if(PrevCurPlayer.XtraTurn == false && AfterCurPlayer.XtraTurn == true){
            AddQ(&(*OpposingPlayer).skillQueue,5);
        }

        //Instant Force
        address P;
        P = First((*CurrentPlayer).bangunanPlayer);
        boolean Check;
        Check = true;
        while(P != Nil && Check == true){
            if(AfterCurPlayer.LevelBangunan.TI[Info(P)].B.Level == 4){
                Check = true;
            }
            P = Next(P); 
        }
        if(Check == true){
            AddQ(&(*CurrentPlayer).skillQueue,6);
        }
        //Barrage
        else if(AfterCurPlayer.JumlahBangunan == 10 && PrevCurPlayer.JumlahBangunan == 9){
            AddQ(&(*CurrentPlayer).skillQueue,7);
        }



    }


