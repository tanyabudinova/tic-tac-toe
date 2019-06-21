#include "stdafx.h"
#include "BigBoard.h"
#include "Utility.h"
#include "Player.h"

using namespace std;

void BigBoard::Print()
{
	cout << " ";
	for (int i = 0; i < board_size * board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			cout << " ";
		}
		if (i % 3 == 0 && i != 0)
		{
			for (int k = 0; k < board_size + 1; k++)
			{
				cout << " ";
			}
		}
		cout << i % board_size;
	}
	cout << endl;
	for (int i = 0; i < board_size * board_size; i++)
	{
		cout << " " << endl;
		if (i % 3 == 0 && i != 0)
		{
			for (int k = 0; k < board_size - 1; k++)
			{
				cout << " " << endl;
			}
		}
		cout << i % board_size << endl;
	}
	for (int i = 0; i < board_size; i++)
	{
		if (i < board_size - 1)
		{
			SetCursorPosition(2, i * 8 + board_size * 2 + 2);
			for (int j = 0; j < board_size * 15; j++)
			{
				cout << (char)196;
			}
		}
		for (int j = 0; j < board_size; j++)
		{
			big_board[i][j].Print(j * 16, i * 8);
			if (j < board_size - 1)
			{
				for (int k = 0; k < board_size * 2 + 1; k++)
				{
					SetCursorPosition((j * 16) + 16, i * 8 + k + 1);
					cout << (char)179;
				}
				if (i < board_size - 1)
				{
					SetCursorPosition((j * 16) + 16, i * 8 + board_size * 2 + 2);
					cout << (char)197;
				}
			}
		}
	}
	SetCursorPosition(0, board_size * 8);
}

bool BigBoard::Win(const Player& pl)
{
	if (big_board[curr_boardI][curr_boardJ].Tie())
	{
		FillWithSymbol('t');
	}
	else if (big_board[curr_boardI][curr_boardJ].Win(pl.getSymbol(), pl.getLastMove()))
	{
		FillWithSymbol(pl.getSymbol());
		bool flag_row = true, flag_col = true, flag_diag1 = true, flag_diag2 = true;
		int i = curr_boardI, j = curr_boardJ;
		for (int k = 0; k < board_size; k++)
		{
			if (big_board[i][k].getWhoWon() != pl.getSymbol())
			{
				flag_row = false;
			}
			if (big_board[k][j].getWhoWon() != pl.getSymbol())
			{
				flag_col = false;
			}
			if (big_board[k][k].getWhoWon() != pl.getSymbol())
			{
				flag_diag1 = false;
			}
			if (big_board[k][board_size - (k + 1)].getWhoWon() != pl.getSymbol())
			{
				flag_diag2 = false;
			}
		}
		return flag_row || flag_col || flag_diag1 || flag_diag2;
	}
	return false;
}

void BigBoard::WhichBoard()
{
	bool flag = true;
	while (flag)
	{
		cout << "On which board you will play: ";
		int n;
		cin >> n;
		int i = (n - 1) / board_size, j = (n - 1) - i * board_size;
		if (EmptyBoard(i, j))
		{
			curr_boardI = i;
			curr_boardJ = j;
			flag = false;
		}
		else
		{
			cout << "Not avalible!" << endl;;
		}
	}
}

bool BigBoard::Tie()
{
	bool flag = true;
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			if (big_board[i][j].getWhoWon() == ' ')
			{
				flag = false;
			}
		}
	}
	return flag;
}

void BigBoard::FillWithSymbol(char symbol)
{
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			big_board[curr_boardI][curr_boardJ].setCharacter(i, j, symbol);
		}
	}
}

void BigBoard::PrintCurrBoard()
{
	int n = curr_boardJ + (curr_boardI * board_size) + 1;
	cout << "You play on board: " << n << endl;
}

Board& BigBoard::getCurrBoard()
{
	return big_board[curr_boardI][curr_boardJ];
}

void BigBoard::CurrBoard(const Player& pl)
{
	char* m = pl.getLastMove();
	int i = m[0] - '0', j = m[1] - '0';
	if (EmptyBoard(i, j))
	{
		curr_boardI = i;
		curr_boardJ = j;
	}
	else
	{
		WhichBoard();
	}
}

bool BigBoard::EmptyBoard(int i, int j)
{
	return big_board[i][j].getWhoWon() == ' ';
}
