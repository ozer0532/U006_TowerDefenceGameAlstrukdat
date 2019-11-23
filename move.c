#include <stdio.h>
#include "move.h"

void move(STATE *s,Player *CP){
 // Move digunakan untuk memindahkan pasukan dari suatu bangunan ke bangunan lain milik pemain 
// Adapun bangunan yang bisa dilakukan move adalah bangunan yang terhubung dengan bangunan tersebut. \
// MOVE hanya dapat dilakukan sekali untuk tiap bangunan pada tiap gilirannya
// I.S Move belom dilakukan sama sekali
//     State harus sudah terdefinisi dan terhubung satu sama lainnya
//     Pemain harus terdefinisi
// F.S Melakukan proses move dengan ketentuan diatas
//     Menampilkan ke layar jika move berhasil ataupun jika tidak berhasil

    address P;
    int no=1;
    int num,jum;
    ACUAN A;
    Inisialisasi(&A);

    int curpla;
    curpla = CP->playerKe;

    P = (*CP).bangunanPlayer.First;
    if (P!= Nil){
        printf("Daftar bangunan anda :\n");
        while(P != Nil){
            printf("%d. ",no);
            //Cetak nama bangunannya
            if (s->listbtot.TI[Info(P)].B.Jenis =='C') printf("Castle ");
            else if ((s->listbtot.TI[Info(P)].B.Jenis )=='T') printf("Tower ");
            else if ((s->listbtot.TI[Info(P)].B.Jenis )=='V') printf("Village ");
            else if ((s->listbtot.TI[Info(P)].B.Jenis )=='F') printf("Fort ");

            //Cetak lokasinya
            printf("(%d,%d) ",s->listbtot.TI[Info(P)].B.Lok.X,s->listbtot.TI[Info(P)].B.Lok.Y);

            //Cetak jumlah pasukannya
            printf ("%d \n",s->listbtot.TI[Info(P)].B.Jpas);
            no++;
            P = Next(P);
        }
        printf ("Pilih Bangunan: "); scanf("%d",&num);
        int indeks;
        address ch = (*CP).bangunanPlayer.First;
        while(--num) ch = Next(ch);
        indeks = Info(ch);
        if (s->listbtot.TI[indeks].B.Jpas > 0){
            ArrayVertex target = Neighbors(s->Hubungan,indeks);
            int countally=0;
            for (int l =1; l <= target.Neff;l++){
                if (s->listbtot.TI[target.TI[l]].B.Milik == curpla) countally += 1;
            }
                if (countally > 0){
                printf("Daftar bangunan terdekat:\n");
                no = 1;
                for (int k = 1; k <= target.Neff;k++){
                    if (s->listbtot.TI[target.TI[k]].B.Milik == curpla){
                    printf("%d. ",no);
                    //Cetak nama bangunannya
                    if (s->listbtot.TI[target.TI[k]].B.Jenis =='C') printf("Castle ");
                    else if ((s->listbtot.TI[target.TI[k]].B.Jenis )=='T') printf("Tower ");
                    else if ((s->listbtot.TI[target.TI[k]].B.Jenis )=='V') printf("Village ");
                    else if ((s->listbtot.TI[target.TI[k]].B.Jenis )=='F') printf("Fort ");

                    //Cetak lokasinya
                    printf("(%d,%d) ",s->listbtot.TI[target.TI[k]].B.Lok.X,s->listbtot.TI[target.TI[k]].B.Lok.Y);

                    //Cetak jumlah pasukannya
                    printf ("%d \n",s->listbtot.TI[target.TI[k]].B.Jpas);
                    no++;}
                }
                
                int moveto;
                printf("move to : ");scanf("%d",&moveto);
                addrCol add = NeighborsList(s->Hubungan,indeks);
                while(moveto){
                    if(s->listbtot.TI[Info(add)].B.Milik == curpla) moveto--;
                    if (moveto) add = Next(add);
                }
                int indeksmoveto = Info(add);

                boolean valid = false;
                while(valid == false) {
                    printf("Jumlah pasukan: ");scanf("%d",&jum);
                    if (s->listbtot.TI[indeks].B.Jpas < jum) printf("More than you have\n");
                    else if ((s->listbtot.TI[indeksmoveto].B.Jpas + jum) > getM(s->listbtot.TI[indeksmoveto].B,A)) printf("The destination can't hold that much troops\n");
                    else if (jum < 0) printf("seriuslah anjir\n");
                    else valid = true;
                }
                
                s->listbtot.TI[indeks].B.Jpas -= jum;
                s->listbtot.TI[indeksmoveto].B.Jpas += jum;

                }else printf("no building to move to\n");

        } else printf("no army in the building\n");

    }

    else printf("u have no buildings\n");
}