#include "stdafx.h"
#include <iostream>
#include "Board.h"
#include "Utility.h"

using namespace std;

Board::Board()
{
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			board[i][j] = ' ';
		}
	}
	who_won = ' ';
}

char Board::getWhoWon() const
{
	return who_won;
}

bool Board::Win(char symbol,const char* last_move)
{
	bool flag_row = true, flag_col = true, flag_diag1 = true, flag_diag2 = true;
	int i = last_move[0] - '0', j = last_move[1] - '0';
	for (int k = 0; k < board_size; k++)
	{
		if (board[i][k] != symbol)
		{
			flag_row = false;
		}
		if (board[k][j] != symbol)
		{
			flag_col = false;
		}
		if (board[k][k] != symbol)
		{
			flag_diag1 = false;
		}
		if (board[k][board_size - (k + 1)] != symbol)
		{
			flag_diag2 = false;
		}
	}
	char flag = flag_row || flag_col || flag_diag1 || flag_diag2;
	if (flag)
	{
		who_won = symbol;
	}
	return flag;
}

bool Board::Tie()
{
	bool flag = true;
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			if (board[i][j] == ' ')
			{
				flag = false;
			}
		}
	}
	if (flag)
	{
		who_won = 't';
	}
	return flag;
}

void Board::PrintOwn() const
{
	unsigned count = 0;
	cout << " ";
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			cout << " ";
		}
		cout << i;
	}

	cout << endl;
	for (int i = 0; i < board_size; i++)
	{
		cout << "  ";
		for (int j = 0; j < board_size; j++)
		{
			cout << '+';
			for (int k = 0; k < board_size; k++)
			{
				cout << '-';
			}
		}
		cout << '+' << endl << count << " " << '|';
		for (int j = 0; j < board_size; j++)
		{
			cout << " " << board[count][j] << " " << '|';
		}
		cout << endl;
		++count;
	}
	cout << " " << " ";
	for (int j = 0; j < board_size; j++)
	{
		cout << '+';
		for (int k = 0; k < board_size; k++)
		{
			cout << '-';
		}
	}
	cout << '+' << endl;
}

void Board::Print(int x, int y)
{
	unsigned count = 0;
	SetCursorPosition(x , y);
	for (int i = 0; i < board_size; i++)
	{
		SetCursorPosition(x + 2, y + (i * 2) + 1);
		for (int j = 0; j < board_size; j++)
		{
			cout << '+';
			for (int k = 0; k < board_size; k++)
			{
				cout << '-';
			}
		}
		cout << '+' << endl;
		SetCursorPosition(x + 2, y + (i * 2) + 2);
		cout << '|';
		for (int j = 0; j < board_size; j++)
		{
			cout << " " << board[count][j] << " |";
		}
		cout << endl;
		++count;
	}
	for (int j = 0; j < board_size; j++)
	{
		SetCursorPosition(x + j * 4 + 2, y + 7);
		cout << '+';
		for (int k = 0; k < board_size; k++)
		{
			cout << '-';
		}
	}
	cout << '+' << endl;
}

bool Board::CouldWin(char symbol, int i, int j)
{
	setCharacter(i, j, symbol);
	char move[2] = { i + '0',j + '0' };
	bool win = Win(symbol, move);
	setCharacter(i, j, ' ');
	return win;
}

bool Board::IsEmpty(int i, int j) const
{
	return board[i][j] == ' ';
}

char Board::getCharacter(int i, int j)const
{
	return board[i][j];
}

void Board::setCharacter(int i, int j, char symbol)
{
	board[i][j] = symbol;
}