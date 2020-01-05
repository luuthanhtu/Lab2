
#include  <string>
#include <iostream>
#include  "BoardH.h"
#include  "ListBoardObjectsH.h"

using namespace std;


void Update_status_all(const p_ListBoardObjects Board_list)
{
	p_BoardObject toIterate;

	toIterate = Board_list->Get_First_Object();

	while (NULL != toIterate)
	{
		toIterate->Update_status();

		//cerr << "Update_statusing "<< toIterate->get_x() <<"," <<toIterate->get_y() << std::endl;
		toIterate = Board_list->Get_Next_Object();

	}

}

char game_all(const p_ListBoardObjects aList)
{

	p_BoardObject toIterate;

	toIterate = aList->Get_First_Object();

	ObjectColours board_color = BACKGROUND;

	while (NULL != toIterate)
	{
		if (BACKGROUND != toIterate->get_Color())
			board_color = toIterate->get_Color();

		toIterate = aList->Get_Next_Object();
	}

	switch (board_color)
	{
	case YELLOW: return 'Y';
	case BLACK: return '#';
	case BLUE: return 'B';
	case RED: return 'R';
	case INVISIBLE: return 'I';
	case BACKGROUND: return '-';
	}
}

void Board::move(const char command)
{
	if ('p' != command)
	{
		switch (command)
		{
		case 'e': if (player_id_x <= 0) break;
				  else
		{
			if (!Map_Array[player_id_x - 1][player_id_y]->isThereAWall())
			{
				Map_Array[player_id_x][player_id_y]->removeOnePlayer();
				player_id_x--;
				startPlayer = new Player(player_id_x, player_id_y);
				Map_Array[player_id_x][player_id_y]->add_One_Object(startPlayer);

			}
		}
				  break;
		case 'x': if (player_id_x >= the_rows - 1) break;
				  else
		{
			if (!Map_Array[player_id_x + 1][player_id_y]->isThereAWall())
			{
				Map_Array[player_id_x][player_id_y]->removeOnePlayer();
				player_id_x++;
				startPlayer = new Player(player_id_x, player_id_y);
				Map_Array[player_id_x][player_id_y]->add_One_Object(startPlayer);
			}
		}
				  break;
		case 's': if (player_id_y <= 0) break;
				  else
		{
			if (!Map_Array[player_id_x][player_id_y - 1]->isThereAWall())
			{
				Map_Array[player_id_x][player_id_y]->removeOnePlayer();
				player_id_y--;
				startPlayer = new Player(player_id_x, player_id_y);
				Map_Array[player_id_x][player_id_y]->add_One_Object(startPlayer);
			}
		}
				  break;
		case 'd': if (player_id_y >= the_cols - 1) break;
				  else
		{
			if (!Map_Array[player_id_x][player_id_y + 1]->isThereAWall())
			{
				Map_Array[player_id_x][player_id_y]->removeOnePlayer();
				player_id_y++;
				startPlayer = new Player(player_id_x, player_id_y);
				Map_Array[player_id_x][player_id_y]->add_One_Object(startPlayer);
			}
		}
				  break;
		}
		int cookieValue = Map_Array[player_id_x][player_id_y]->isCookieValue();
		if (cookieValue > 0)
		{
			std::cerr << "Ate a cookie\n";
			currentScore += cookieValue;
		}

	}
}

void Board::paint()
{
	char draw;
	std::string row;

	for (int i = 0; i < the_rows; i++)
	{
		row = "";
		for (int j = 0; j < the_cols; j++)
		{
			Update_status_all(Map_Array[i][j]);
			draw = game_all(Map_Array[i][j]);
			row.push_back(draw);
		}
		cout << row << endl;
	}
	cout << "CURRENT SCORE : " << currentScore << endl;
}

