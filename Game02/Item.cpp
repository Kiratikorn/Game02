#include "Item.h"

void Item::initTexture()
{
	this->potionTex.loadFromFile("Pic/Potion.png");
	this->shieldTex.loadFromFile("Pic/shield.png");
}

void Item::initSprite()
{
	this->potion.setTexture(this->potionTex);
	this->shield.setTexture(this->shieldTex);
}

Item::Item()
{
	this->initTexture();
	this->initSprite();
}

Item::~Item()
{
}

//const sf::FloatRect Item::getGlobalBounds_shield() const
//{
//	return this->shield.getGlobalBounds();
//}

//const sf::FloatRect Item::getGlobalBounds_potion() const
//{
//	return this->potion.getGlobalBounds();
//}

const sf::Vector2f Item::getPosition_potion() const
{
	return this->potion.getPosition();
}

const sf::Vector2f Item::getPosition_shield() const
{
	return this->shield.getPosition();
}

void Item::setPosition_potion(const float x, const float y)
{
	potionX = x;
	potionY = y;
	first = true;
}

void Item::setPosition_shield(const float x, const float y)
{
	shieldX = x;
	shieldY = y;
	first = true;
}

void Item::update()
{
	if (first == true && remove_item == false)
	{
		printf("<item>");
		ranItem = rand() % 2 + 1;
		first = false;
	}
	if (ranItem == 1 && first == false)
	{
		this->potion.setPosition(potionX, potionY);

	}
	if (ranItem == 2 && first == false)
	{
		this->shield.setPosition(shieldX, shieldY);
	}

}

void Item::render(sf::RenderTarget& target)
{
	if (ranItem == 1 && remove_item ==false)
	{
		
		target.draw(this->potion);
	}
	else if(ranItem == 2 && remove_item == false)
	{
		
		target.draw(this->shield);
	}
}
