#pragma once
#include <iostream>
#include "Board.h"

using namespace std;

class Player
{
	char symbol;
	char *moves;
	int size;
	unsigned cap;
	void resize();
public:
	Player(char symbol);
	Player(const Player& Other) = delete;
	Player& operator=(const Player& Other) = delete;
	virtual ~Player();
	char* getLastMove()const;
	char getSymbol()const;
	friend ostream& operator<<(ostream& os, const Player& p);
	virtual void MakeMove(Board& board);
	void AddMove(char x, char y);
	void Print();
	bool ValidMove(int x, int y, const Board& board);
};