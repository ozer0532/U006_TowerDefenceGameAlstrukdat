#include "bangunan.h"
#include <stdio.h>

void Inisialisasi(ACUAN *Ac)
{
    //ACUAN Referensi
    (*Ac).C[1].A=10;
    (*Ac).C[1].M=40;
    (*Ac).C[1].P=0;
    (*Ac).C[1].U=40;
    (*Ac).C[2].A=15;
    (*Ac).C[2].M=60;
    (*Ac).C[2].P=0;
    (*Ac).C[3].A=20;
    (*Ac).C[3].M=80;
    (*Ac).C[3].P=0;
    (*Ac).C[4].A=25;
    (*Ac).C[4].M=100;
    (*Ac).C[4].P=0;

    (*Ac).T[1].A=5;
    (*Ac).T[1].M=20;
    (*Ac).T[1].P=1;
    (*Ac).T[1].U=30;
    (*Ac).T[2].A=10;
    (*Ac).T[2].M=30;
    (*Ac).T[2].P=1;
    (*Ac).T[3].A=20;
    (*Ac).T[3].M=40;
    (*Ac).T[3].P=1;
    (*Ac).T[4].A=30;
    (*Ac).T[4].M=50;
    (*Ac).T[4].P=1;

    (*Ac).F[1].A=10;
    (*Ac).F[1].M=20;
    (*Ac).F[1].P=0;
    (*Ac).F[1].U=80;
    (*Ac).F[2].A=20;
    (*Ac).F[2].M=40;
    (*Ac).F[2].P=0;
    (*Ac).F[3].A=30;
    (*Ac).F[3].M=60;
    (*Ac).F[3].P=1;
    (*Ac).F[4].A=40;
    (*Ac).F[4].M=80;
    (*Ac).F[4].P=1;

    (*Ac).V[1].A=5;
    (*Ac).V[1].M=20;
    (*Ac).V[1].P=0;
    (*Ac).V[1].U=20;
    (*Ac).V[2].A=10;
    (*Ac).V[2].M=30;
    (*Ac).V[2].P=0;
    (*Ac).V[3].A=15;
    (*Ac).V[3].M=40;
    (*Ac).V[3].P=0;
    (*Ac).V[4].A=30;
    (*Ac).V[4].M=50;
    (*Ac).V[4].P=0;
}


int CariDariAcuan (ACUAN Ac, char Jenis, int Lvl, char AMPU)
//I.S Acuan harus sudah di INISIALISASIKAN
//F.S Keluaran berupa integer
{
    if (Jenis=='C'&& Lvl==1 && AMPU=='A') {return (Ac.C[1].A);}
    if (Jenis=='C'&& Lvl==1 && AMPU=='M') {return (Ac.C[1].M);}
    if (Jenis=='C'&& Lvl==1 && AMPU=='P') {return (Ac.C[1].P);}
    if (Jenis=='C'&& Lvl==1 && AMPU=='U') {return (Ac.C[1].U);}

    if (Jenis=='C'&& Lvl==2 && AMPU=='A') {return (Ac.C[2].A);}
    if (Jenis=='C'&& Lvl==2 && AMPU=='M') {return (Ac.C[2].M);}
    if (Jenis=='C'&& Lvl==2 && AMPU=='P') {return (Ac.C[2].P);}

    if (Jenis=='C'&& Lvl==3&& AMPU=='A') {return (Ac.C[3].A);}
    if (Jenis=='C'&& Lvl==3&& AMPU=='M') {return (Ac.C[3].M);}
    if (Jenis=='C'&& Lvl==3&& AMPU=='P') {return (Ac.C[3].P);}

    if (Jenis=='C'&& Lvl==4&& AMPU=='A') {return (Ac.C[4].A);}
    if (Jenis=='C'&& Lvl==4&& AMPU=='M') {return (Ac.C[4].M);}
    if (Jenis=='C'&& Lvl==4&& AMPU=='P') {return (Ac.C[4].P);}




    if (Jenis=='T'&& Lvl==1 && AMPU=='A') {return (Ac.T[1].A);}
    if (Jenis=='T'&& Lvl==1 && AMPU=='M') {return (Ac.T[1].M);}
    if (Jenis=='T'&& Lvl==1 && AMPU=='P') {return (Ac.T[1].P);}
    if (Jenis=='T'&& Lvl==1 && AMPU=='U') {return (Ac.T[1].U);}

    if (Jenis=='T'&& Lvl==2 && AMPU=='A') {return (Ac.T[2].A);}
    if (Jenis=='T'&& Lvl==2 && AMPU=='M') {return (Ac.T[2].M);}
    if (Jenis=='T'&& Lvl==2 && AMPU=='P') {return (Ac.T[2].P);}

    if (Jenis=='T'&& Lvl==3&& AMPU=='A') {return (Ac.T[3].A);}
    if (Jenis=='T'&& Lvl==3&& AMPU=='M') {return (Ac.T[3].M);}
    if (Jenis=='T'&& Lvl==3&& AMPU=='P') {return (Ac.T[3].P);}

    if (Jenis=='T'&& Lvl==4&& AMPU=='A') {return (Ac.T[4].A);}
    if (Jenis=='T'&& Lvl==4&& AMPU=='M') {return (Ac.T[4].M);}
    if (Jenis=='T'&& Lvl==4&& AMPU=='P') {return (Ac.T[4].P);}

    

     if (Jenis=='F'&& Lvl==1 && AMPU=='A') {return (Ac.F[1].A);}
    if (Jenis=='F'&& Lvl==1 && AMPU=='M') {return (Ac.F[1].M);}
    if (Jenis=='F'&& Lvl==1 && AMPU=='P') {return (Ac.F[1].P);}
    if (Jenis=='F'&& Lvl==1 && AMPU=='U') {return (Ac.F[1].U);}

    if (Jenis=='F'&& Lvl==2 && AMPU=='A') {return (Ac.F[2].A);}
    if (Jenis=='F'&& Lvl==2 && AMPU=='M') {return (Ac.F[2].M);}
    if (Jenis=='F'&& Lvl==2 && AMPU=='P') {return (Ac.F[2].P);}

    if (Jenis=='F'&& Lvl==3&& AMPU=='A') {return (Ac.F[3].A);}
    if (Jenis=='F'&& Lvl==3&& AMPU=='M') {return (Ac.F[3].M);}
    if (Jenis=='F'&& Lvl==3&& AMPU=='P') {return (Ac.F[3].P);}

    if (Jenis=='F'&& Lvl==4&& AMPU=='A') {return (Ac.F[4].A);}
    if (Jenis=='F'&& Lvl==4&& AMPU=='M') {return (Ac.F[4].M);}
    if (Jenis=='F'&& Lvl==4&& AMPU=='P') {return (Ac.F[4].P);}


    if (Jenis=='V'&& Lvl==1 && AMPU=='A') {return (Ac.V[1].A);}
    if (Jenis=='V'&& Lvl==1 && AMPU=='M') {return (Ac.V[1].M);}
    if (Jenis=='V'&& Lvl==1 && AMPU=='P') {return (Ac.V[1].P);}
    if (Jenis=='V'&& Lvl==1 && AMPU=='U') {return (Ac.V[1].U);}

    if (Jenis=='V'&& Lvl==2 && AMPU=='A') {return (Ac.V[2].A);}
    if (Jenis=='V'&& Lvl==2 && AMPU=='M') {return (Ac.V[2].M);}
    if (Jenis=='V'&& Lvl==2 && AMPU=='P') {return (Ac.V[2].P);}

    if (Jenis=='V'&& Lvl==3&& AMPU=='A') {return (Ac.V[3].A);}
    if (Jenis=='V'&& Lvl==3&& AMPU=='M') {return (Ac.V[3].M);}
    if (Jenis=='V'&& Lvl==3&& AMPU=='P') {return (Ac.V[3].P);}

    if (Jenis=='V'&& Lvl==4&& AMPU=='A') {return (Ac.V[4].A);}
    if (Jenis=='V'&& Lvl==4&& AMPU=='M') {return (Ac.V[4].M);}
    if (Jenis=='V'&& Lvl==4&& AMPU=='P') {return (Ac.V[4].P);}

}

void MakeBangunanEmpty (BANGUNAN *B)
//Inisialisasi Bangunan dengan membuat semua elemennya 0
{
    (*B).Milik=0;
    (*B).Jenis='X';
    (*B).Jpas=0;
    (*B).Level=0;
    (*B).Lok.X=0;
    (*B).Lok.Y=0;
}


BANGUNAN MakeBANGUNAN(BANGUNAN *B, int Milik, int Jpas, int Level, char Jenis,  POINT Lok)
//Merancang BANGUNAN dari komponen-komponen yang ada
// I.S BANGUNAN terinisialisasi lewat MakeBangunanEmpty
// F.S BANGUNAN terdefinisi
{
    (*B).Milik=Milik;
    (*B).Jenis=Jenis;
    (*B).Jpas=JPas;
    (*B).Level=Level;
    (*B).Lok.X=Lok.X;
    (*B).Lok.Y=Lok.Y;
    return BANGUNAN;
}

boolean JumlahPasukanValid (BANGUNAN B, int JPas)
//True jika jumlah pasukan  <=M
{
    ACUAN A;
    Inisialisasi(&A);
    return ((JPas <= CariDariAcuan(A,B.Jenis,B.Level,'M')) && (JPas >=0));
}

void ResetBangunan(BANGUNAN *B, int JPasAwal, int Milik)
//Reset bangunan dilakukan saat bangunan diambil alih
{
    if (JumlahPasukanValid(*B,JPasAwal))
    {
        (*B).Milik=Milik;
        (*B).Jpas=JPasAwal;
        (*B).Level=1;
    }
}