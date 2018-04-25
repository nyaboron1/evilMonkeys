
#include "stdafx.h"
#include "drawEngine.h"

#include <windows.h>
#include <iostream>

DrawEngine::DrawEngine(int xSize, int ySize)
{
	_screenWidth = xSize;
	_screenHeight = ySize;

	// set cursor visibility to false
	cursorVisibility(false);
}

DrawEngine::~DrawEngine()
{
	// set curspr visibility to true
	cursorVisibility(true);
}

int DrawEngine::createSprite(int index, char c)
{
	if (index >= 0 && index < 16)
	{
		_spriteImage[index] = c;
		return index;
	}
	
	return -1;
}

void DrawEngine::drawSprite(int index, int posx, int posy)
{
	// go to the correct location
	gotoxy(posx, posy);
	// draw the sprite with cout
	std::cout << _spriteImage[index];
}

void DrawEngine::eraseSprite(int posx, int posy)
{
	gotoxy(posx, posy);
	std::cout << ' ';
}

void DrawEngine::gotoxy(int x, int y)
{
	HANDLE output_handle;
	COORD pos;

	pos.X = x;
	pos.Y = y;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(output_handle, pos);
}

void DrawEngine::cursorVisibility(bool visibility)
{
	HANDLE output_handle;
	CONSOLE_CURSOR_INFO cciInfo;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorInfo(output_handle, &cciInfo);
}

void DrawEngine::deleteSprite(int index)
{
	// this implementation is not need
}