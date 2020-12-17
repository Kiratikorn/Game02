#include "Fireball.h"

void Fireball::initTexture()
{
	this->fireballTex.loadFromFile("Pic/dragon_fire.png");
}

void Fireball::initSprite()
{
	this->fireballShape.setRadius(40);
	this->fireballShape.setTexture(&this->fireballTex);
	//this->fireball_s.setTexture(this->fireballTex);
	this->fireball_s.setScale(0.1f, 0.1f);
}

Fireball::Fireball(float pos_x, float pos_y)
{
	this->initTexture();
	this->initSprite();
	this->fireball_s.setPosition(pos_x, pos_y);
	y = pos_y;
}

Fireball::~Fireball()
{

	
}

void Fireball::setPosition(const float x, const float y)
{
	this->fireballShape.setPosition(x, y);
}

const sf::Vector2f Fireball::getPosition() const
{
	return this->fireballShape.getPosition();
}

const sf::FloatRect Fireball::getGlobalBounds() const
{
	return this->fireballShape.getGlobalBounds();;
}

void Fireball::updateMovement_fireball()
{

	y += 4.f;
	fireballShape.setPosition(this->fireball_s.getPosition().x, y);
	fireballShape.setOrigin(this->fireballShape.getLocalBounds().width / 2.f, this->fireballShape.getLocalBounds().width / 2.f);
	fireballShape.rotate(10.f);


}

void Fireball::update_fireball()
{
	if (remove == true)
		this->updateMovement_fireball();
}

void Fireball::render(sf::RenderTarget& target)
{
	if(remove==true)
		target.draw(this->fireballShape);

}
