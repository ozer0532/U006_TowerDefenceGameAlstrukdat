#include "STATE.h"
#include "attack.h"

void move(STATE *s,Player *CP){
    address P;
    int no=1;
    int num,jum;
    P = (*CP).bangunanPlayer.First;
    printf("Daftar bangunan anda :\n");
    while(P != Nil){
        printf("%d. ",no);
        //Cetak nama bangunannya
        if (s->listbtot.TI[Info(P)].B.Jenis =='C') printf("Castle ");
        else if ((s->listbtot.TI[Info(P)].B.Jenis )=='T') printf("Tower ");
        else if ((s->listbtot.TI[Info(P)].B.Jenis )=='V') printf("Village ");
        else if ((s->listbtot.TI[Info(P)].B.Jenis )=='F') printf("Fort ");

        //Cetak lokasinya
        printf("Lokasi : (%d,%d) ",s->listbtot.TI[Info(P)].B.Lok.X,s->listbtot.TI[Info(P)].B.Lok.Y);

        //Cetak jumlah pasukannya
        printf ("Jumlah Pasukan : %d \n",s->listbtot.TI[Info(P)].B.Jpas);
        no++;
        P = Next(P);
    }
    scanf("%d",num);
    int indeks;
    address ch = (*CP).bangunanPlayer.First;
    while(--num) ch = Next(ch);
    indeks = Info(ch);
    ArrayVertex target = Neighbors(s->Hubungan,indeks);
    printf("where to move?\n");
    no = 1;
    for (int k = 1; k <= target.Neff;k++){
        printf("%d. ",no);
        //Cetak nama bangunannya
        if (s->listbtot.TI[target.TI[k]].B.Jenis =='C') printf("Castle ");
        else if ((s->listbtot.TI[target.TI[k]].B.Jenis )=='T') printf("Tower ");
        else if ((s->listbtot.TI[target.TI[k]].B.Jenis )=='V') printf("Village ");
        else if ((s->listbtot.TI[target.TI[k]].B.Jenis )=='F') printf("Fort ");

        //Cetak lokasinya
        printf("Lokasi : (%d,%d) ",s->listbtot.TI[target.TI[k]].B.Lok.X,s->listbtot.TI[Info(P)].B.Lok.Y);

        //Cetak jumlah pasukannya
        printf ("Jumlah Pasukan : %d \n",s->listbtot.TI[target.TI[k]].B.Jpas);
        no++;
    }
    int moveto;
    scanf("%d",&moveto);
    addrCol add = NeighborsList(s->Hubungan,indeks); 
    while(--moveto) add = next(add);
    int indeksmoveto = Info(add);
    printf("move how many>?\n");
    scanf("%d",&jum);
    s->listbtot.TI[indeks].B.Jpas -= jum;
    s->listbtot.TI[indeksmoveto].B.Jpas += jum;
}