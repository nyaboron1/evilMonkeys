#pragma once

#include "drawEngine.h"

enum
{
	SPRITE_CLASSID,
	CHARACTER_CLASSID,
};

struct vector
{
	float x;
	float y;

	vector()
	{
		x = 0.0f;
		y = 0.0f;
	}

	vector(float p_x, float p_y)
	{
		x = p_x;
		y = p_y;
	}
};


class Sprite
{
public:
	Sprite(DrawEngine*, int, float, float, int );
	~Sprite();

	vector getPosition();

	float getX() { return _pos.x; }
	float getY() { return _pos.y; }

	int getLives() { return _lives; }

	bool isAlive();

	virtual void addLives(int p_lives);
	virtual bool move(float p_x, float p_y);


protected:
	DrawEngine* _drawArea;

	int _spriteIndex;
	int _lives;
	int _classID;

	vector _pos;
	vector _facingDirection;

	void draw(float p_x, float p_y);
	void erase(float p_x, float p_y);

private:
	
	
};
