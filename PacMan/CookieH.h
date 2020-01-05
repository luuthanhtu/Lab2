#pragma once
#ifndef H_COOKIE
#define H_COOKIE
const enum CookieState { VISIBLE, EATEN, EXPIRED };

const enum PrizeValueIndex { CHEAP, MEDIUM, USEFUL, DEAR };


#include "BoardObjectH.h"

class Cookie : public BoardObject
{

private:
	CookieState status;
	ObjectColours Cookies_color1;
	ObjectColours  Cookies_color2;
	PrizeValueIndex valueIndex;

public:
	Cookie(int start_x, int start_y) :BoardObject(start_x, start_y)
	{
		status = VISIBLE;
		Cookies_color1 = YELLOW;
		Cookies_color2 = BLUE;
		valueIndex = CHEAP;
		ACurrentClass = A_COOKIE;
	};

	int get_value();

	void Update_status();
};
#endif
