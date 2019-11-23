#include "STATE.h"
#include <stdio.h>
#include "pcolor.h"
#include <string.h>


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
				printf("* ");
			}
			else {
				if (Elm(p,i,j).C == 'e') printf("  ");
				else 
				{
					if (Elm(p,i,j).p == 0) printf("%c ",Elm(p,i,j).C);
                    else if (Elm(p,i,j).p == 1) {print_blue(("%c",Elm(p,i,j).C));printf(" ");}
                    else if (Elm(p,i,j).p == 2) {print_red(("%c",Elm(p,i,j).C));printf(" ");}
				}
			}
			if (j == p.NKolEff) printf("\n");
		}
	}
}

SAVEDSTATE DuplicateSTATE(STATE S) {
	// KAMUS LOKAL
	SAVEDSTATE P;
	address Q;

	// ALGORITMA
	// Buat bagian global
	for (int i = 0; i < IdxMax; i++) {
		P.daftarBangunan[i] = S.listbtot.TI[i+1].B;
	}
	strcpy(P.lastaction, S.lastaction);

	// Buat Player1
	Q = First(S.P1.bangunanPlayer);
	for (int i = 0; i < 30; i++) {
		if (Q != Nil) {
			P.bangunanPlayer1[i] = Info(Q);
		} else {
			P.bangunanPlayer1[i] = ElUndef;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (i < S.P1.skillQueue.TAIL) {
			P.skillPlayer1[i] = S.P1.skillQueue.T[i+1];
		} else {
			P.skillPlayer1[i] = ElUndef;
		}
	}
	P.shieldPlayer1 = S.P1.shieldCooldown;
	P.extraTurnPlayer1 = S.P1.extraTurn;
	P.attackUpPlayer1 = S.P1.AttackUp;
	P.critHitPlayer1 = S.P1.CriticalHit;
	
	// Buat Player2
	Q = First(S.P2.bangunanPlayer);
	for (int i = 0; i < 30; i++) {
		if (Q != Nil) {
			P.bangunanPlayer2[i] = Info(Q);
		} else {
			P.bangunanPlayer2[i] = ElUndef;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (i < S.P2.skillQueue.TAIL) {
			P.skillPlayer2[i] = S.P2.skillQueue.T[i+1];
		} else {
			P.skillPlayer2[i] = ElUndef;
		}
	}
	P.shieldPlayer2 = S.P2.shieldCooldown;
	P.extraTurnPlayer2 = S.P2.extraTurn;
	P.attackUpPlayer2 = S.P2.AttackUp;
	P.critHitPlayer2 = S.P2.CriticalHit;
}

void SETSTATE(STATE * S, SAVEDSTATE s) {
	// KAMUS LOKAL
	int i;

	// ALGORITMA
	// Buat bagian global
	for (int i = 0; i < IdxMax; i++) {
		S->listbtot.TI[i+1].B = s.daftarBangunan[i];
	}
	strcpy(S->lastaction, s.lastaction);

	// Buat P1
	i = 0;
	while(!IsEmptyL(S->P1.bangunanPlayer)) {
		DelVFirstL(&(S->P1.bangunanPlayer), &i);
	}
	i = 0;
	while (i < 30 && s.bangunanPlayer1[i] != ElUndef) {
		InsVLastL(&(S->P1.bangunanPlayer), s.bangunanPlayer1[i]);
	}
	i = 0;
	CreateEmptyQ(&(S->P1.skillQueue), 10);
	while (i < 10 && s.skillPlayer1[i] != ElUndef) {
		AddQ(&(S->P1.skillQueue), s.skillPlayer1[i]);
	}
	S->P1.shieldCooldown = s.shieldPlayer1;
	S->P1.extraTurn = s.extraTurnPlayer1;
	S->P1.AttackUp = s.attackUpPlayer1;
	S->P1.CriticalHit = s.critHitPlayer1;
	
	// Buat P2
	i = 0;
	while(!IsEmptyL(S->P2.bangunanPlayer)) {
		DelVFirstL(&(S->P2.bangunanPlayer), &i);
	}
	i = 0;
	while (i < 30 && s.bangunanPlayer2[i] != ElUndef) {
		InsVLastL(&(S->P2.bangunanPlayer), s.bangunanPlayer2[i]);
	}
	i = 0;
	CreateEmptyQ(&(S->P2.skillQueue), 10);
	while (i < 10 && s.skillPlayer2[i] != ElUndef) {
		AddQ(&(S->P2.skillQueue), s.skillPlayer2[i]);
	}
	S->P2.shieldCooldown = s.shieldPlayer2;
	S->P2.extraTurn = s.extraTurnPlayer2;
	S->P2.AttackUp = s.attackUpPlayer2;
	S->P2.CriticalHit = s.critHitPlayer2;
}
