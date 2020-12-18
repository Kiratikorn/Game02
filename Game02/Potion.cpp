#include "Potion.h"

void Potion::initTexture()
{
	this->potionTex.loadFromFile("Pic/Potion.png");
}

void Potion::initSprite()
{
	this->potion.setTexture(this->potionTex);
}

Potion::Potion()
{
	this->initTexture();
	this->initSprite();
}

Potion::~Potion()
{

}

const sf::FloatRect Potion::getGlobalBounds_potion() const
{
	return this->potion.getGlobalBounds();
}

const sf::Vector2f Potion::getPosition_potion() const
{
	return this->potion.getPosition();
}

void Potion::setPosition_potion(const float x, const float y)
{
	printf("setposition");
	potionX = x;
	potionY = y;
	first = true;
}

void Potion::update()
{
	if (first == true && remove_potion == false)
	{
		printf("<item>");
		first = false;
	}
	else if (remove_potion == true)
	{
		this->potion.setPosition(-100.f, potionY);
	}
	else if (first == false)
	{
		//printf("change");
		this->potion.setPosition(potionX, potionY);

	}
}

void Potion::render(sf::RenderTarget& target)
{
	if (remove_potion == false)
	{

		target.draw(this->potion);
	}
}
