#pragma once

#include "drawEngine.h"
#include"sprite.h"
#include "character.h"

class Game
{

public:
	bool run (void);

protected:
	bool getInput (char*);
	void timerUpdate (void);
	
private:
	Character* _player;

	double _frameCount;
	double _startTime;
	double _lastTime;

	DrawEngine _drawArea;
};