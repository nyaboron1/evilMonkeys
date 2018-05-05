#include "stdafx.h"
#include "character.h"



Character::Character(DrawEngine * de, 
	int index, float x, float y, 
	int lives, char u, char d, 
	char l, char r) : Sprite(de, index, x, y, l)
{
	_de = de;

	index = index;

	x = x;
	y = y;

	lives = lives;

	up_key = u;
	down_key = d;
	left_key = l;
	right_key = r;
}


Character::~Character()
{
}


void Character::keyPress()
{

}


