#pragma once
#include<SFML\Graphics.hpp>
class Block
{
private:
	sf::Sprite block1;
	sf::Sprite block2;
	sf::Texture block1Tex;
	sf::Texture block2Tex;
	
	int column, row = 0;
	sf::Sprite terrain[100][10];
	sf::Sprite ter;
	//int have_terr[100][10];

	int Ramdom_Type();
	int type;


	void initTexture();
	void initSprite();
	void createBlock();
	sf::RectangleShape blockCheck;
public:
	Block(float pos_x, float pos_y);
	virtual ~Block();
	const sf::Vector2f getPosition() const;

	int count = 0;
	bool ran = false;
	float blockX=100, blockY=500;
	const sf::FloatRect getGlobalBounds() const;
	void update();
	void render(sf::RenderTarget& target);
};

