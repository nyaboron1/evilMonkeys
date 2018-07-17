#pragma once

#include "drawEngine.h"
#include"sprite.h"
#include "character.h"

class Game
{
public:
	bool run (void);

protected:
	bool getInput (char* p_c);
	void timerUpdate ();
	
private:
	Character* _player;

	double _frameCount;
	double _startTime;
	double _lastTime;

	DrawEngine _drawArea;
};