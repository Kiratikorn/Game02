#include "Block.h"

int Block::Ramdom_Type()
{
	this->type = rand() % 3;
	return type;
}

void Block::initTexture()
{
	this->block1Tex.loadFromFile("Pic/block1.png");
	this->block2Tex.loadFromFile("Pic/block2.png");

}

void Block::initSprite()
{
	this->block1.setTexture(this->block1Tex);
	this->block2.setTexture(this->block2Tex);

}

void Block::createBlock()
{
		//Ramdom_Type();
	type = 1;
		this->ter.setScale(0.75, 0.75);
		if (this->type <= 1)
		{

			this->ter.setTexture(block1Tex);
			//this->have_terr[column][row] = 1;
		}
		else if (this->type == 2)
		{
			this->ter.setTexture(block2Tex);
			//this->have_terr[column][row] = 2;
		}
		//else if (this->type == 3)
		//{
		//	//this->have_terr[column][row] = 0;
		//}
	}
	//this->ran = false;
	//blockX = 100;
	//if (this->ran == false)
	//{
	//	for (column = 0; column < 50; column++)
	//	{
	//		for (row = 0; row <= 5; row++)
	//		{
	//			Ramdom_Type();
	//			if (this->type <= 1)
	//			{
	//				this->terrain[column][row].setTexture(block1Tex);
	//				this->have_terr[column][row] = 1;
	//			}
	//			else if (this->type == 2)
	//			{
	//				this->terrain[column][row].setTexture(block2Tex);
	//				this->have_terr[column][row] = 2;
	//			}
	//			else if (this->type == 3)
	//			{
	//				this->have_terr[column][row] = 0;
	//			}


	//		}

	//	}
	//	this->ran = true;
	//}

	//if (this->ran == true)
	//{
	//	for (column = 0; column < 50; column++)
	//	{
	//		for (row = 0; row <= 4; row++)
	//		{
	//			this->terrain[column][row].setScale(0.75f, 0.75f);
	//			//this->terrain[column][row].setPosition(blockX, blockY);
	//			if (this->have_terr[column][row] != 0)
	//			{
	//				this->blockCheck.setOutlineColor(sf::Color::Cyan);
	//				this->blockCheck.setOutlineThickness(2.f);
	//				this->blockCheck.setFillColor(sf::Color::Transparent);
	//				//this->blockCheck.setPosition(terrain[column][row].getPosition().x, terrain[column][row].getPosition().y);
	//				this->blockCheck.setSize(sf::Vector2f(120.f * 0.75f, 120.f * 0.75f));
	//			}
	//			blockX += 88;
	//		}
	//	}
	//}}

Block::Block(float pos_x, float pos_y)
{
	this->initTexture();
	this->initSprite();
	this->ter.setPosition(pos_x, pos_y);
	//this->block2.setPosition(pos_x, pos_y);
}

Block::~Block()
{
}

const sf::Vector2f Block::getPosition() const
{
	return this->ter.getPosition();
}

const sf::FloatRect Block::getGlobalBounds() const
{
	return this->blockCheck.getGlobalBounds();
}

void Block::update()
{
	this->createBlock();
}

void Block::render(sf::RenderTarget& target)
{

	target.draw(this->ter);
	//target.draw(this->blockCheck);
}
