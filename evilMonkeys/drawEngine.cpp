
#include "stdafx.h"
#include "drawEngine.h"

#include <windows.h>
#include <iostream>

DrawEngine::DrawEngine(int p_xSize, int p_ySize)
{
	_screenWidth = p_xSize;
	_screenHeight = p_ySize;

	// set cursor visibility to false
	cursorVisibility(false);
}


DrawEngine::~DrawEngine()
{
	// set curspr visibility to true
	cursorVisibility(true);
}


int
DrawEngine::createSprite(int p_index, char p_c)
{
	if (p_index >= 0 && p_index < 16)
	{
		_spriteImage[p_index] = p_c;
		return p_index;
	}
	
	return -1;
}


void 
DrawEngine::drawSprite(int p_index, int p_posx, int p_posy)
{
	// go to the correct location
	gotoxy(p_posx, p_posy);
	// draw the sprite with cout
	std::cout << _spriteImage[p_index];
}


void
DrawEngine::eraseSprite(int p_posx, int p_posy)
{
	gotoxy(p_posx, p_posy);
	std::cout << ' ';
}


void
DrawEngine::gotoxy(int p_x, int p_y)
{
	HANDLE output_handle;
	COORD pos;

	pos.X = p_x;
	pos.Y = p_y;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(output_handle, pos);
}


void 
DrawEngine::cursorVisibility(bool p_visibility)
{
	HANDLE output_handle;
	CONSOLE_CURSOR_INFO cciInfo;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorInfo(output_handle, &cciInfo);
}


void 
DrawEngine::deleteSprite(int p_index)
{
	// this implementation is not need
}