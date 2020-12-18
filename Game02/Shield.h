#pragma once
#include <SFML/Graphics.hpp>

class Shield
{
private:
	bool first = true;
;
	float shieldX, shieldY;
	sf::Sprite shield;
	sf::Sprite aura;
	sf::Texture auraTex;
	sf::Texture shieldTex;
	
	void initTexture();
	void initSprite();
public:
	Shield();
	virtual ~Shield();
	bool remove_shield = true;
	bool aura_shield = false;
	const sf::FloatRect getGlobalBounds_shield() const;
	const sf::Vector2f getPosition_shield() const;
	void setPosition_aura(const float x, const float y);
	void setPosition_shield(const float x, const float y);
	void update();
	void render(sf::RenderTarget& target);
};

