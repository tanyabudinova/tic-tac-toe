#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include "Opponent.h"

Opponent::Opponent(char symbol):Player(symbol)
{}

void Opponent::MakeMove(Board& board)
{
	Sleep(500);
	bool made_move = false;
	int x, y;
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			if (board.IsEmpty(i,j) && CanWin(i,j,board))
			{
				x = i;
				y = j;
				made_move = true;
				break;
			}
			if (board.IsEmpty(i, j) && CanBlock(i, j, board))
			{
				x = i;
				y = j;
				made_move = true;
			}
		}
	}
	if (made_move)
	{
		AddMove(x, y);
		board.setCharacter(x, y, getSymbol());
		made_move = true;
	}
	Sleep(500);
	while (!made_move)
	{
		int i, j;
		i = rand() % board_size;
		j = rand() % board_size;
		if (board.IsEmpty(i, j))
		{
			AddMove(i, j);
			board.setCharacter(i, j, getSymbol());
			made_move = true;
		}
	}
}

bool Opponent::CanWin(int i, int j, Board& board)
{
	return board.CouldWin(getSymbol(), i, j);
}

bool Opponent::CanBlock(int i, int j, Board& board)
{
	char player_symbol = (getSymbol() == 'x') ? 'o' : 'x';
	return board.CouldWin(player_symbol, i, j);
}

