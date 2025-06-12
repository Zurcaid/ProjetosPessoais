#include "RTSconstants.h"
#include "RTSfunctions.cpp"
using namespace std;

int main()
{
	init_game = beginGame();
	if(init_game == 1){
		newGame();
	}else{
		loadGame();
	}
	initCivilizations();
	
	while(1){
		playerTurn();
		age += 1;
		cout << "Date: " << age;
		cin >> input;
	}
	return 0;
}
