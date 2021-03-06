#include "stdafx.h"

#include "game.h"

#include <Windows.h>
#include <conio.h>
#include <iostream>

// set game speed
#define GAME_SPEED (1000 / 10)

bool 
Game::run()
{
	_drawArea.createSprite(0, '$');

	_player = new Character(&_drawArea, 0);

	char key = ' ';

	_startTime = timeGetTime();
	_lastTime = 0;
	_frameCount = 0;

	while (key != 'q')
	{
		while (!getInput(&key))
		{
			timerUpdate();
		}

		_player->keyPress(key);

		//std::cout << "Here's what you presed: " << key << std::endl;
	}
	
	std::cout << _frameCount / ((timeGetTime() - _startTime) / 1000) << "fps" << std::endl;
	std::cout << "End of the game" << std::endl;

	return true;
}


bool 
Game::getInput(char* p_c)
{
	if (_kbhit())
	{
		*p_c = _getch();
		return true;
	}

	return false;
}


void 
Game::timerUpdate()
{
	double currentTime = timeGetTime() - _lastTime;

	if (currentTime < GAME_SPEED)
		return;

	_frameCount++;

	_lastTime = timeGetTime();
}