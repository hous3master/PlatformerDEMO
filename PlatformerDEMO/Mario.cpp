#include "Mario.h"
Mario::Mario(){}
Mario::Mario(int px, int py, int pw, int ph) : Entity(px, py, pw, ph, 4, 12, 0, 2) {
	vertical_velocity = 300;
	horizontal_velocity = 30;
	jump_limit = 100;
}
Mario::~Mario(){}
void Mario::Gravity(vector<Rectangle*> platforms) {
	if (!OnPlatform(platforms))
		y += 20;
}
bool Mario::OnPlatform(vector<Rectangle*> platforms) {
	Rectangle platform_detector(x, y + h, w, 20);
	for (int i = 0; i < platforms.size(); i++) {
		if (platform_detector.IntersectsWith(*platforms.at(i)))
			return true;
	}
	return false;
}
direction Mario::BlockedPath(vector<Rectangle*> platforms) {
	Rectangle obstacle_detector;
	if (orientation == direction::left) {
		obstacle_detector.X = x - 20;
		obstacle_detector.Y = y;
		obstacle_detector.Width = 20;
		obstacle_detector.Height = h - 5;
	}
	if (orientation == direction::right) {
		obstacle_detector.X = x + w;
		obstacle_detector.Y = y;
		obstacle_detector.Width = 20;
		obstacle_detector.Height = h - 5;
	}
		obstacle_detector = Rectangle(x + w, y, 20, h - 5);
	for (int i = 0; i < platforms.size(); i++) {
		if (obstacle_detector.IntersectsWith(*platforms.at(i)))
			return orientation;
	}
	return direction::down;
}