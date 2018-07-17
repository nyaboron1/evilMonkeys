#pragma once

class DrawEngine 
{
public:
	DrawEngine(int p_xSize = 30, int p_ySize = 20);
	~DrawEngine();

	int createSprite(int p_index, char p_c);
	void deleteSprite(int p_index);

	void eraseSprite(int p_posx, int p_posy);
	void drawSprite(int p_index, int p_posx, int p_posy);

protected:
	int _screenWidth;
	int _screenHeight;
	char _spriteImage[16];

private:
	void gotoxy(int p_x, int p_y);
	void cursorVisibility(bool p_visibility);
};