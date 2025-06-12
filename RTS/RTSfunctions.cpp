#include "RTSconstants.h"
#include "RTSfunctions.h"

using namespace std;

int init_game;
int month;
int year;
string input;
// Funcoes relativas ao gerenciamento da cidade
Civilization::Civilization(int a, int b, int c){
    Civilization::alignment = a;
    Civilization::kind = b;
    Civilization::king = c;
}
void Civilization::changeAlignment(int x){
	alignment += x;
}
void Civilization::changeXp(int x){
	xp += x;
}
void Civilization::changeMoral(int x){
    xp += x;
}
void Civilization::setTroops(string x, int n){
	int size = troops.size();
	int pos = size+1;
	for(int i = 0; i <= size; i++){
		if(troops.at(i) == x){
			pos = i;
			break;
		}
	}
    if(pos <= size){
		troopsNum.at(pos) = troopsNum.at(pos) + n;
	}else{
		troops.push_back(x);
		troopsNum.push_back(n);
	}
}
void Civilization::setKind(int x){
	kind = x;
}
void Civilization::setKing(int x){
	king = x;
}

// Funcoes relativas ao andamento do jogo

void initCivilizations(){
    Civilization Kingdom1(50, 0, 0);
}

int beginGame(){
	return 1;
}

void newGame(){
	
}

void loadGame(){
	
}

void playerTurn(){
	cout << Kingdom1.alignment;
}
