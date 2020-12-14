#pragma once
#include <SFML\Graphics.hpp>
class Fire
{
private:
	int fireX, xplus=4 ;
	sf::Sprite fire_s;
	sf::Texture fireballTex;
	void initTexture();
	void initSprite();
public:
	Fire(float pos_x, float pos_y);
	virtual ~Fire();
	void setPosition(const float x, const float y);
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	void updateMovement_fire();
	void update_fire();
	void render(sf::RenderTarget& target);
};

