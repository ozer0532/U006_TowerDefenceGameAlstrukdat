//ADT ATTACK

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "attack.h"
#include <math.h>
#include "STATE.h"


void MakeEmptyarr (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    (*T).arr = (int*) malloc ((101)*sizeof(int));
    //mulai dari 1
    for (int i=1;i<=100;i++)
    {
        (*T).arr[i]= IdxUndef;
    }
    (*T).Neff=0;
}

address AlokasiLTambahBangunan (BangunanTot *B, IdxType Index)
//Saat ingin Alokasi / Buat List Liniear
//F.S address di BangunanTOt sudah terisi oleh address dari Alokasi Index di List Linier
{
    address Pe;
    Pe=AlokasiL(Index);
    (*B).TI[Index].P = Pe;
    return (Pe);
}

void AddAsLastElarr (TabInt * T, int X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
    (*T).arr[NbElmtarr(*T)+1]=X;
    (*T).Neff=(*T).Neff+1;
}

void Dealokasiarr(TabInt *T)
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */
{
    free((*T).arr);
    (*T).Neff=0;
}


int NbElmtarr (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
    int a;
    if ((T).Neff ==0) 
    {
        a=0;
    }
    else
    {
        (a=T.Neff);
    }
    return a;
}


boolean Searcharr (TabInt T, int X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
    int i;
    boolean Found;
    Found = false;
    i=IdxMin;
    if ((T).Neff ==0) {
        Found = false;
    }
    else
    {
        while ((i<=NbElmtarr(T))&& (!(Found))){
            if (T.arr[i]==X){
                Found = true;
            }
            else{
                i=i+1;
            }         
        }
    }

    if (Found == true){
        return true;
    }
    else{
        return false;
    }
}

void AddToLPemain (Player *Pe, Player *Pm, STATE *T,  IdxType Idx, int JPasNetto)
//Membuat Bangunan menjadi berubah kepemilikan
//Proses: Misal Bangunan milik P1 baru dikuasai maka LIST L1 berkurang 1  LIST L2 bertambah, Bangunan TOtal tetap
//F.S Bangunan sudah beralih milik dan sudah di RESETBANGUNAN
{
    address PP;
    if ((*T).listbtot.TI[Idx].B.Milik==0)
    {
        
        PP=AlokasiL(Idx);
        (*T).listbtot.TI[Idx].P = PP;
        ResetBANGUNAN(&((*T).listbtot.TI[Idx].B),JPasNetto,(*Pe).playerKe);
        (*T).peta.Mem[(*T).listbtot.TI[Idx].B.Lok.X][(*T).listbtot.TI[Idx].B.Lok.Y].p=(*Pe).playerKe;


        //InsertLastL(&La,PP);
        InsVLastL(&(*Pe).bangunanPlayer,Idx);
        

    }
    else
    {
        PP=SearchL((*Pm).bangunanPlayer,Idx);
        ResetBANGUNAN(&(*T).listbtot.TI[Idx].B,JPasNetto,(*Pe).playerKe);
        (*T).peta.Mem[(*T).listbtot.TI[Idx].B.Lok.X][(*T).listbtot.TI[Idx].B.Lok.Y].p=(*Pe).playerKe;
        InsVLastL(&(*Pe).bangunanPlayer,Idx);
        Del1Urut(&(*T).listbtot,PP,Idx,JPasNetto,(*Pe).playerKe);
        DelPL(&(*Pm).bangunanPlayer,Idx);
    }
}

void MakeBangunanPemain (Player *Pe, Player *Pm, STATE *T,  IdxType Idx, int Jmlh, boolean AttackUp)
//INPUTAN Jmlh Awal harus Valid
//Artinya Jmlh harus lebih dari 0 namun harus kurang dari sama dengan JPas Daftar Bangunan
//Mengambil alih bangunan menjadi milik player "PEMAINKE"
//I.S Jmlh adalah JUMLAH PASUKAN Bruto
//Pros Check dahulu dengan IsBangunanNon Jika True, Maka TIDAK ADA RESET KEPEMILIKAN, 
// Search
//F.S Jika jumlah pasukkan kurang (Pe.L1.JPas< Pe.L1.JenisBangunanTot[1].) maka Pe.L1.Jpas-Jmlh dan bangunan tidak diambil alih
//    Jika jumlah pasukkan le
{

    address P;
    int JHDiserang;
    ACUAN Ac;

    if (AttackUp==false) {
        Inisialisasi(&Ac);
    }
    else {
        InisialisasiAttackUp(&Ac);
    }
    List La= (*Pe).bangunanPlayer;
    List Lb= (*Pm).bangunanPlayer;

    
    //Saat Belum dikuasai siapa2. Maka Minimal yang harus diserang adalah Sebanyak U
    //Jika Jumlahnya lebih dari diserang

    if (IsAdaPertahanan((*T).listbtot.TI[Idx].B))
    {
        
        if ((*T).listbtot.TI[Idx].B.Milik==0) //Kalau Bangunannya belom dikuasai siapa2
        {
            JHDiserang=(*T).listbtot.TI[Idx].B.Jpas;
            if ( (int)floor((3*Jmlh/4))>=JHDiserang)
            {
                
                //Jika belom menyentuh nilai max
                if (JumlahPasukanValid((*T).listbtot.TI[Idx].B, (int)floor(3*Jmlh/4)-JHDiserang))
                {
                    AddToLPemain(Pe, Pm,T,Idx,(int)floor(3*Jmlh/4)-JHDiserang);
                    printf("Bangunan menjadi milikmu. \n");
                }
                
                //Jika sudah menyentuh nilai max
                else
                {
                    AddToLPemain(Pe, Pm,T,Idx,CariDariAcuan(Ac,(*T).listbtot.TI[Idx].B.Jenis,(*T).listbtot.TI[Idx].B.Level,'M'));
                    printf("Bangunan menjadi milikmu. \n");
                }
            }
            //Jika jumlahnyaa kurang dari diserang
            else 
            {
                (*T).listbtot.TI[Idx].B.Jpas = JHDiserang-(int)floor(3*Jmlh/4);
                printf("Bangunan gagal direbut.\n");
            }
        }
         //Saat bangunan sudah dikuasasi Pemain yang lain
         else
         {
            if((*Pe).AttackUp == true || (*Pe).CriticalHit == true){ //Pemain mengaktifkan  attack up
                if((*Pe).CriticalHit == true){
                    JHDiserang= (int)floor(((*T).listbtot.TI[Idx].B.Jpas)/2);
                    if ( Jmlh>=JHDiserang)
                    {
                        //Jika belom menyentuh nilai max
                        if (JumlahPasukanValid((*T).listbtot.TI[Idx].B, Jmlh-JHDiserang))
                        {
                            AddToLPemain(Pe,Pm,T,Idx,Jmlh-JHDiserang);
                            printf("Bangunan lawan menjadi milikmu. \n");
                        }
                        
                        //Jika sudah menyentuh nilai max
                        else
                        {
                            AddToLPemain(Pe,Pm,T,Idx,CariDariAcuan(Ac,(*T).listbtot.TI[Idx].B.Jenis,(*T).listbtot.TI[Idx].B.Level,'M'));  
                            printf("Bangunan lawan menjadi milikmu. \n");
                        }
                    }
                    else
                    {
                        printf("Bangunan gagal direbut.\n");
                        (*T).listbtot.TI[Idx].B.Jpas=JHDiserang- Jmlh;
                        
                    }

                }
                else{
                    JHDiserang=(*T).listbtot.TI[Idx].B.Jpas;
                    if ( Jmlh>=JHDiserang)
                    {
                        //Jika belom menyentuh nilai max
                        if (JumlahPasukanValid((*T).listbtot.TI[Idx].B, Jmlh-JHDiserang))
                        {
                            AddToLPemain(Pe,Pm,T,Idx,Jmlh-JHDiserang);
                            printf("Bangunan lawan menjadi milikmu. \n");
                        }
                        
                        //Jika sudah menyentuh nilai max
                        else
                        {
                            AddToLPemain(Pe,Pm,T,Idx,CariDariAcuan(Ac,(*T).listbtot.TI[Idx].B.Jenis,(*T).listbtot.TI[Idx].B.Level,'M'));  
                            printf("Bangunan lawan menjadi milikmu. \n");
                        }
                    }
                    else
                    {
                        printf("Bangunan gagal direbut.\n");
                        (*T).listbtot.TI[Idx].B.Jpas=JHDiserang- Jmlh;
                        
                    }
                }

            }
            else{
             
                JHDiserang=(*T).listbtot.TI[Idx].B.Jpas;
                if ( (int)floor(3/4)*Jmlh>=JHDiserang)
                {
                    //Jika belom menyentuh nilai max
                    if (JumlahPasukanValid((*T).listbtot.TI[Idx].B, (int)floor(3*Jmlh/4)-JHDiserang))
                    {
                        AddToLPemain(Pe,Pm,T,Idx,(int)floor(3*Jmlh/4)-JHDiserang);
                        
                        printf("Bangunan lawan menjadi milikmu. \n");
                    }
                    
                    //Jika sudah menyentuh nilai max
                    else
                    {
                        AddToLPemain(Pe,Pm,T,Idx,CariDariAcuan(Ac,(*T).listbtot.TI[Idx].B.Jenis,(*T).listbtot.TI[Idx].B.Level,'M'));
                        printf("Bangunan lawan menjadi milikmu. \n");
                    }
                }
                else
                {
                    printf("Bangunan gagal direbut.\n");
                    (*T).listbtot.TI[Idx].B.Jpas=JHDiserang- (int)floor(3*Jmlh/4);
                    
                }
            }
        }
         
    }
    else
    {
        if ((*T).listbtot.TI[Idx].B.Milik==0) //Kalau Bangunannya belom dikuasai siapa2
        {
            JHDiserang=(*T).listbtot.TI[Idx].B.Jpas;
            if ( Jmlh>=JHDiserang)
            {
                //Jika belom menyentuh nilai max
                if (JumlahPasukanValid((*T).listbtot.TI[Idx].B,Jmlh-JHDiserang))
                {
                    AddToLPemain(Pe,Pm,T,Idx,Jmlh-JHDiserang);
                    printf("Bangunan menjadi milikmu. \n");
                }
                
                //Jika sudah menyentuh nilai max
                else
                {
                    AddToLPemain(Pe,Pm,T,Idx,CariDariAcuan(Ac,(*T).listbtot.TI[Idx].B.Jenis,(*T).listbtot.TI[Idx].B.Level,'M'));
                    printf("Bangunan menjadi milikmu. \n");
                }
            }
            //Jika jumlahnyaa kurang dari diserang
            else 
            {
                printf("Bangunan gagal direbut.\n");
                (*T).listbtot.TI[Idx].B.Jpas=JHDiserang- Jmlh;
            }
         }
         //Saat bangunan sudah dikuasasi Pemain yang laain
         else
         {
            if((*Pm).shieldCooldown > 0){
                if((*Pe).CriticalHit == true){
                    JHDiserang= (int)floor(((*T).listbtot.TI[Idx].B.Jpas)/2);
                    if ( Jmlh>=JHDiserang)
                    {
                        //Jika belom menyentuh nilai max
                        if (JumlahPasukanValid((*T).listbtot.TI[Idx].B, Jmlh-JHDiserang))
                        {
                            AddToLPemain(Pe,Pm,T,Idx,Jmlh-JHDiserang);
                            printf("Bangunan lawan menjadi milikmu. \n");
                        }
                        
                        //Jika sudah menyentuh nilai max
                        else
                        {
                            AddToLPemain(Pe,Pm,T,Idx,CariDariAcuan(Ac,(*T).listbtot.TI[Idx].B.Jenis,(*T).listbtot.TI[Idx].B.Level,'M'));  
                            printf("Bangunan lawan menjadi milikmu. \n");
                        }
                    }
                    else
                    {
                        printf("Bangunan gagal direbut.\n");
                        (*T).listbtot.TI[Idx].B.Jpas=JHDiserang- Jmlh;
                        
                    }

                }else{
                    JHDiserang=(*T).listbtot.TI[Idx].B.Jpas;
                    if ( (int)floor(3/4)*Jmlh>=JHDiserang)
                    {
                        //Jika belom menyentuh nilai max
                        if (JumlahPasukanValid((*T).listbtot.TI[Idx].B, (int)floor(3*Jmlh/4)-JHDiserang))
                        {
                            AddToLPemain(Pe,Pm,T,Idx,(int)floor(3*Jmlh/4)-JHDiserang);
                            
                            printf("Bangunan lawan menjadi milikmu. \n");
                        }
                        
                        //Jika sudah menyentuh nilai max
                        else
                        {
                            AddToLPemain(Pe,Pm,T,Idx,CariDariAcuan(Ac,(*T).listbtot.TI[Idx].B.Jenis,(*T).listbtot.TI[Idx].B.Level,'M'));
                            printf("Bangunan lawan menjadi milikmu. \n");
                        }
                    }
                    else
                    {
                        printf("Bangunan gagal direbut.\n");
                        (*T).listbtot.TI[Idx].B.Jpas=JHDiserang- (int)floor(3*Jmlh/4);
                        
                    }
                }
            }else{
                if((*Pe).CriticalHit == true){
                    JHDiserang= (int)floor(((*T).listbtot.TI[Idx].B.Jpas)/2);
                    if ( Jmlh>=JHDiserang)
                    {
                        //Jika belom menyentuh nilai max
                        if (JumlahPasukanValid((*T).listbtot.TI[Idx].B, Jmlh-JHDiserang))
                        {
                            AddToLPemain(Pe,Pm,T,Idx,Jmlh-JHDiserang);
                            printf("Bangunan lawan menjadi milikmu. \n");
                        }
                        
                        //Jika sudah menyentuh nilai max
                        else
                        {
                            AddToLPemain(Pe,Pm,T,Idx,CariDariAcuan(Ac,(*T).listbtot.TI[Idx].B.Jenis,(*T).listbtot.TI[Idx].B.Level,'M'));  
                            printf("Bangunan lawan menjadi milikmu. \n");
                        }
                    }
                    else
                    {
                        printf("Bangunan gagal direbut.\n");
                        (*T).listbtot.TI[Idx].B.Jpas=JHDiserang- Jmlh;
                        
                    }

                }else{
                    JHDiserang=(*T).listbtot.TI[Idx].B.Jpas;
                    if ( Jmlh>=JHDiserang)
                    {
                        //Jika belom menyentuh nilai max
                        if (JumlahPasukanValid((*T).listbtot.TI[Idx].B, Jmlh-JHDiserang))
                        {
                            AddToLPemain(Pe,Pm,T,Idx,Jmlh-JHDiserang);
                            printf("Bangunan lawan menjadi milikmu. \n");
                        }
                        
                        //Jika sudah menyentuh nilai max
                        else
                        {
                            AddToLPemain(Pe,Pm,T,Idx,CariDariAcuan(Ac,(*T).listbtot.TI[Idx].B.Jenis,(*T).listbtot.TI[Idx].B.Level,'M'));  
                            printf("Bangunan lawan menjadi milikmu. \n");
                        }
                    }
                    else
                    {
                        printf("Bangunan gagal direbut.\n");
                      
                      (*T).listbtot.TI[Idx].B.Jpas=JHDiserang- Jmlh;
                    }
                }
             }
         }
    }   
}

void CetakDaftarBangunan (BangunanTot T, Player Pe, boolean *bol)
//Mencetak daftar bangunan dari pemain 1
//I.S L adalah List1 YANG SUDAH TERDEFINISI dimana Info(L).Milik=1 
//F.S Tercetak ke layar daftar bangunan dari player bersangkutan
{
    int N;
    address P;
    int no=1; int n=0;
    boolean Empty=true;
    
    printf("Daftar bangunan:\n");

    P=First(Pe.bangunanPlayer);
    if (IsEmptyL(Pe.bangunanPlayer)) {
        printf("Kamu belom punya bangunan\n");
    }
    else {
        Empty= false;
    }


    if(Empty==false) {
        while((P)!=Nil){
 
            printf("%d. ",no);
            //Cetak nama bangunannya
            if (T.TI[Info(P)].B.Jenis =='C') {printf("Castle ");}
            else if ((T.TI[Info(P)].B.Jenis )=='T') {printf("Tower ");}
            else if ((T.TI[Info(P)].B.Jenis )=='V') {printf("Village ");}
            else if ((T.TI[Info(P)].B.Jenis )=='F') {printf("Fort ");}

            //Cetak lokasinya
            printf("(%d,%d) ",T.TI[Info(P)].B.Lok.X,T.TI[Info(P)].B.Lok.Y);

            //Cetak jumlah pasukannya
            printf ("%d ",T.TI[Info(P)].B.Jpas);

            if (T.TI[Info(P)].B.Jpas==0) {
                n=n+1;
            }

            //cetak level
            printf("lv. %d\n", T.TI[Info(P)].B.Level);

            no++;
            P=Next(P);
        }

        if (n==no-1)
        {
            printf("Kamu tidak punya bangunan yang dapat digunakan untuk menyerang!!\n");
            *bol=false;

        }
        else {
            *bol=true;
        }
    }
}


void Attack(Graph G, STATE *T, Player *Pe,  Player *Pm, TabInt *Tab, boolean AttackUp)
//Menerima masukkan daftar bangunan dan melakukkan mekanisme Attack
//I.S Attack belom dilakukan
//F.S Attack sudah dilakukan dengan menggunakan mekanisme dimana
//1. Akan mendapatkan jumlah Pasukan yang diinginkan(JPas Netto)
//2. jumlah pasukkan netto yang sudah terdefinisi dimasukkan ke dalam procedure MakeBangunanPemain
//3. Attack dilakukan dan mengeluarkan output kelayar juka berhasil ataupun gagal

{
    int N,M,Pas;
    address P;
    ArrayVertex A;
    boolean bol;
    int j;

    
    CetakDaftarBangunan((*T).listbtot,*Pe,&bol);
    
    int no=1;
    if (bol==true) {
        printf("Bangunan yang digunakan untuk menyerang: ");
        if ((First((*Pe).bangunanPlayer))!=Nil) {
            scanf("%d",&N);

            
        //Validasi inputan pengguna
        while (N<=0 || N>NbElmtL((*Pe).bangunanPlayer)) {
            printf("Inputan kamu salah\n");
            printf("Bangunan yang digunakan untuk menyerang: ");
            scanf("%d",&N);
        }

        P = First((*Pe).bangunanPlayer);
        int i = 1;
        while (i < N && P != Nil) {
            P = Next(P);
            i++;
            }
        }
        else {
            printf("Bangunan tidak ada ~~\n");
        }

        if (Searcharr((*Tab),N))
        {
            printf("Kamu tidak bisa menyerang dengan bangunan ini lagi\n");
        }
        else { 

            A = (Neighbors(G,Info(P)));
            if (A.Neff == 0) {
                printf("Tidak ada bangunan yang dapat diserang\n");
            } else {
                    //Masukin nilai Index hubung ke array
                    printf("Bangunan yang dapat diserang:\n");
                    for (int j=1;j<=A.Neff;j++) {
                        if (A.TI[j]!=0 && (*T).listbtot.TI[A.TI[j]].B.Milik!=(*Pe).playerKe) {
                            printf("%d. ",no);
                                
                            //Cetak nama bangunannya
                            if ((*T).listbtot.TI[A.TI[j]].B.Jenis =='C') {printf("Castle ");}
                            else if (((*T).listbtot.TI[A.TI[j]].B.Jenis )=='T') {printf("Tower ");}
                            else if (((*T).listbtot.TI[A.TI[j]].B.Jenis )=='V') {printf("Village ");}
                            else if (((*T).listbtot.TI[A.TI[j]].B.Jenis )=='F') {printf("Fort ");}

                            //Cetak lokasinya
                            printf("(%d,%d) ",(*T).listbtot.TI[A.TI[j]].B.Lok.X,(*T).listbtot.TI[A.TI[j]].B.Lok.Y);

                            //Cetak jumlah pasukannya
                            printf ("%d ",(*T).listbtot.TI[A.TI[j]].B.Jpas);

                            //cetak level
                            printf("lv. %d\n", (*T).listbtot.TI[A.TI[j]].B.Level);
                            no++;
                        }
                    }
                        
                } 
                
                
                printf("Bangunan yang diserang: ");
                scanf("%d",&M);
                int j;
                
                //Validasi inputan pengguna
                while (M<=0 || M>=no) {
                    printf("Masukkan input salah\n");
                    printf("Bangunan yang diserang: ");
                    scanf("%d",&M);
                }

                j=1;
                while(j<=A.Neff && M!=0) {
                    if (A.TI[j]!=0 && (*T).listbtot.TI[A.TI[j]].B.Milik!=(*Pe).playerKe) {
                        M=M-1;
                    }
                    if (M!=0){
                        j++;
                    }
                }

                printf("Jumlah pasukan: ");
                scanf("%d",&Pas);

                //Check apakah jumlah pasukan valid atau tidak
                while ((*T).listbtot.TI[Info(P)].B.Jpas < Pas || Pas<0){
                    printf("Masukan jumlah pasukan salah ~~\n");
                    printf("Jumlah pasukan: ");
                    scanf("%d",&Pas);
                }
        
                MakeBangunanPemain(Pe,Pm,T,A.TI[j],Pas,AttackUp);
                (*T).listbtot.TI[Info(P)].B.Jpas -= Pas;
                AddAsLastElarr(Tab,N);
                
        }
    }
    else {
        //Do Nothing
    }
}


void UpdateStorageTakNol (Player *Pe, Player *Pm, BangunanTot B) 
//I.S Storage akan banyak yang berisi nol JPas
//F.S Storage sudah bersih dan tidak berisi nol JPas
{
    address X;
    address P=(*Pe).bangunanPlayer.First;
        if (B.TI[(Info(P))].B.Jpas==0){
            DelFirstL(&(*Pe).bangunanPlayer,&X);
        }
        else {
            P=Next(P);
            while(P!=Nil) {
                while((B.TI[(Info(Next(P)))].B.Jpas!=0)&&(P!=Nil))
                {
                    P=Next(P);
                }
                DelAfterL(&(*Pe).bangunanPlayer,&X,P);
                P=Next(P);
            }
        }
    address P0=(*Pm).bangunanPlayer.First;
        if (B.TI[(Info(P0))].B.Jpas==0){
            DelFirstL(&(*Pm).bangunanPlayer,&X);
        }
        else {
            P0=Next(P0);
            while(P0!=Nil) {
                while((B.TI[(Info(Next(P0)))].B.Jpas!=0)&&(P0!=Nil))
                {
                    P0=Next(P0);
                }
                DelAfterL(&(*Pe).bangunanPlayer,&X,P0);
                P0=Next(P0);
            }
        }
 }



