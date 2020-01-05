#pragma once
#ifndef H_PLAYER
#define H_PLAYER
#include <iostream>

const enum PlayerState { ALIVE, DEAD };

#include "BoardObjectH.h"

class Player : public BoardObject
{

private:
	PlayerState currentstatus;
	ObjectColours Player_color1;
	ObjectColours  Player_color2;

public:
	Player(int start_x, int start_y) :BoardObject(start_x, start_y)
	{
		currentstatus = ALIVE;
		Player_color1 = RED;
		Player_color2 = BLUE;
		ACurrentClass = A_PLAYER;
	};

	virtual void Update_status();
};
#endif
