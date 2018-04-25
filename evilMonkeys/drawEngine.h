#pragma once

class DrawEngine 
{
public:
	DrawEngine(int xSize = 30, int ySize = 20);
	~DrawEngine();

	int createSprite(int index, char c);
	void deleteSprite(int index);

	void eraseSprite(int posx, int posy);
	void drawSprite(int index, int posx, int posy);

protected:
	int _screenWidth;
	int _screenHeight;
	char _spriteImage[16];

private:
	void gotoxy(int x, int y);
	void cursorVisibility(bool visibility);
};