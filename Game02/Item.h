#pragma once
#include <SFML/Graphics.hpp>

class Item
{
private:
	int ranItem = 0;
	bool first = true;
	float potionX, potionY;
	float shieldX, shieldY;
	sf::Sprite shield;
	sf::Sprite potion;
	sf::Texture shieldTex;
	sf::Texture potionTex;
	void initTexture();
	void initSprite();
public:
	Item();
	virtual ~Item();
	bool remove_item = true;
	//const sf::FloatRect getGlobalBounds_shield() const;
	//const sf::FloatRect getGlobalBounds_potion() const;
	const sf::Vector2f getPosition_potion() const;
	const sf::Vector2f getPosition_shield() const;
	void setPosition_potion(const float x, const float y);
	void setPosition_shield(const float x, const float y);
	void update();
	void render(sf::RenderTarget& target);
};

