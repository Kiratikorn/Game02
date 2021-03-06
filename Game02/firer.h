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
	firer(float pos_x, float pos_y);
	virtual ~firer();
	void setPosition(const float x, const float y);

	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	void render(sf::RenderTarget& target);
};

