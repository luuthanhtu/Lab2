#pragma once


#define ROWS 20
#define COLUMNS 20

#include <vector>
#include  "BoardObjectH.h"
#include  "ListBoardObjectsH.h"
#include  "PlayerH.h"
#include  "WallH.h"
#include  "CookieH.h"

typedef  ListBoardObjects* p_ListBoardObjects;

class Board
{

private:

	int the_rows, the_cols;

	bool set_correct_map_size;
	bool gameOn;
	int lives;
	p_ListBoardObjects   Map_Array[ROWS][COLUMNS];
	int player_id_x;
	int player_id_y;
	Player *startPlayer;
	int currentScore;


public:

	Board(int rows, int cols)
	{
		if ((ROWS >= rows) && (COLUMNS >= cols))
		{
			set_correct_map_size - true; the_rows = rows; the_cols = cols;
			lives = 3000000; gameOn = true;
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
				{
					BoardObject* aBackground = new BoardObject(i, j);
					p_ListBoardObjects aList = new ListBoardObjects(aBackground);
					Map_Array[i][j] = aList;
				}
			player_id_x = the_rows / 2;
			player_id_y = the_cols / 2;
			startPlayer = new Player(player_id_x, player_id_y);
			currentScore = 0;

			(Map_Array[player_id_x][player_id_y])->add_One_Object(startPlayer);

			for (int i = 1; i < the_rows - 1; i++)
			{
				Wall * aWall = new Wall(i, 1);
				(Map_Array[i][1])->add_One_Object(aWall);
				aWall = new Wall(i, the_cols - 2);
				(Map_Array[i][the_cols - 2])->add_One_Object(aWall);
			}

			for (int i = 1; i < the_rows - 1; i = i + 2)
			{
				Cookie * aCookie = new Cookie(i, 0);
				(Map_Array[i][0])->add_One_Object(aCookie);
				aCookie = new Cookie(i, the_cols - 1);
				(Map_Array[i][the_cols - 1])->add_One_Object(aCookie);
			}
		}
		else
			set_correct_map_size = false;

	};

	bool setBoardOK() { return set_correct_map_size; };

	void paint();

	void move(const char command);

	bool IamAlive() {
		if (0 < lives) { lives--; return true; }
		else return false;
	}
};
