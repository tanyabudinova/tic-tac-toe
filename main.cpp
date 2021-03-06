// tic-tac-toe-4504.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Game.h"
using namespace std;

int main()
{
	Game game;
	char y_n = 'Y';
	while (y_n == 'Y' || y_n == 'y')
	{
		cout << "Hello!" << endl << "You're playing tic-tac-toe!" << endl
			<< "Menu: " << endl << "[1] SinglePlayer" << endl << "[2] Multiplayer" << endl
			<< "[3] Big Game" << endl;
		int type;
		cin >> type;
		switch (type)
		{
		case 1:
			game.Singleplayer();
			break;
		case 2:
			game.Multiplayer();
			break;
		case 3:
			game.BigGame();
			break;
		default:
			cout << "Not an option!" << endl;
			break;
		}
		cout << "One more?(Y/N)" << endl;
		cin >> y_n;
	}
	cout << "Bye!" << endl;
	return 0;
}

