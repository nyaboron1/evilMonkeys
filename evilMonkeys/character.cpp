#include "stdafx.h"
#include "character.h"

Character::Character(DrawEngine * de, 
	int index, float x, float y, 
	int lives, char u, char d, 
	char l, char r) : Sprite(de, index, x, y, l)
{
	_up_key = u;
	_down_key = d;
	_left_key = l;
	_right_key = r;

	_classID = CHARACTER_CLASSID;
}


bool 
Character::keyPress (char p_c)
{
	if (p_c == _up_key)
		return move(0, -1);

	else if (p_c == _down_key)
		return move(0, 1);

	else if (p_c == _left_key)
		return move(-1, 0);

	else if (p_c == _right_key)
		return move(1, 0);
}


Character::~Character()
{
}