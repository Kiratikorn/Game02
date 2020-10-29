#include "Player.h"
#include <stdio.h>

void Player::initVariables()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	//this->moving = false;
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
	this->animationTimer.restart();
}

void Player::initPhysics()
{
	this->velocityMax = 4.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->drag = 0.90f;
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initPhysics();
}

Player::~Player()
{
}


void Player::move(const float dir_x, const float dir_y)
{
	//acce
	this->velocity.x += dir_x * this->acceleration;
	//this->velocity.y += dir_y * this->acceleration; gravity
	//limit velo
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void Player::updatePhysics()
{
	//deceleration
	this->velocity *= this->drag;
	//limitdece
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->sprite.move(this->velocity);
}

void Player::updateMovement()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		this->move(-1.0f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->move(1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;

	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
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
	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.4f)
		{
			this->currentFrame.top = 100.f;
			this->currentFrame.left += 150.f;
			if (this->currentFrame.left > 300.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_RIGHT)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.15f)
		{
			this->currentFrame.top = 300.f;
			this->currentFrame.left += 150.f;
			if (this->currentFrame.left > 750.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else
		this->animationTimer.restart();
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
	this->updatePhysics();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
