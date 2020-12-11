#pragma once
#include <SFML\Graphics.hpp>
class Fireball
{
private:
	float y;
	sf::Sprite fireball_s;
	sf::Texture fireballTex;
	void initTexture();
	void initSprite();
public:
	Fireball(float pos_x, float pos_y);
	virtual ~Fireball();
	void setPosition(const float x, const float y);
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	void updateMovement_fireball();
	void update_fireball();
	void render(sf::RenderTarget& target);
};



