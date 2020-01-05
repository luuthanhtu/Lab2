#include <iostream>

#include "BoardObjectH.h"
#include "PlayerH.h"

void Player::Update_status()
{
	switch (currentstatus)
	{
	case ALIVE: if (Player_color1 == get_Color())
		set_color(Player_color2);
				else
		set_color(Player_color1);
		break;
	case  DEAD:
		set_color(YELLOW);
	}
	//std::cerr << " Player Object Update_statused\n";
}
