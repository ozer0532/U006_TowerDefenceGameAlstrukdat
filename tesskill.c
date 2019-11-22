#include <stdio.h>
#include "boolean.h"
#include "queue.h"
#include "bangunan.h"
#include "listlinier.h"
#include "player.h"
#include "array.h"
#include "skill.h"


int main(){
Player P1;
Player P2;
Status PrevCurPlayer;
Status AfterCurPlayer;
Status PrevOpsPlayer;
Status AfterOpsPlayer;
int skl1, skl2;
ACUAN Semi;
BangunanTot Ba;
MakeEmptyBangunanTot(&Ba);
Ba.TI[1].B.Jpas = 10;
Ba.TI[1].B.Level = 1;
//nisialisasi(&Semi);
CreateEmptyL(&P1.bangunanPlayer);
CreateEmptyL(&P2.bangunanPlayer);
CreateEmptyQ(&P1.skillQueue,10);
CreateEmptyQ(&P2.skillQueue,10);


InsVLastL(&P1.bangunanPlayer,1);
InsVLastL(&P2.bangunanPlayer,1);
printf("Jumlah pasukan awal: %d\n", Ba.TI[1].B.Jpas);
//int Y;
//DelVFirstL(&P.bangunanPlayer,&Y);
//printf("nilai Y: %d\n", Y);
//PrevOpsPlayer.JumlahBangunan = 3;
//AfterOpsPlayer.JumlahBangunan = 2;
//PrevCurPlayer.JumlahBangunan = 9;
//AfterCurPlayer.JumlahBangunan = 10;
//PrevOpsPlayer.JumlahFort = 2;
//AfterOpsPlayer.JumlahFort = 3;
//PrevCurPlayer.JumlahTower = 2;
//AfterCurPlayer.JumlahTower = 3;
//PrevCurPlayer.XtraTurn = false;
//AfterCurPlayer.XtraTurn=true;
Sesudah(P1,P2,&AfterCurPlayer,&AfterOpsPlayer,Ba);
printf("jmlh bangunan1 %d\n", AfterCurPlayer.JumlahBangunan);
printf("level bangunan1 %d\n", AfterCurPlayer.JumlahFort);
printf("jmlh bangunan2 %d\n", AfterOpsPlayer.JumlahBangunan);
/*
GetSkill(&P1,&P2,PrevCurPlayer,PrevOpsPlayer,AfterCurPlayer,AfterOpsPlayer);
DelQ(&P1.skillQueue,&skl1);
DelQ(&P2.skillQueue,&skl2);
printf("skl: %d\n", skl1);
printf("skl2: %d\n", skl2);
//IntToSkill(skl, &P, &Semi, &Ba);
//printf("Habis Skill: %d\n", Ba.TI[1].B.Level);
/*if(P.CriticalHit == true){
    printf("hello\n");
}*/
    return 0;
}

