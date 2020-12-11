#include "Fireball.h"

void Fireball::initTexture()
{
	this->fireballTex.loadFromFile("Pic/dragon_fire.png");
}

void Fireball::initSprite()
{
	this->fireball_s.setTexture(this->fireballTex);
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
	this->fireball_s.setPosition(x, y);
}

const sf::Vector2f Fireball::getPosition() const
{
	return this->fireball_s.getPosition();
}

const sf::FloatRect Fireball::getGlobalBounds() const
{
	return this->fireball_s.getGlobalBounds();;
}

void Fireball::updateMovement_fireball()
{

	y += 4.f;
	fireball_s.setPosition(this->fireball_s.getPosition().x, y);
	fireball_s.setOrigin(this->fireball_s.getLocalBounds().width / 2.f, this->fireball_s.getLocalBounds().width / 2.f);
	fireball_s.rotate(10.f);


}

void Fireball::update_fireball()
{
	this->updateMovement_fireball();
}

void Fireball::render(sf::RenderTarget& target)
{
	target.draw(this->fireball_s);

}
