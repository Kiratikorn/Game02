#include "Block_dirt.h"

void Block_dirt::initTexture()
{
	this->dirtTex.loadFromFile("Pic/block1.png");
}

void Block_dirt::createBlock_dirt()
{
	this->dirt.setScale(0.75f, 0.75f);
	this->dirt.setTexture(dirtTex);
}

Block_dirt::Block_dirt(float pos_x, float pos_y)
{
	this->initTexture();
	this->dirt.setPosition(pos_x, pos_y);
}

Block_dirt::~Block_dirt()
{
}

const sf::Vector2f Block_dirt::getPosition() const
{
	return this->dirt.getPosition();
}

const sf::FloatRect Block_dirt::getGlobalBounds() const
{
	return this->dirt.getGlobalBounds();;
}

void Block_dirt::update()
{
	this->createBlock_dirt();
}

void Block_dirt::render(sf::RenderTarget& target)
{
	target.draw(this->dirt);
}
