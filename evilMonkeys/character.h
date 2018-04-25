#pragma once

#include "sprite.h"

class Character : public Sprite
{
public:

	Character(DrawEngine* de, int index, float x = 1, float y = 1, int lives = 3,
		char up_key = 'w', char down_key = 's', char left_key = 'a',
		char right_key = 'd');

	Character();
	~Character();

	virtual void keyPress();

protected:

};

