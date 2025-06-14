#include "RTSconstants.h"
#include "RTSfunctions.h"
#include "RTSfunctions.cpp"
#include <iostream>
using namespace std;

int month, init_game;
int year = 1;
string input;

int main()
{
	init_game = beginGame();
	if (init_game == 1)
	{
		newGame();
	}
	else
	{
		loadGame();
	}

	while (1)
	{
		playerTurn();
		month += 1;
		if (month >= 13)
		{
			month = month - 12;
			year += 1;
		}
		cout << "Date: Month " << month << " | Year " << year << " ... ";
		cin >> input;
	}
	return 0;
}