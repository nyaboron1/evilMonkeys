#pragma once

#include "sprite.h"

class Character : public Sprite
{
public:
	Character(DrawEngine* de, int index, float x = 1, float y = 1, int lives = 3,
		char up_key = 'w', 
		char down_key = 's', 
		char left_key = 'a',
		char right_key = 'd');

	~Character();

	virtual bool keyPress (char p_c);

protected:
	DrawEngine* _de;

	char _up_key;
	char _down_key;
	char _left_key; 
	char _right_key;

	int _index; 
	int _lives;

	float _x = 1.0f;
	float _y = 1.0f;
};

