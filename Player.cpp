#include "stdafx.h"
#include <iostream>
#include "Player.h"

using namespace std;

void Player::resize()
{
	cap += 2;
	char* tmp = new char[cap];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = moves[i];
	}
	delete[] moves;
	moves = tmp;
}

Player::Player(char symbol):symbol(symbol),size(0),cap(6)
{
	moves = new char[cap];
}

Player::~Player()
{
	delete[] moves;
}

void Player::MakeMove(Board & board)
{
	bool flag = true;
	while (flag)
	{
		cout << "Position: ";
		char x, y;
		cin >> x >> y;
		x = x - '0';
		y = y - '0';
		if (board.IsEmpty(x, y))
		{
			AddMove(x, y);
			board.setCharacter(x, y, getSymbol());
			flag = false;
		}
		else cout << "Can't there!" << endl;
	}
}

void Player::AddMove(char x, char y)
{
	if (size >= cap-1)
	{
		resize();
	}
	moves[size] = x + '0';
	moves[size + 1] = y + '0';
	size += 2;
}

char* Player::getLastMove() const
{
	return &moves[size - 2];
}

char Player::getSymbol() const
{
	return symbol;
}

void Player::Print()
{
	cout << *this;
}

bool Player::ValidMove(int x, int y, const Board& board)
{
	return board.getCharacter(x, y) == ' ';
}

ostream& operator<<(ostream & os, const Player& p)
{
	os << "symbol: " << p.symbol << endl;
	if (p.size > 0)
	{
		os << "moves:" << endl;
	}
	for (int i = 0; i < p.size - 1; i += 2)
	{
		os << '(' << p.moves[i] << p.moves[i + 1] << ')' << " ";
	}
	os << endl;
	return os;
}
