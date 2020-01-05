#pragma once

enum WallState { SOLID };

#include "BoardObjectH.h"

class Wall : public BoardObject
{

private:
	ObjectColours wallcolor;

public:
	Wall(int start_x, int start_y) :BoardObject(start_x, start_y)
	{
		wallcolor = BLACK;
		ACurrentClass = A_WALL;
	};

	void Update_status();
};
