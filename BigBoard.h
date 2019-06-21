#pragma once
#include<iostream>
#include "Player.h"
#include"Board.h"

using namespace std;

class BigBoard
{
	Board big_board[board_size][board_size];
	int curr_boardI;
	int curr_boardJ;
public:
	void Print();
	bool Win(const Player& pl);
	void WhichBoard();
	bool Tie();
	void FillWithSymbol(char symbol);
	void PrintCurrBoard();
	Board& getCurrBoard();
	void CurrBoard(const Player& pl);
	bool EmptyBoard(int i, int j);
};