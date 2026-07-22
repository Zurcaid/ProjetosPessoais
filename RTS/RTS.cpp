#include "RTSconstants.h"
#include "RTSfunctions.h"
#include "RTSfunctions.cpp"
#include <iostream>
#include <unistd.h>
#include <ctime>

using namespace std;

int month = 0, init_game;
int year = 1;
string input;

int main()
{
	srand(time(0));
	setupTroops();
	setupBuildings();
	generateOtherCivilizations();

	int dead_count = 0;
	for (int j = 0; j < 120; j++)
	{
		dead_count = 0;
		for (int i = 0; i < botManagement.size(); i++)
		{
			sleep(0);
			if (botManagement.at(i).BotCivilization->alive)
			{
				// cout << "Bot [" << botManagement.at(i).BotCivilization->identifier << "] turn: \n";
				botManagement.at(i).botTurn();
			}
			else
			{
				dead_count += 1;
			}
		}
		worldEvents();
		// month += 1;
		// cout << "Date: Month " << month << " | Year " << year << " ... ";
		// if (month >= 13)
		// {
		// 	month = month - 12;
		// 	year += 1;
		// }
		cout << "Year: " << j / 12 << endl;
	}
	for (int i = 0; i < botManagement.size(); i++)
	{
		if (botManagement.at(i).BotCivilization->alive)
		{
			cout << "Bot [" << botManagement.at(i).BotCivilization->identifier << "] turn: \n";
			botManagement.at(i).botTurn();
			botManagement.at(i).BotCivilization->report();
		}
		else
		{
		}
	}

	cout << "Dead civilizations: " << dead_count << endl;

	init_game = beginGame();
	if (init_game == 1)
	{
		newGame();
	}
	else
	{
		loadGame();
	}

	for (int i = 0; i < PlayerKingdom.nations_unknown.size(); i++)
	{
		cout << "x: " << PlayerKingdom.nations_unknown_x.at(i) << endl;
	}

	while (1)
	{
		month += 1;
		if (month >= 13)
		{
			month = month - 12;
			year += 1;
		}
		cout << "Date: Month " << month << " | Year " << year << " ... ";

		playerTurn();

		cout << "The world is moving..." << endl;

		for (int i = 0; i < botManagement.size(); i++)
		{
			// cout << "Bot [" << botManagement.at(i).BotCivilization->identifier << "] turn: \n";
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