#include "Block_stone.h"

void Block_Stone::initTexture()
{
	this->stoneTex.loadFromFile("Pic/block2.png");
}

void Block_Stone::createBlock_stone()
{
	this->stone.setScale(0.75f, 0.75f);
	this->stone.setTexture(stoneTex);
}

Block_Stone::Block_Stone(float pos_x, float pos_y)
{
	this->initTexture();
	this->stone.setPosition(pos_x, pos_y);
}

Block_Stone::~Block_Stone()
{
}

const sf::Vector2f Block_Stone::getPosition() const
{
	return this->stone.getPosition();
}

const sf::FloatRect Block_Stone::getGlobalBounds() const
{
	return this->stone.getGlobalBounds();;
}

void Block_Stone::update()
{
	this->createBlock_stone();
}

void Block_Stone::render(sf::RenderTarget& target)
{
	target.draw(this->stone);
}
