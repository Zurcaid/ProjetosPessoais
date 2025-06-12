#include "RTSfunctions.h"
#include "RTSconstants.h"
#include <iostream>
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
		month += 1;
		if(month >= 12){
		    month = month - 12;
		    year += 1;
		}
		cout << "Actual date: " << month << "/" << year;
		cin >> input;
	}
	return 0;
}
