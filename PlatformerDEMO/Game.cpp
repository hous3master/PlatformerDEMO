#include "Game.h"
Game::Game() {
	player = new Mario(100, 100, 1, 1);
	Create_platforms();
}
Game::~Game(){}
void Game::Create_platforms() {
	platforms.push_back(new Rectangle(306, 482, 52, 50)); //bloc 1
	platforms.push_back(new Rectangle(632, 268, 52, 50)); //block 2
	platforms.push_back(new Rectangle(522, 482, 272, 50)); //block row
	platforms.push_back(new Rectangle(0, 689, 800, 111)); //floor
}
void Game::new_orientation(direction new_data) {
	if (player->BlockedPath(platforms) != new_data)
		player->new_orientation(new_data);
}
void Game::Draw_player(Graphics^ g, Bitmap^ bmp) {
	player->Move(g);
	player->Gravity(platforms);
	player->Draw_from_image(g, bmp);
}
