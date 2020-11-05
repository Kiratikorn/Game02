#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "firer.h"
//#include "TileMap.h"
//#include "Map.h"
class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;

	//World
	sf::Texture one;
	sf::Texture two;
	sf::Sprite blockOne;
	sf::Sprite blockTwo;
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;

	Player* player;
	firer* fire;

	bool ran = false;

	//TileMap map;
	void initWindow();
	void initWorld();
	void initPlayer();
	

public:
	Game();
	virtual ~Game();
	int Block();
	void showMap();
	void showBlock();
	void updateBlock();
	//void setPositionBlock(int x, int y);

	void updatePlayer();
	void updateWorld();
	void updateCollision();
	//void run();
	void update();
	void renderPlayer();
	void renderWorld();
	void render();
	const sf::RenderWindow & getWindow() const;
protected:
	int type;
	
	sf::Sprite terrain[100];
};

