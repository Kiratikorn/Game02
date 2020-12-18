
#pragma once
#include <SFML/Graphics.hpp>

class Potion
{
private:
	bool first = true;
	float potionX, potionY;
	sf::Sprite shield;
	sf::Sprite potion;
	sf::Texture shieldTex;
	sf::Texture potionTex;
	void initTexture();
	void initSprite();
public:
	Potion();
	virtual ~Potion();
	bool remove_potion = true;
	const sf::FloatRect getGlobalBounds_potion() const;
	const sf::Vector2f getPosition_potion() const;
	void setPosition_potion(const float x, const float y);
	void update();
	void render(sf::RenderTarget& target);
};


