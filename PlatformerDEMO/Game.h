#pragma once
#include "Mario.h"
class Game
{
private:
	Mario* player;
	vector<Rectangle*> platforms;
public:
	Game();
	~Game();
	void Create_platforms();
	void new_orientation(direction new_data);
	void Draw_player(Graphics^ g, Bitmap^ bmp);
};

