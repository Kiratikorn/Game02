#pragma once
#include<SFML\Graphics.hpp>
class Block_Stone
{
	sf::Sprite stone;
	sf::Texture stoneTex;
	//sf::RectangleShape stoneShape;
	void initTexture();
	void createBlock_stone();
public:
	Block_Stone(float pos_x, float pos_y);
	virtual ~Block_Stone();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	void update();
	void render(sf::RenderTarget& target);
};