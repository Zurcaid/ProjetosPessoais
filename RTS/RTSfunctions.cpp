#include "RTSconstants.h"
#include "RTSfunctions.h"

int init_game;
int month;
int year;
string input;
void Civilization::changeAlignment(int x){
	alignment += x;
}
void Civilization::changeXp(int x){
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

void initCivilizations(){
    Civilization Kingdom1;
	Kingdom1.changeAlignment(50);
	Kingdom1.setKind(0);
	Kingdom1.setKing(0);
}

int beginGame(){
	return 1;
}

void newGame(){
	
}

void loadGame(){
	
}

void playerTurn(){
	
}
