#pragma once
#include <SFML\Graphics.hpp>
class firer
{
private:
	int x = 50.f;
	sf::Sprite firer_s;
	sf::Sprite fire_s;
	sf::Texture firerTex;
	sf::Texture fireballTex;
	sf::IntRect currentFrame;
	void initTexture();
	void initSprite();
	void fireball();
public:
	firer();
	virtual ~firer();
	void updateMovement_fire();
	void update_firer();
	void render(sf::RenderTarget& target);
};

