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
		month += 1;
		cout << "Date: Month " << month << " | Year " << year << " ... ";
		if (month >= 13)
		{
			month = month - 12;
			year += 1;
		}

		playerTurn();

		for (int i = 0; i < botManagement.size(); i++)
		{
			cout << "Bot [" << botManagement.at(i).BotCivilization->identifier << "] turn: \n";
			botManagement.at(i).botTurn();
		}
	}
	return 0;
}