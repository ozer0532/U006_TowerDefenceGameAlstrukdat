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
Ba.TI[1].B.Jpas = 40;
Ba.TI[1].B.Level = 1;
Ba.TI[1].B.Jenis = 'C';

//nisialisasi(&Semi);
CreateEmptyL(&P1.bangunanPlayer);
CreateEmptyL(&P2.bangunanPlayer);
CreateEmptyQ(&P1.skillQueue,10);
CreateEmptyQ(&P2.skillQueue,10);


InsVLastL(&P1.bangunanPlayer,1);
AddQ(&(P1.skillQueue),1); // menambah skill instant upgrade
AddQ(&(P1.skillQueue),6); // menambah skill  instatn reiforcement

DelQ(&P1.skillQueue,&skl1);
printf("skill: %d\n", skl1);
IntToSkill(skl1,&P1,&P2,&Ba); // menggunakan skill instant upgrade
DelQ(&P1.skillQueue,&skl1);
printf("skill: %d\n", skl1);
IntToSkill(skl1,&P1,&P2,&Ba); // menggunakan skill instan reiforcemonet

//seharunya level bangunan nambha 1 menjadi 2
// jumlah pasukan pada bangunan tambah 5 menjadi 15
printf("level bangunan: %d\n", Ba.TI[1].B.Level );
printf("Jumlah pasukan: %d\n", Ba.TI[1].B.Jpas);
return 0;
}