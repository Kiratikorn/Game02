#pragma once
#include<SFML\Graphics.hpp>
class Block_dirt
{
	sf::Sprite dirt;
	sf::Texture dirtTex;

	void initTexture();
	void createBlock_dirt();
public:
	Block_dirt(float pos_x, float pos_y);
	virtual ~Block_dirt();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	void update();
	void render(sf::RenderTarget& target);
};