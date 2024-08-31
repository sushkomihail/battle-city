#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "Input.h"
#include "Map.h"
#include "Tank.h"

class Game
{
public:
	Game();

private:
	const int WINDOW_WIDTH = 832;
	const int WINDOW_HEIGHT = 832;
	const int FPS = 64;
	const float UPDATE_INTERVAL = static_cast<float>(1) / static_cast<float>(FPS);

	sf::RenderWindow* window;
	 World *world;
	 Map* map;
	 Tank* tank;
	 Input* input;

	void start() const;
	void update(float deltaTime) const;
	void render() const;
};

#endif // GAME_H
