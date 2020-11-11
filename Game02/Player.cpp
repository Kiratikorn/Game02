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
	this->currentFrame = sf::IntRect(30, 100, 120, 100);//x,y,w,h
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(0.8f, 0.8f);
}

void Player::initAnimation()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::initPhysics()
{
	this->velocityMax = 6.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	this->drag = 0.90f;
	this->gravity_player = 0.f;
	this->velocityMaxY = 15.f;
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

void Player::hitbox_P()
{
	hitbox_player.setOutlineColor(sf::Color::Red);
	hitbox_player.setOutlineThickness(2.0f);
	hitbox_player.setSize(sf::Vector2f(40.f, 50.f));
	hitbox_player.setPosition(this->sprite.getPosition().x+13.f,this->sprite.getPosition().y+25.f);

	circ.setFillColor(sf::Color::Red);
	circ.setRadius(2.f);
	circ.setPosition(this->sprite.getPosition().x , this->sprite.getPosition().y+ 80.f);

}

const bool& Player::getAnimSwitch()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;

}

const sf::Vector2f Player::getPosition() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}
const sf::FloatRect Player::getGlobalBounds_hit() const
{
	return this->hitbox_player.getGlobalBounds();
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
	left_hit = x + 13.f;
	right_hit = x + 40.f + 13.f;
	top_hit = y + 25.f;
	bottom_hit = y + 80.f;

}

void Player::resetVelocityY()
{
	this->velocity.y = 0.f;
}

//void Player::collide(float xvel, float yvel, Platform level[5])
//{
//	for (int i = 0; i < 5; i++)
//	{
//		if (hitbox.left <level[i].hitbox.right &&
//			hitbox.right > level[i].hitbox.left &&
//			hitbox.top < level[i].hitbox.bottom &&
//			hitbox.bottom > level[i].hitbox.top)
//		{
//			printf("Yes");
//		}
//	}
//}


void Player::resetAnimationTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::move_x(const float dir_x, const float dir_y)
{
	//acce
	this->velocity.x += dir_x * this->acceleration;
	
	//limit velo
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void Player::updatePhysics()
{
	//GRAVITY
	this->velocity.y += 1.0 * this->gravity_player;
	if (std::abs(this->velocity.x) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}
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
		this->move_x(-1.0f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		this->move_x(1.f, 0.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;

	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		sprite.move(0.f, -5.f);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		sprite.move(0.f, 5.f);
		this->animState = PLAYER_ANIMATION_STATES::DIG;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		this->animState = PLAYER_ANIMATION_STATES::ATTACK;
	}
}

void Player::updateAnimations()
{

	if (this->animState == PLAYER_ANIMATION_STATES::IDLE)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.4f || this->getAnimSwitch())
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
		this->sprite.setScale(0.8f, 0.8f);
		this->sprite.setOrigin(0.f, 0.f);
		this->hitbox_player.setScale(1.f, 1.f);
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_LEFT)
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
		this->sprite.setScale(-0.8f, 0.8f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
		this->hitbox_player.setScale(-1.f, 1.f);
		
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::MOVING_UP)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f)
		{
			this->currentFrame.top = 700.f;
			this->currentFrame.left += 150.f;
			if (this->currentFrame.left >= 300.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::DIG)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f)
		{
			this->currentFrame.top = 890.f;
			this->currentFrame.left += 150.f;
			if (this->currentFrame.left >= 150.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == PLAYER_ANIMATION_STATES::ATTACK)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.top = 500.f;
			this->currentFrame.left += 150.f;
			if (this->currentFrame.left >= 450.f)
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
	this->hitbox_P();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->hitbox_player);
	target.draw(this->sprite);


target.draw(circ);
}
