#include "Game.h"

#include <iostream>

#include "Map.h"
#include "Tank.h"
#include "World.h"

using namespace sf;

Game::Game() {
	window = new RenderWindow(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Battle City");
	 world = new World;
	 map = new Map(0);
	 input = new Input(Keyboard::W, Keyboard::S, Keyboard::A, Keyboard::D, Keyboard::Space);
	 tank = new Tank(B, YELLOW, input);

	start();
}

void Game::start() const {
	float deltaTime = 0;
	Clock clock;

	while (window->isOpen())
	{
		deltaTime += clock.restart().asSeconds();
		Event event{};

		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}

		if (deltaTime >= UPDATE_INTERVAL) {
			update(deltaTime);
			render();
			deltaTime = 0;
		}
	}
}

void Game::update(const float deltaTime) const {
	tank->update(world, map, deltaTime);
}

void Game::render() const {
	window->clear();

	for (Object *object : world->getProjectiles()) {
		object->render(*window);
	}

	 map->render(*window);
	 tank->render(*window);
	window->display();
}
