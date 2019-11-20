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
void AttackUp(ACUAN Ac, Player Pe, BangunanTot Ba) //Bonus
 /*Jika pemain mengaktifkan skill ini, maka pertahanan lawan tidak akan mempengaruhi penyerangan.
    Syarat: Pemain baru saja melakukan penyerangan ke tower lawan dan tower pemain menjadi berjumlah 3 */
    {
        
    }
void CriticalHit (){} //Bonus
    /* Syarat: Musuh baru saja melakukan skill Extra Turn
        F.S: pada bangunan yang melakukan serangan tepat selanjutnya hanya berkurang 1/2 dari jumlah seharusnya. */
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
int SkillToInt(char Skill){
   /* int No;
    No = 0;
    if(Skill == 'InstantUpgrade'){
        No = 1;
    }
    if(Skill == 'Shield'){
        No = 2;
    }
    if(Skill == 'ExtraTurn'){
        No = 3;
    }
    if(Skill == 'AttackUp')
    {
        No = 4;
    }
    if(Skill = 'CriticalHit')
    {
        No = 5;
    }
    if (Skill == 'InstantReinforcement'){
        No = 6;
    }
    if(Skill == 'Barrage'){
        No = 7;
    }
    return No;*/
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
        AttackUp(*Semi, Pe, *Ba);
    }
    if(SkillKe == 5){
        CriticalHit();
    }
    if(SkillKe == 6){
        InstantReinforcement(Pe, Ba);
    }
    if(SkillKe == 7){
        Barrage(Pe, Ba);
    }
}

void Sebelum(Player Pe, Status *St, BangunanTot Ba){
    /*KAMUS*/
    address P;

    /*ALGORITMA*/

    (*St).JumlahBangunan = NbElmtL(Pe.bangunanPlayer);

    P = First(Pe.bangunanPlayer);
    while(P != Nil){
        (*St).LevelBangunan.TI[Info(P)].B.Level = Ba.TI[Info(P)].B.Level;
        P = Next(P);
    }
    (*St).JumlahFort = 0;
    while(P != Nil){
        if(Ba.TI[Info(P)].B.Jenis == 'F'){
            (*St).JumlahFort += 1;
        }
    }
    while(P != Nil){
        if(Ba.TI[Info(P)].B.Jenis == 'T'){
            (*St).JumlahTower += 1;
        }
    }
    (*St).XtraTurn = Pe.extraTurn;
    

    
    
}
void Sesudah (Player Pe, Status *St, BangunanTot Ba){
        /*KAMUS*/
    address P;

    /*ALGORITMA*/

    (*St).JumlahBangunan = NbElmtL(Pe.bangunanPlayer);

    P = First(Pe.bangunanPlayer);
    while(P != Nil){
        (*St).LevelBangunan.TI[Info(P)].B.Level = Ba.TI[Info(P)].B.Level;
        P = Next(P);
    }
    (*St).JumlahFort = 0;
    while(P != Nil){
        if(Ba.TI[Info(P)].B.Jenis == 'F'){
            (*St).JumlahFort += 1;
        }
    }
    (*St).JumlahTower = 0;
    while(P != Nil){
        if(Ba.TI[Info(P)].B.Jenis == 'T'){
            (*St).JumlahTower += 1;
        }
    }
    (*St).XtraTurn = Pe.extraTurn;
}
void GetSkill(Player *Pe, BangunanTot Ba){
        address P;
        P = First((*Pe).bangunanPlayer);
        Status CheckSebelum;
        Status CheckSesudah;
        Sebelum(*Pe, &CheckSebelum, Ba);
        Sesudah(*Pe,&CheckSesudah, Ba);
        // Algoritma mendapatkan skill

        //shield
        if(CheckSesudah.JumlahBangunan == 2 && CheckSebelum.JumlahBangunan ==1){
            AddQ(&(*Pe).skillQueue,2);
        }
        else if((CheckSesudah.JumlahFort -1) ==  CheckSesudah.JumlahFort){
            AddQ(&(*Pe).skillQueue,3);
        }
        else if(CheckSesudah.JumlahTower == 3 && CheckSebelum.JumlahTower == 4){
            AddQ(&(*Pe).skillQueue, 4);
        }
        boolean Check;
        Check = true;
        while(P != Nil && Check == true){
            if(CheckSesudah.LevelBangunan.TI[Info(P)].B.Level == 4){
                Check = true;
            } 
        }
        if(Check == true){
            AddQ(&(*Pe).skillQueue,6);
        }
        else if(CheckSebelum.XtraTurn == false && CheckSesudah.XtraTurn == true){
            AddQ(&(*Pe).skillQueue,5);
        }
        else if(CheckSesudah.JumlahBangunan == 10 && CheckSebelum.JumlahBangunan == 9){
            AddQ(&(*Pe).skillQueue,7);
        }



    }

