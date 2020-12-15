#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"

#include "Mainmenu.h"
#include "Textbox.h"
//fire
#include "firer.h"
#include "Fire.h"
#include "Fireball.h"
#include "fire_above.h"
#include "fireBeam.h"
//
#include "Orc.h"
#include "Boss.h"
#include "Point.h"
//#include "Block.h"
#include "Block_dirt.h"
#include "Block_Stone.h"

#include <iostream>
#include<string>
#include<sstream>
//#include "TileMap.h"
//#include "Map.h"

using namespace std;
class Game
{
private:
	int x = 100, y = 500;
	int column, row = 0,spawn;
	int health=5;
	int score=0;
	int firecheck=0;
	int level = 1;
	float worldY=0;
	int fireballX;
	int difficulty;
	int delayLoadMap;
	int delayFireball;
	bool change_level=false;
	bool bossskill=false;
	bool play = false;
	bool enterName = false;
	int gameState = 0;

	//mouse
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosview;

	sf::Clock timeEnemyAttack;
	sf::Clock timefire;
	sf::Clock timedifficulty;
	sf::Clock timeLoadMap;
	sf::Clock timeFireball;


	float delayEnemyAttack;
	float delayfire;

	sf::RenderWindow* window;
	sf::Event ev;
	sf::View view;
	//World
	sf::Texture one;
	sf::Texture two;
	sf::Texture healthTex;
	sf::Texture worldBackgroundTex;
	sf::Texture op_BackgroundTex;
	sf::Texture BossHpTex;
	sf::Sprite BossHp;
	sf::Sprite op_Background;
	sf::Sprite blockOne;
	sf::Sprite blockTwo;
	sf::Sprite health_s;
	sf::Sprite worldBackground;
	sf::RectangleShape blockCheck;
	sf::RectangleShape check;
	sf::RectangleShape bossHpBar;
	
	sf::Font font;
	sf::Text healthText;
	sf::Text scoreText;

	Mainmenu* menu;
	Player* player;
	
	std::vector<Point*> coins;
	std::vector<Orc*> orc_enemies;
	std::vector<Block_dirt*> dirtBlocks;
	std::vector<Block_Stone*> stoneBlocks;
	std::vector<firer*> firers;
	std::vector<Fire*> fires;
	std::vector<Fireball*> fireballs;
	std::vector<fireBeam*> firebeams;
	//std::vector<Block*> blocks;
	//std::vector<Orc*> orc_enemy;
	//fireBeam* firebeam;
	Fire_above* fire_above;
	Boss* boss;
	bool ran = false;

	//TileMap map;
	
	void playgame();
	void initWindow();
	void initWorld();
	void initPlayer();
	void initEnemy();
	void deleteblock();
	void loadMap();
	int BlockX = 100, BlockY = 400;

	float spawnTimer=0;
	float spawnTimerMax;

public:
	Game();
	virtual ~Game();
	
	void run();
	void updateMousePositions();

	void initGUI();

	int Block_ran();
	void showMap();
	void showBlock();
	void createBlock();
	void updateBlock();
	void enemy_view();
	void enemy_walk();

	void update_enemy();
	void update_block();
	void update_dirtBlock();
	void update_stoneBlock();
	void update_firer();
	void update_fire();
	void update_fireball();
	void update_firebeam();
	void updateGUI();
	
	void boss_attack();
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
	//float level[100];
	//Platform level[100];
	void updatePlayer();
	void updateWorld();
	void updateCollision();
	//void run();
	void MenuGUI();
	
	void update();
	void renderBlock();
	void renderGUI();
	void renderPlayer();
	void renderWorld();
	void render();
	const sf::RenderWindow & getWindow() const;
protected:
	int type;	
};

