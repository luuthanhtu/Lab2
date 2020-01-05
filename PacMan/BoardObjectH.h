#pragma once
#ifndef H_BOARD_OBJECT
#define H_BOARD_OBJECT
const enum ObjectColours { BLACK, YELLOW, BLUE, RED, INVISIBLE, BACKGROUND };
const enum ObjectTypes { THE_BACKGROUND, A_COOKIE, A_PLAYER, A_WALL };


class BoardObject
{

private:
	// create direction x,y
	int x, y;
	ObjectColours currentColor;

	//cant not change to private because it is inherit and being used by player,wall,cookies class 
protected:
	ObjectTypes ACurrentClass;
	//int unique_ID;
	//static int count;
public:
	BoardObject( int start_x, int start_y)
	{
		x = start_x; y = start_y;
		currentColor = BACKGROUND;
		ACurrentClass = THE_BACKGROUND;

		//unique_ID=count++;
	};

	//int get_ID() { return unique_ID;};

	 int get_x()  { return x ; };
	 int get_y()  { return y; };
	 ObjectTypes get_Type() const { return ACurrentClass; }


	 ObjectColours get_Color() const { return currentColor; }


	//cant not add const because int the void function, the currentColor changes the value into BACKGROUND
	virtual void Update_status() { currentColor = BACKGROUND; }

protected:

	void set_color(const ObjectColours new_color)
	{
		currentColor = new_color;
	};
	void set_x( int new_x) { x = new_x; };
	void set_y( int new_y) { y = new_y; };


};

//int BoardObject::count=0;
#endif // H_BOARD_OBJECT

