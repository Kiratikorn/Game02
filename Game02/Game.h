#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Opening.h"
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
//Item
#include "Potion.h"
#include "Shield.h"
//#include "Block.h"
#include "Block_dirt.h"
#include "Block_Stone.h"

#include <iostream>
#include<string>
#include<sstream>
#include<utility>
#include<algorithm>
#include<vector>

//#include "TileMap.h"
//#include "Map.h"

using namespace std;
class Game
{
private:
	FILE* fp;
	bool stopName = false;
	char temp[255];
	int scorep[6];
	string name[6];
	vector<pair<int, string>>userScore;
	bool endgames = false;

	float bossHplose = 500.f;
	void showhighscore(int x, int y, string word, sf::RenderWindow& window, sf::Font* font);
	int x = 100, y = 500;
	int column, row = 0,spawn;
	int sudoX;
	int health=5;
	int aura = 0;
	int score=0;
	int firecheck=0;
	int level = 1;
	int boss_skill=0;
	float worldY=0;
	int fireballX;
	int difficulty;
	int delaySkill;
	int delayLoadMap;
	int delayFireball;
	int delayLoseHpFireball;
	int delayShield;
	int delayItem;
	bool change_level=false;
	int bossStart = 0;
	int itemcount = 0;
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
	sf::Clock timeSkill;
	sf::Clock timeLoseHpFireball;
	sf::Clock timeShield;
	sf::Clock timeItem;

	float delayEnemyAttack;
	float delayfire;

	sf::RenderWindow* window;
	sf::Event ev;
	sf::View view;

	sf::Music musicBG;
	sf::Sound BG_sound;
	//World
	sf::Texture one;
	sf::Texture two;
	sf::Texture healthTex;
	sf::Texture shieldTex;
	sf::Texture worldBackgroundTex;
	sf::Texture op_BackgroundTex;
	sf::Texture BossHpTex;
	sf::Sprite BossHp;
	sf::Sprite op_Background;
	sf::Sprite blockOne;
	sf::Sprite blockTwo;
	sf::Sprite health_s;
	sf::Sprite shield_s;
	sf::Sprite worldBackground;
	sf::RectangleShape blockCheck;
	sf::RectangleShape check;
	sf::RectangleShape bossHpBar;
	
	sf::Font font;
	sf::Text auraText;
	sf::Text healthText;
	sf::Text scoreText;

	Mainmenu* menu;
	Opening* opening;
	Player* player;

	//Item
	Shield* shield;
	Potion* potion;
	
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
	void initItem();
	void initWorld();
	void initPlayer();
	void initEnemy();
	void deleteblock();
	void loadMap();
	int BlockX = 100, BlockY = 400;

	int spawnTimer=0;
	int spawnTimerMax=500;

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

	void update_boss();
	void update_fireabove();
	void update_enemy();
	void update_block();
	void update_dirtBlock();
	void update_stoneBlock();
	void update_firer();
	void update_fire();
	void update_fireball();
	void update_firebeam();
	void updateGUI();
	void update_Item();
	
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
	void updateOp();
	void updatePlayer();
	void updateWorld();
	void updateCollision();
	//void run();
	void MenuGUI();
	
	void update();
	void renderItem();
	void renderOp();
	void renderBlock();
	void renderGUI();
	void renderPlayer();
	void renderWorld();
	void render();
	const sf::RenderWindow & getWindow() const;
protected:
	int type;	
};

