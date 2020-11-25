#include "firer.h"

void firer::initTexture()
{
	this->firerTex.loadFromFile("Pic/firer.png");
}

void firer::initSprite()
{
	this->firer_s.setTexture(this->firerTex);
	this->firer_s.setScale(0.6f, 0.6f);

}


firer::firer(float pos_x, float pos_y)
{
	this->initTexture();
	this->initSprite();
	this->firer_s.setPosition(pos_x, pos_y);
}

firer::~firer()
{
}

const sf::Vector2f firer::getPosition() const
{
	return this->firer_s.getPosition();
}

const sf::FloatRect firer::getGlobalBounds() const
{
	return this->firer_s.getGlobalBounds();;
}

void firer::render(sf::RenderTarget& target)
{
	target.draw(this->firer_s);
}

