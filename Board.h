#pragma once
#include <iostream>

const unsigned board_size = 3;

class Board
{
	char board[board_size][board_size];
	char who_won;
public:
	Board();
	char getWhoWon()const;
	char getCharacter(int i, int j)const;
	void setCharacter(int i, int j,char symbol);
	bool Win(char symbol,const char* last_move);
	bool Tie();
	void PrintOwn()const;
	void Print(int x, int y);
	bool CouldWin(char symbol, int i, int j);
	bool IsEmpty(int i, int j)const;
};