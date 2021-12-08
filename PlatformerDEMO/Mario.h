#pragma once
#include "Entity.h"
class Mario: public Entity
{
private:
	int jump_limit;
public:
	Mario();
	Mario(int px, int py, int pw, int ph);
	~Mario();

	void Gravity(vector<Rectangle*> platforms);
	bool OnPlatform(vector<Rectangle*> platforms);
	direction BlockedPath(vector<Rectangle*> platforms);
};

