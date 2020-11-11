#include "Fire_above.h"

void Fire_above::initVariables()
{
	this->animState = FA_ANIMATION_STATES::IDLE_FA;
}

void Fire_above::initTexture()
{
	this->fire_aboveTex.loadFromFile("Pic/Fire_above.png");
}

void Fire_above::initSprite()
{
	this->fire_above_S.setTexture(this->fire_aboveTex);
	this->currentFrame = sf::IntRect(0, 0, 500, 100);//x,y,w,h
	this->fire_above_S.setTextureRect(this->currentFrame);
	this->fire_above_S.setScale(1.2f, 1.2f);
	this->fire_above_S.setPosition(20.f, 0.f);
}

void Fire_above::initAnimation()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}


Fire_above::Fire_above()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Fire_above::~Fire_above()
{
}

void Fire_above::updateMovement_FA()
{
	this->animState = FA_ANIMATION_STATES::IDLE_FA;
	fire_above_S.move(0.f, 0.5f);
}

const bool& Fire_above::getAnimSwitch_FA()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

void Fire_above::updateAnimation_FA()
{
	if (this->animState == FA_ANIMATION_STATES::IDLE_FA)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f || this->getAnimSwitch_FA())
		{
			this->currentFrame.top += 100.f;
			if (this->currentFrame.top > 300.f)
				this->currentFrame.top = 0;
			this->animationTimer.restart();
			this->fire_above_S.setTextureRect(this->currentFrame);
		}
	}
	else
		this->animationTimer.restart();
}

void Fire_above::resetAnimationTimer_FA()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Fire_above::update_FA()
{
	this->updateAnimation_FA();
	this->updateMovement_FA();
}

void Fire_above::render(sf::RenderTarget& target)
{
	target.draw(this->fire_above_S);
}

