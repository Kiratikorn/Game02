#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;
	
	Player* player;

	void initWindow();
	void initPlayer();

public:
	Game();
	virtual ~Game();

	void updatePlayer();
	void run();
	void update();
	void renderPlayer();
	void render();
	const sf::RenderWindow & getWindow() const;
};

