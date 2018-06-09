#include "stdafx.h"
#include "character.h"

Character::Character(DrawEngine * de, 
	int index, float x, float y, 
	int lives, char u, char d, 
	char l, char r) : Sprite(de, index, x, y, l)
{
	up_key = u;
	down_key = d;
	left_key = l;
	right_key = r;

	_classID = CHARACTER_CLASSID;
}


bool Character::keyPress (char c)
{
	if (c == up_key)
		return move(0, -1);

	else if (c == down_key)
		return move(0, 1);

	else if (c == left_key)
		return move(-1, 0);

	else if (c == right_key)
		return move(1, 0);
}


Character::~Character()
{
}