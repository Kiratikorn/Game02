#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;

	//World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;

	Player* player;

	void initWindow();
	void initWorld();
	void initPlayer();
	

public:
	Game();
	virtual ~Game();

	
	void updatePlayer();
	void updateWorld();
	void updateCollision();
	//void run();
	void update();
	void renderPlayer();
	void renderWorld();
	void render();
	const sf::RenderWindow & getWindow() const;
};

