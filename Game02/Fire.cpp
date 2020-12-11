#include "Fire.h"

void Fire::initTexture()
{
	this->fireballTex.loadFromFile("Pic/fireball.png");
}

void Fire::initSprite()
{

	this->fire_s.setTexture(this->fireballTex);
	this->fire_s.setScale(-0.4f, 0.4f);
}

Fire::Fire(float pos_x, float pos_y)
{
	this->initTexture();
	this->initSprite();
	this->fire_s.setPosition(pos_x, pos_y);
	x = pos_x;
}

Fire::~Fire()
{
}

void Fire::setPosition(const float x, const float y)
{
	this->fire_s.setPosition(x, y);
	xplus = 0;

}

const sf::Vector2f Fire::getPosition() const
{
	return this->fire_s.getPosition();
}

const sf::FloatRect Fire::getGlobalBounds() const
{
	return this->fire_s.getGlobalBounds();;
}

void Fire::updateMovement_fire()
{
	if (x == -200.f)
	{
		xplus = 0;
	}
	if (xplus == 4)
	{
		x += xplus;
		fire_s.setPosition(x, this->fire_s.getPosition().y);
		if (x >= 550.f)
		{
			x = 100.f;
		}
	}
	

}

void Fire::update_fire()
{
	this->updateMovement_fire();
}

void Fire::render(sf::RenderTarget& target)
{
	target.draw(this->fire_s);
}

