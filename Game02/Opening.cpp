#include "Opening.h"

void Opening::initTexture()
{
	this->bossTex.loadFromFile("Pic/Opening.png");
}

void Opening::initSprite()
{
	
	this->boss.setTexture(this->bossTex);
	this->currentFrame = sf::IntRect(0, 150, 200, 150);
	this->boss.setTextureRect(this->currentFrame);
	this->boss.setPosition(100.f, 50.f);
	this->boss.setScale(2.0f, 2.0f);
}

void Opening::initAnimation()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

Opening::Opening()
{
	this->initTexture();
	this->initSprite();
}

Opening::~Opening()
{
}

const bool& Opening::getAnimSwitch_op()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;
}

void Opening::animation()
{
	if (this->animState == OP_ANIMATION_STATES::Fly_op)
	{
		boss.move(-2.f, 0.f);
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch_op())
		{
			this->currentFrame.top = 800.f;
			this->currentFrame.left += 200.f;
			if (this->currentFrame.left > 400.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->boss.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == OP_ANIMATION_STATES::Sleep_op || start_op == false)
	{
		printf("op");
		if (this->animationTimer.getElapsedTime().asSeconds() >= 1.f || this->getAnimSwitch_op())
		{
			this->currentFrame.top = 150.f;
			this->currentFrame.left += 200.f;
			if (this->currentFrame.left > 200.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->boss.setTextureRect(this->currentFrame);
		}
	}
	else if (this->animState == OP_ANIMATION_STATES::Play_op || start_op == true)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f || this->getAnimSwitch_op())
		{
			if (first)
			{
				this->currentFrame.top = 300.f;
				first = false;
			}

			this->currentFrame.left += 200.f;
			if (this->currentFrame.left >= 400.f && this->currentFrame.top >= 600.f)
			{
				this->animState = OP_ANIMATION_STATES::Fly_op;
	
			}
			else if (this->currentFrame.left > 800.f)
			{
				this->currentFrame.left = 0.f;
				this->currentFrame.top += 150.f;
			}

			this->animationTimer.restart();
			this->boss.setTextureRect(this->currentFrame);
		}
	}

}

void Opening::update()
{
	if (this->boss.getPosition().x > -400.f)
		this->animation();
}

void Opening::render(sf::RenderTarget& target)
{
	if(this->boss.getPosition().x > -400.f)
		target.draw(this->boss);
}
