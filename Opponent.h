#pragma once
#include <iostream>
#include "Player.h"

class Opponent : public Player
{
	bool CanBlock(int i, int j, Board& board);
	bool CanWin(int i, int j, Board& board);
public:
	Opponent(char symbol);
	void MakeMove(Board& board);
};