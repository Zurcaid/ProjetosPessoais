#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//Desenvolvimento de um jogo com objetivo de incrementar o costume com a linguagem C.
//O jogo se trata de um jogo de estrategia que deu vontade de desenvolver, algum tipo de simulador de guerra ou semelhante.
//Detalhes ainda irão ser definidos

char mapa[15][15]; //mapa consiste numa matriz
int config[15][15][3]; // Os dois primeiros valores representam a mesma posicao do mapa, enquanto o ultimo é para guardar informações sobre o espaco
// O primeiro valor representa o  time da tropa no espaco, 0 representa que nao ha nada no espaco.
// O segundo valor representa o tipo de tropa, valores acima de 1000 representam constucoes.
// O terceiro valor representa a direção com ae dezena de milhar, e a durabilidade pela unidade de milhar e a centena, e o dano pela dezena e unidade.
// O quarto valor representa a area de atuacao da tropa, sendo as casas de milhao a area de efeito ataque, enquanto a area de alcance sendo
// as cassas de milhar no eixo Y as casas de centena dezena e unidade no eixo X.
int saveinfo[2]; // Informacao que o jogo guarda quando voce sai. Nao vejo necessidade de criptografar, brincar com os arquivos e interessante.
// O primeiro numero representa o numero do save.
// O segundo numero representa o  dinheiro.
// O terceiro numero representa o nivel.
// A base e as tropas sao informacoes guardadaas em arquivos diferentes
//int tropas[];
int cordX, cordY;


int begin(){ // Input inicial do jogador
	int nextstep = 0;
	char initop;
	while(nextstep == 0){
		printf("Digite N para iniciar novo jogo ou C para carregar um jogo antigo: ");
		scanf("%c", &initop);
		if((initop == 'N') | (initop == 'n')){
		return 0;
		nextstep = 1;
		}else if((initop == 'C') | (initop == 'c')){
		return 1;
		nextstep = 1;
		}else printf("Operacao invalida. \n");
	}
}

void setTroop(int yPos, int xPos, int team, int type, int third, int fourth){
	config[yPos][xPos][0] = team;
	config[yPos][xPos][1] = type;
	config[yPos][xPos][2] = third;
	config[yPos][xPos][0] = fourth;
}

void userInput(){
	char acao;
	printf("Que acao deseja tomar? (P para posicionar tropas; M para mudar o local visualizado.)");
	scanf("%c", &acao);
}

void updateMap(int startX, int startY){
	//mapa visivel para o jogador, tamanho 16x16
	int countX = 0;
	int countY = 0;
	cordX = startX;
	cordY = startY;
	for(int i = startX; i < (startX+16); i++){
		for(int i2 = startY; i2 < (startY+16); i2++){
			switch(config[i2][i][1]){
				case 0:
					mapa[countY][countX] = '.';
					break;
				case 1:
					mapa[countY][countX] = 's';
					break;
				default:
					mapa[countY][countX] = '.';
			}
			countY++;
		}
		countX++;
		countY = 0;
	}
}

void dmgEnemy(int posX, int  posY, int dmg, int bulletSize){
		int enemyDir, enemyDmg, enemyHP, bulletSideSize;
			if(bulletSize == 1){
			enemyDir = config[posY][posX][2]/10000;
			enemyDmg = (config[posY][posX][2]-(enemyDir*10000))/100;
			enemyHP = (config[posY][posX][2]-(enemyDir*1000))-(enemyDmg*100);
			enemyHP = enemyHP - dmg;
			config[posY][posX][2] = enemyDir + enemyDmg + enemyHP;
		}else{
			bulletSideSize = (bulletSize - 1)/2;
			for(int i = (posY - bulletSideSize); i <= (posY + bulletSideSize); i++){
				for(int i2 = (posX - bulletSize); i2 <= (posX + bulletSize); i2++){
					if(config[i][i2][0] != 0){
						enemyDir = config[i][i2][2]/10000;
						enemyDmg = (config[i][i2][2]-(enemyDir*10000))/100;
						enemyHP = (config[i][i2][2]-(enemyDir*1000))-(enemyDmg*100);
						enemyHP = enemyHP - dmg;
						config[i][i2][2] = enemyDir + enemyDmg + enemyHP;
					}
				}
			}
		}
}

void updateWorldAttacks(){
	int dir, rangeX, sideRangeX, rangeY, dmg, bulletSize, turnUsed;
	for(int i = cordX; i < (cordX+16); i++){
		for(int i2 = cordY; i2 < (cordY+16); i2++){
			if(config[i2][i][0] != 0){ // Se na localizacao houver uma tropa ou construcao
				turnUsed = 0;
				dir = config[i2][i][2]/10000; // Direcao da tropa
				dmg = (config[i2][i][2]-(dir*10000))/100; // Dano da tropa
				bulletSize = config[i2][i][3]/1000000; // Area de efieto da tropa
				rangeY = (config[i2][i][3]-(bulletSize*1000000))/1000; // Alcance da tropa no eixo Y
				rangeX = config[i2][i][3]-(rangeY*1000); // Alcance da tropa no eixo X
				if(rangeX > 1) sideRangeX = (rangeX-1)/2;
				if(dmg != 0){
					switch(dir){
						case 1:
							// Caso tropa esteja virada pra cima
							for(int i3 = i2; i3 <= (i2 + rangeY); i3++){
								if((config[i3][i][1] != 0) && (config[i3][i][0] != config[i2][i][0])){
									dmgEnemy(i3, i, dmg, bulletSize);
									turnUsed = 1;
									break;
								}
							}
							if(turnUsed == 0){
								for(int i3 = i2; i3 <= (i2 + rangeY); i3++){
									for(int i4 = (i - sideRangeX); i4 <= (i + sideRangeX); i4++){
										if((config[i3][i4][1] != 0) && (config[i3][i4][0] != config[i2][i][0])){
											dmgEnemy(i3, i4, dmg, bulletSize);
											turnUsed = 1;
											break;
										}
									}
									if(turnUsed == 1) break;
								}
							}
							break;
						case 2:
							// Caso tropa esteja virada pra direita
							for(int i3 = i; i3 <= (i + rangeY); i3++){
								if((config[i2][i3][1] != 0) && (config[i2][i3][0] != config[i2][i][0])){
									dmgEnemy(i2, i3, dmg, bulletSize);
									turnUsed = 1;
									break;
								}
							}
							if(turnUsed == 0){
								for(int i3 = i; i3 <= (i + rangeY); i3++){
									for(int i4 = (i2 - sideRangeX); i4 <= (i2 + sideRangeX); i4++){
										if((config[i4][i3][1] != 0) && (config[i4][i3][0] != config[i2][i][0])){
											dmgEnemy(i4, i3, dmg, bulletSize);
											turnUsed = 1;
											break;
										}
									}
									if(turnUsed == 1) break;
								}
							}
							break;
						case 3:
							// Caso tropa esteja virada pra baixo
							for(int i3 = i2; i3 <= (i2 - rangeY); i3 = i3 - 1){
								if((config[i3][i][1] != 0) && (config[i3][i][0] != config[i2][i][0])){
									dmgEnemy(i3, i, dmg, bulletSize);
									turnUsed = 1;
									break;
								}
							}
							if(turnUsed == 0){
								for(int i3 = i2; i3 <= (i2 - rangeY); i3 = i3 - 1){
									for(int i4 = (i - sideRangeX); i4 <= (i + sideRangeX); i4++){
										if((config[i3][i4][1] != 0) && (config[i3][i4][0] != config[i2][i][0])){
											dmgEnemy(i3, i4, dmg, bulletSize);
											turnUsed = 1;
											break;
										}
									}
									if(turnUsed == 1) break;
								}
							}
							break;
						case 4:
							// Caso tropa esteja virada pra esquerda
							for(int i3 = i; i3 <= (i - rangeY); i3 = i3 - 1){
								if((config[i2][i3][1] != 0) && (config[i2][i3][0] != config[i2][i][0])){
									dmgEnemy(i2, i3, dmg, bulletSize);
									turnUsed = 1;
									break;
								}
							}
							if(turnUsed == 0){
								for(int i3 = i; i3 <= (i - rangeY); i3 = i3 - 1){
									for(int i4 = (i2 - sideRangeX); i4 <= (i2 + sideRangeX); i4++){
										if((config[i4][i3][1] != 0) && (config[i4][i3][0] != config[i2][i][0])){
											dmgEnemy(i4, i3, dmg, bulletSize);
											turnUsed = 1;
											break;
										}
									}
									if(turnUsed == 1) break;
								}
							}
							break;
					}
				}
			}
		}
	}
}

void updateWorldTroops(){
	int troopDir, troopDmg, troopHP;
	for(int i = cordX; i < (cordX+16); i++){
		for(int i2 = cordY; i2 < (cordY+16); i2++){
			troopDir = config[i2][i][2]/10000;
			troopDmg = (config[i2][i][2]-(troopDir*10000))/100;
			troopHP = (config[i2][i][2]-(troopDir*1000))-(troopDmg*100);
			if(troopHP <= 0){
				setTroop(i2, i, 0, 0, 0, 0);
			}
		}
	}
}

void printMap(){
	for(int i = 0; i < 16; i++){
		for(int i2 = 0; i2 < 16; i2++){
			printf("%c ", mapa[i][i2]);
		}
		printf("\n");
	}
}

int savesystem(int op){
	if(!op){
		// Inicia jogo do zero.
		// Adiciona tropas iniciais
		// Constroi base inicial
	}else{
		// Carrega o arquivo salvo.
		// Pede numero do save e exibe informacoes
		// Carrega as bases salvas e tropas.
	}
}

void main(){
	srand(time(0));
	int seed = rand(); //seed para geracao de inimigos unicos
	//Codigo principal que ficara rodando
	for(int i = 0; i < 16; i++){
		for(int i2 = 0; i2 < 16; i2++){
			config[i][i2][0] = 0;
			config[i][i2][1] = 0;
			config[i][i2][2] = 0;
			config[i][i2][3] = 0;
		}
	}
	//saveinfo[0] = 1;//savesystem(begin());
	setTroop(2, 8, 2, 1, 30101, 1004003);
	setTroop(4, 8, 1, 1, 10101, 1004003);
	updateMap(0,0);
	printf("Ola comandante, voce foi enviado para um novo planeta, nomeado X-%d. \n", seed);
	printf("O seu objetivo e conquistar o planeta completamente, cada vez que desconectar deste terminal o sistema entendera a operacao como \n");
	printf("encerrada e movera suas bases para outro planeta junto com suas tropas. \n");
	printf("Boa sorte na missao. \n");

	printMap();
}

