#include "stdafx.h"
#include "sprite.h"


Sprite::Sprite(DrawEngine* de, int s_index, 
	float x = 1, 
	float y = 1 , 
	int lives = 1)
{
	_drawArea = de;
	_spriteIndex = s_index;

	_pos.x = x;
	_pos.y = y;

	_lives = lives;

	_facingDirection.x = 1;
	_facingDirection.y = 0;

	_classID = SPRITE_CLASSID;
}


Sprite::~Sprite()
{
	// erase the dying sprite
	erase(_pos.x, _pos.y);
}

vector Sprite::getPosition()
{
	return _pos;
}


void 
Sprite::addLives(int p_lives)
{
	if (p_lives >= 0)
		_lives += p_lives;
}


bool 
Sprite::isAlive()
{
	return (_lives > 0);
}


bool
Sprite::move(float p_x, float p_y)
{
	// erase sprite
	erase(_pos.x, _pos.y);

	_facingDirection.x = 1;
	_facingDirection.y = 0;

	// set new position
	_pos.x += p_x;
	_pos.y += p_y;

	// draw sprite
	draw(_pos.x, _pos.y);

	return true;
}

void Sprite::draw(float p_x, float p_y)
{
	_drawArea->drawSprite(_spriteIndex, (int)p_x, (int)p_y);
}

void Sprite::erase(float p_x, float p_y)
{
	_drawArea->eraseSprite((int)p_x, (int)p_y);
}
