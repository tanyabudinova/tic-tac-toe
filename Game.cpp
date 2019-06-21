#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Opponent.h"
#include "BigBoard.h"

using namespace std;

bool Game::PlayerPlay(Player* player, bool& flag)
{
	player->Print();
	player->MakeMove(game_board);
	ClearScreen();
	game_board.PrintOwn();
	if (game_board.Win(player->getSymbol(), player->getLastMove()))
	{
		cout << player->getSymbol() << " wins!" << endl;
		flag = false;
	}
	return flag;
}

void Game::Multiplayer()
{
	ClearScreen();
	StartTheGame(false);
}

void Game::Singleplayer()
{
	ClearScreen();
	StartTheGame(true);
}

void Game::BigGame()
{
	ClearScreen();
	BigBoard board;
	srand(time(NULL));
	char tmp_symbol;
	bool flag = true;
	while (flag)
	{
		cout << "Enter x or o: ";
		cin >> tmp_symbol;
		if (tmp_symbol == 'x' || tmp_symbol == 'o')
		{
			char op_symbol = (tmp_symbol == 'x') ? 'o' : 'x';
			second = new Player(op_symbol);
			flag = false;
		}
		else
		{
			cout << "Only x or o are allowed!" << endl;
		}
	}
	first = new Player(tmp_symbol);
	flag = true;
	board.WhichBoard();
	while (flag)
	{
		ClearScreen();
		board.Print();
		board.PrintCurrBoard();
		first->Print();
		first->MakeMove(board.getCurrBoard());
		if (board.Win(*first))
		{
			ClearScreen();
			board.Print();
			cout << first->getSymbol() << " wins!" << endl;
			flag = false;
			break;
		}
		if (board.Tie())
		{
			ClearScreen();
			board.Print();
			cout << "It's a tie!" << endl;
			flag = false;
			break;
		}
		ClearScreen();
		board.Print();
		board.CurrBoard(*first);
		board.PrintCurrBoard();
		second->Print();
		second->MakeMove(board.getCurrBoard());
		if(board.Win(*second))
		{
			ClearScreen();
			board.Print();
			cout << second->getSymbol() << " wins!" << endl;
			flag = false;
			break;
		}
		if (board.Tie())
		{
			ClearScreen();
			board.Print();
			cout << "It's a tie!" << endl;
			flag = false;
			break;
		}
		ClearScreen();
		board.Print();
		board.CurrBoard(*second);
	}
}

void Game::StartTheGame(bool opponent)
{
	srand(time(NULL));
	char tmp_symbol;
	bool flag = true;
	while (flag)
	{
		cout << "Enter x or o: ";
		cin >> tmp_symbol;
		if (tmp_symbol == 'x' || tmp_symbol == 'o')
		{
			char op_symbol = (tmp_symbol == 'x') ? 'o' : 'x';
			if (opponent)
			{
				second = new Opponent(op_symbol);
			}
			else
			{
				second = new Player(op_symbol);
			}
			flag = false;
		}
		else
		{
			cout << "Only x or o are allowed!" << endl;
		}
	}
	first = new Player(tmp_symbol);
	flag = true;
	while (flag)
	{
		ClearScreen();
		game_board.PrintOwn();
		if (!(PlayerPlay(first, flag)))
		{
			break;
		}
		if (game_board.Tie())
		{
			cout << "It's a tie!" << endl;
			flag = false;
			break;
		}
		flag = PlayerPlay(second, flag);
	}
	ToFile();
}

void Game::ToFile()
{
	ofstream file("game.txt", ios::app);
	if (!file)
	{
		cerr << "Fail to open file!";
	}
	file << *first;
	file << *second;
	if (game_board.Tie())
	{
		file << "It was a tie!" << endl;
	}
	else
	{
		file << game_board.getWhoWon() << " won!" << endl;
	}
	file.close();
}

void Game::ClearScreen()
{
#ifdef WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}