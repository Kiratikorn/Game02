#include "Boss.h"

void Boss::initVariables()
{
	this->animState = Boss_ANIMATION_STATES::IDLE_boss;
}

void Boss::initTexture()
{
	this->bossTex.loadFromFile("Pic/dragon_spriite.png");
}

void Boss::initSprite()
{
	this->boss.setTexture(this->bossTex);
	this->currentFrame = sf::IntRect(0, 0, 175, 120);//x,y,w,h
	this->boss.setTextureRect(this->currentFrame);
	this->boss.setPosition(400.f, 300.f);
	this->boss.setScale(2.5f, 2.5f);
}

void Boss::initAnimation()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

Boss::Boss()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Boss::~Boss()
{
}

const bool& Boss::getAnimSwitch_boss()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

const sf::Vector2f Boss::getPosition_boss() const
{
	return this->boss.getPosition();
}

const sf::FloatRect Boss::getGlobalBounds_boss() const
{
	return this->boss.getGlobalBounds();
}

void Boss::resetAnimationTimer_boss()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}


void Boss::updateMovement_boss()
{
	this->animState = Boss_ANIMATION_STATES::IDLE_boss;
}

void Boss::updateAnimations_boss()
{
	if (this->animState == Boss_ANIMATION_STATES::IDLE_boss)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch_boss())
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 230.f;
			if (this->currentFrame.left > 1610.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->boss.setTextureRect(this->currentFrame);
		}
	}
}

void Boss::update_boss()
{
	this->updateAnimations_boss();
}

void Boss::render_boss(sf::RenderTarget& target)
{
	target.draw(this->boss);
}
