#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "firer.h"
//#include "Platform.h"
#include "Orc.h"
#include "fire_above.h"
#include "Boss.h"
#include "Point.h"
//#include "TileMap.h"
//#include "Map.h"
class Game
{
private:
	int column, row = 0,spawn;
	sf::RenderWindow* window;
	sf::Event ev;
	sf::View view;
	//World
	sf::Texture one;
	sf::Texture two;
	sf::Sprite blockOne;
	sf::Sprite blockTwo;
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;
	sf::RectangleShape blockCheck;

	Player* player;
	firer* fire;
	Orc* orc_enemy;
	std::vector<Point*> coins;
	std::vector<Orc*> orc_enemies;
	//std::vector<Orc*> orc_enemy;
	Fire_above* fire_above;
	Boss* boss;
	bool ran = false;

	//TileMap map;
	void initWindow();
	void initWorld();
	void initPlayer();
	void initEnemy();

	float spawnTimer;
	float spawnTimerMax;

	int score=0;
public:
	Game();
	virtual ~Game();
	
	int Block();
	void showMap();
	void showBlock();
	void updateBlock();
	void enemy_view();
	void update_enemy();
	void player_attack();

	void update_coin();
	//void setPositionBlock(int x, int y);
	sf::CircleShape test;
	sf::Sprite terrain[100][10];
	int have_terr[100][10];
	float plat_left_hit;
	float plat_right_hit;
	float plat_top_hit;
	float plat_bottom_hit ;
	void collide();
	float level[100];
	//Platform level[100];
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
};

