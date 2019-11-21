#include "STATE.h"
#include <stdio.h>
#include "pcolor.h"



void makeemptypeta(STATE *s)
{
    for (int i = 0; i <= (*s).peta.NBrsEff;i ++){
		for (int j = 0; j <= (*s).peta.NKolEff; j ++){
            Elm((*s).peta,i,j).C = 'e';
            Elm((*s).peta,i,j).p = 0;
        }
    }
    
}

void printpeta(STATE s){
	MATRIKS p = s.peta;
	for (int i = 0; i <= p.NBrsEff;i ++){
		for (int j = 0; j <= p.NKolEff; j ++){
			if ((i == 0)||(j == 0)||(i == p.NBrsEff)||(j == p.NKolEff)){
				printf("*");
			}
			else {
				if (Elm(p,i,j).C == 'e') printf(" ");
				else 
				{
					if (Elm(p,i,j).p == 0) printf("%c",Elm(p,i,j).C);
<<<<<<< HEAD
                    else if (Elm(p,i,j).p == 1) print_blue(("%c",Elm(p,i,j).C));
=======
                    // else if (Elm(p,i,j).p == 1) printf("\x1B[31m%c\x1B[0m",Elm(p,i,j).C);
                    // else if (Elm(p,i,j).p == 2) printf("%c",Elm(p,i,j).C);
					else if (Elm(p,i,j).p == 1) print_blue(("%c",Elm(p,i,j).C));
>>>>>>> cac2320d8ff764b6509a03c85fec1841527ca878
                    else if (Elm(p,i,j).p == 2) print_red(("%c",Elm(p,i,j).C));
				}
			}
			if (j == p.NKolEff) printf("\n");
		}
	}
}