


#include "BoardObjectH.h"
#include "CookieH.h"

int PrizeValues[] = { 10,20,30,40 };

void Cookie::Update_status()
{
	switch (status)
	{
	case VISIBLE: if (Cookies_color1 == get_Color())
		set_color(Cookies_color2);
				  else
		set_color(Cookies_color1);
		break;
	case  EATEN:
	case  EXPIRED:
		set_color(BACKGROUND);
	}
}

int Cookie::get_value()
{
	return PrizeValues[valueIndex];
}

