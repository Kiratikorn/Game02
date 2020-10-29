#include "Player.h"
#include <stdio.h>

void Player::initVariable()
{
	this->moving = false;
}

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("Pic/Sprite.png"))
	{
		printf("Pic ERROR");
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 100, 120, 110);//x,y,w,h
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(0.8f, 0.8f);
}

void Player::initAnimation()
{
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}


void Player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->sprite.move(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->sprite.move(1.f, 0.f);
	}if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		this->sprite.move(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->sprite.move(1.f, 0.f);
	}
}

void Player::updateAnimations()
{

}

void Player::update()
{
	this->updateMovement();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
