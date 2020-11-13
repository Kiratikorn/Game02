#include "firer.h"

void firer::initTexture()
{
	this->firerTex.loadFromFile("Pic/firer.png");
	this->fireballTex.loadFromFile("Pic/fireball.png");

}

void firer::initSprite()
{
	this->firer_s.setTexture(this->firerTex);
	this->firer_s.setScale(0.5f, 0.5f);
	this->firer_s.setPosition(20.f, 0.f);
	
	this->fire_s.setTexture(this->fireballTex);
	this->fire_s.setScale(-0.3f, 0.3f);
}

void firer::fireball()
{
	int x = 0, y = 0;
	
	//for(int x)
	
}

firer::firer()
{
	this->initTexture();
	this->initSprite();
}

firer::~firer()
{
}

void firer::updateMovement_fire()
{
	x += 4.f;
	fire_s.setPosition(x, this->firer_s.getPosition().y+5.f);
	if (x >= 550.f)
	{
		x = 50.f;
	}

}

void firer::update_firer()
{
	this->updateMovement_fire();
}

void firer::render(sf::RenderTarget& target)
{
	target.draw(this->fire_s);
	target.draw(this->firer_s);
}

