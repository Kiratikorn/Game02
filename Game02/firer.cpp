#include "firer.h"

void firer::initTexture()
{
	this->textureSheet.loadFromFile("Pic/firer.png");
}

void firer::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 120, 120);//x,y,w,h
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(0.5f, 0.5f);
	this->sprite.setPosition(20.f, 0.f);
}

void firer::fireball()
{
	int x = 0, y = 0;
	this->fireballTex.loadFromFile("Pic/fireball.png");
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

void firer::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}

