#pragma once

#include "drawEngine.h"
#include"sprite.h"

class Game
{

public:
	bool run (void);

protected:
	bool getInput (char*);
	void timerUpdate (void);
	
private:
	Sprite* _player;

	double _frameCount;
	double _startTime;
	double _lastTime;

	DrawEngine _drawArea;
};