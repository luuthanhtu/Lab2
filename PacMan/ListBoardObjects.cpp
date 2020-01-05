#include <iostream>
#include "BoardObjectH.h"
#include "ListBoardObjectsH.h"

ListBoardObjects::ListBoardObjects(const p_BoardObject newOne) :list()
{
	std::vector <p_BoardObject>::iterator it;
	it = list.begin();
	list.insert(it, newOne);
}

p_BoardObject ListBoardObjects::Get_First_Object()
{
	if (0 < list.size())
	{
		internalIterator = list.begin();
		return (*internalIterator);
	}
	else
		return NULL;
}


void ListBoardObjects::add_One_Object(const p_BoardObject newOne)
{
	std::vector <p_BoardObject>::iterator it;
	it = list.begin();
	list.insert(it, newOne);
}

p_BoardObject ListBoardObjects::Get_Next_Object()
{
	internalIterator++;
	if (internalIterator < list.end())
	{
		return (*internalIterator);
	}
	else
		return NULL;
}

void ListBoardObjects::removeOnePlayer()
{
	std::vector <p_BoardObject>::iterator it;
	it = list.begin();
	while (it < list.end())
	{
		if (A_PLAYER == (*it)->get_Type())
		{
			list.erase(it); return;
		}
		it++;
	}

	return;
}


bool ListBoardObjects::isThereAWall()
{
	std::vector <p_BoardObject>::iterator it;
	it = list.begin();
	while (it < list.end())
	{
		if (A_WALL == (*it)->get_Type())
		{
			return true;
		}
		it++;
	}

	return false;
}


int ListBoardObjects::isCookieValue()
{
	int temp = 0;
	std::vector <p_BoardObject>::iterator it;
	it = list.begin();
	while (it < list.end())
	{
		if (A_COOKIE == (*it)->get_Type())
		{
			temp = ((Cookie *)(*it))->get_value();
			list.erase(it);
			return temp;
		}
		it++;
	}

	return temp;
}
