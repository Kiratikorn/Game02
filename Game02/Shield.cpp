#include "Shield.h"

void Shield::initTexture()
{
	this->shieldTex.loadFromFile("Pic/shield.png");
	this->auraTex.loadFromFile("Pic/aura.png");
}

void Shield::initSprite()
{
	this->shield.setTexture(this->shieldTex);
	this->aura.setTexture(this->auraTex);
	this->aura.setScale(1.5f, 1.5f);
}

Shield::Shield()
{
	this->initTexture();
	this->initSprite();
}

Shield::~Shield()
{
}

const sf::FloatRect Shield::getGlobalBounds_shield() const
{
	return this->shield.getGlobalBounds();
}

const sf::Vector2f Shield::getPosition_shield() const
{
	return this->shield.getPosition();
}

void Shield::setPosition_aura(const float x, const float y)
{
	this->aura.setPosition(x, y);
}

void Shield::setPosition_shield(const float x, const float y)
{
	shieldX = x;
	shieldY = y;
	first = true;
}

void Shield::update()
{
	if (first == true && remove_shield == false)
	{
		printf("<item>");
		first = false;
	}
	else if (remove_shield == true)
	{
		this->shield.setPosition(-100.f, shieldY);
	}
	else if (first == false)
	{
		//printf("change");
		this->shield.setPosition(shieldX, shieldY);

	}
}

void Shield::render(sf::RenderTarget& target)
{
	if (remove_shield == false)
	{

		target.draw(this->shield);
	}
	if (aura_shield == true)
	{
		target.draw(this->aura);
	}
}
