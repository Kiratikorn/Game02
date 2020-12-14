#pragma once
#include <SFML\Graphics.hpp>
class Point
{
private:
	sf::Sprite coin;
	sf::Texture coinTex;
	void initTexture();
	void initSprite();
public:
	Point(float pos_x, float pos_y);
	virtual ~Point();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds_coin() const;
	void setPosition(const float x, const float y);
	void update_point();
	void render(sf::RenderTarget& target);
};


