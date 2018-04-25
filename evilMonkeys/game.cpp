#include "stdafx.h"

#include "game.h"

#include <Windows.h>
#include <conio.h>
#include <iostream>

// set game speed
#define GAME_SPEED (1000 / 30)

bool Game::run(void)
{
	_drawArea.createSprite(0, '$');

	_player = new Sprite(&_drawArea, 0, 1, 1, 1);

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

		//std::cout << "Here's what you presed: " << key << std::endl;
	}
	
	std::cout << _frameCount / ((timeGetTime() - _startTime) / 1000) << "fps" << std::endl;
	std::cout << "End of the game" << std::endl;

	return true;
}

bool Game::getInput(char* c)
{
	if (_kbhit())
	{
		*c = _getch();
		return true;
	}

	return false;
}

void Game::timerUpdate(void)
{
	double currentTime = timeGetTime() - _lastTime;

	if (currentTime < GAME_SPEED)
		return;
	
	_player->move(1, 1);

	_frameCount++;

	_lastTime = timeGetTime();
}