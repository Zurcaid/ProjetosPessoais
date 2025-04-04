#include <stdio.h>

int i, i2;
#define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
#define h 7

//JOGO DE XADREZ
// PECAS: PEAO = P; CAVALO = C; TORRE = T; BISPO = B; DAMA = D; REI = R.
// PECAS BRANCAS TEM A LETRA B COMO INDICADOR, ENQUANTO AS PRETAS TEM P.
char *EV = "--"; // ESPACO VAZIO

char *PP = "PP"; // PEAO PRETO
char *BP = "BP"; // BISPO PRETO
char *CP = "CP"; // CAVALO PRETO
char *TP = "TP"; // TORRE PRETA
char *DP = "DP"; // DAMA PRETA
char *RP = "RP"; // REI PRETO

char *PB = "PB"; // PEAO BRANCO
char *BB = "BB"; // BISPO BRANCO
char *CB = "CB"; // CAVALO BRANCO
char *TB = "TB"; // TORRE BRANCA
char *DB = "DB"; // DAMA BRANCA
char *RB = "RB"; // REI BRANCO

char *tabuleiro[8][8];

void tabuleiroInit(){
	for(i = 0; i < 8; i++){
		for(i2 = 0; i2 < 8; i2++){
			tabuleiro[i][i2] = EV;
		}
	}
	// PECAS PRETAS
    for(i = 0; i <= 8; i++){
        tabuleiro[i][1] = PP; // PEOES
    }
    tabuleiro[a][0] = TP; // TORRE 1
    tabuleiro[b][0] = CP; // CAVALO 1
    tabuleiro[c][0] = BP; // BISPO 1
    tabuleiro[d][0] = DP; // DAMA
    tabuleiro[e][0] = RP; // REI
    tabuleiro[f][0] = BP; // BISPO 2
    tabuleiro[g][0] = CP; // CAVALO 2
    tabuleiro[h][0] = TP; // TORRE 2
    
    // PECAS BRANCAS 
    for(i = 0; i <= 8; i++){
        tabuleiro[i][6] = PB; // PEOES
    }
    tabuleiro[a][7] = TB; // TORRE 1
    tabuleiro[b][7] = CB; // CAVALO 1
    tabuleiro[c][7] = BB; // BISPO 1
    tabuleiro[d][7] = DB; // DAMA
    tabuleiro[e][7] = RB; // REI
    tabuleiro[f][7] = BB; // BISPO 2
    tabuleiro[g][7] = CB; // CAVALO 2
    tabuleiro[h][7] = TB; // TORRE 2
}

void tabuleiroPrint(){
    for(i = 0; i < 8; i++){
        for(i2 = 0; i2 < 8; i2++){
            printf("%s|", tabuleiro[i2][i]);
        }
        printf("\n");
    }
}

void main(){
    tabuleiroInit();
    tabuleiroPrint();
}
