#include "Point.h"

void Point::initTexture()
{
	this->coinTex.loadFromFile("Pic/Coin.png");
}

void Point::initSprite()
{
	this->coin.setTexture(this->coinTex);
	this->coin.setScale(1.f, 1.f);
}

Point::Point(float pos_x, float pos_y)
{
	this->initTexture();
	this->initSprite();
	this->coin.setPosition(pos_x, pos_y);
}

Point::~Point()
{
}

const sf::Vector2f Point::getPosition() const
{
	return this->coin.getPosition();
}

const sf::FloatRect Point::getGlobalBounds_coin() const
{
	return this->coin.getGlobalBounds();
}

void Point::setPosition(const float x, const float y)
{
	this->coin.setPosition(x, y);
}

void Point::update_point()
{
}

void Point::render(sf::RenderTarget& target)
{
	target.draw(this->coin);
}
