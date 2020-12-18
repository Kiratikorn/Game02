#include "Boss.h"

void Boss::initVariables()
{
	//this->animState = Boss_ANIMATION_STATES::SLEEP_boss;
}

void Boss::initTexture()
{
	this->bossTex.loadFromFile("Pic/Dragon_sprite.png");
}

void Boss::initSprite()
{
	this->boss.setTexture(this->bossTex);
	this->currentFrame = sf::IntRect(0, 0, 200, 150);//x,y,w,h
	this->boss.setTextureRect(this->currentFrame);
	this->boss.setPosition(300.f, 100.f);
	this->boss.setScale(2.0f, 2.0f);
	this->hit_boxBoss.setSize(sf::Vector2f(100.f, 130.f));
	
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

void Boss::setPosition(const float x, const float y)
{
	this->boss.setPosition(x, y);
}

const sf::Vector2f Boss::getPosition_boss() const
{
	return this->boss.getPosition();
}

const sf::FloatRect Boss::getGlobalBounds_boss() const
{
	return this->boss.getGlobalBounds();
}

const sf::FloatRect Boss::getGlobalBounds_hit_box_boss() const
{
	return this->hit_boxBoss.getGlobalBounds();
}

void Boss::resetAnimationTimer_boss()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}


void Boss::updateMovement_boss()
{
	this->hit_boxBoss.setPosition(this->boss.getPosition().x + 130.f, this->boss.getPosition().y + 100.f);

	
	//Animation opening


			//this->idle_anim = true;
			//printf("stop");
	

}

void Boss::updateAnimations_boss()
{

	if (this->animState == Boss_ANIMATION_STATES::IDLE_boss || this->animation_boss ==0)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f || this->getAnimSwitch_boss())
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 200.f;
			if (this->currentFrame.left > 1400.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->boss.setTextureRect(this->currentFrame);
		}
	}

	
	else if (this->animState == Boss_ANIMATION_STATES::FLY_boss)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f || this->getAnimSwitch_boss())
		{
			this->currentFrame.top = 455.f;
			this->boss.setTextureRect(this->currentFrame);
			this->currentFrame.left += 230.f;
			this->animationTimer.restart();

			if (this->currentFrame.left >= 690.f)
			{
				this->currentFrame.left = 0.f;
			}

		}
	}
}


void Boss::update_boss()
{

	this->updateMovement_boss();
	this->updateAnimations_boss();
	
}

void Boss::render_boss(sf::RenderTarget& target)
{

	if (bossFight == true)
	{
		printf("boss");
		//target.draw(this->hit_boxBoss);
		target.draw(this->boss);
	}
}
