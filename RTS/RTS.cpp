#include "RTSconstants.h"
#include "RTSfunctions.h"
#include "RTSfunctions.cpp"
#include <iostream>
#include <ctime>

using namespace std;

int month, init_game;
int year = 1;
string input;

int main()
{
	srand(time(0));
	setupTroops();
	setupBuildings();
	generateOtherCivilizations();
	for (int j = 0; j < 6000; j++)
	{
		int dead_count = 0;
		for (int i = 0; i < botManagement.size(); i++)
		{
			if (botManagement.at(i).BotCivilization->alive)
			{
				cout << "Bot [" << botManagement.at(i).BotCivilization->identifier << "] turn: \n";
				botManagement.at(i).botTurn();
			}
			else
			{
				dead_count += 1;
			}
		}
		cout << "Dead civilizations: " << dead_count << endl;
		worldEvents();
	}

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

		worldEvents();

		// for (int j = 0; j < 120; j++)
		// {
		// 	month += 1;
		// 	if (month >= 13)
		// 	{
		// 		month = month - 12;
		// 		year += 1;
		// 	}
		// 	for (int i = 0; i < botManagement.size(); i++)
		// 	{
		// 		cout << "Bot [" << botManagement.at(i).BotCivilization->identifier << "] turn: \n";
		// 		botManagement.at(i).botTurn();
		// 	}
		// 	worldEvents();
		// }
	}
	return 0;
}