#pragma once
#include <SFML\Graphics.hpp>
class firer
{
private:

	sf::Sprite sprite;
	sf::Texture textureSheet;
	sf::Texture fireballTex;
	sf::IntRect currentFrame;
	void initTexture();
	void initSprite();
	void fireball();
public:
	firer();
	virtual ~firer();
	void render(sf::RenderTarget& target);
};

