#pragma once
#include<iostream>
#include <fstream>
#include "Player.h"
#include "Board.h"

class Game
{
	Player* first;
	Player* second;
	Board game_board;
	void ClearScreen();
	void StartTheGame(bool opponent);
	void ToFile();
	bool PlayerPlay(Player* player,bool& flag);
public:
	Game(){}
	Game(const Game& Other) = delete;
	Game& operator=(const Game& Other) = delete;
	void Multiplayer();
	void Singleplayer();
	void BigGame();
};