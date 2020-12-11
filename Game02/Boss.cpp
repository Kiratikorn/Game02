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
	this->currentFrame = sf::IntRect(0, 0, 175, 170);//x,y,w,h
	this->boss.setTextureRect(this->currentFrame);
	this->boss.setPosition(300.f, 100.f);
	this->boss.setScale(2.0f, 2.0f);
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
	if (idle_anim == true)
	{
		this->animState = Boss_ANIMATION_STATES::IDLE_boss;
	}
	/*this->animState = Boss_ANIMATION_STATES::SLEEP_boss;*/
	if (this->sleep_anim == true)
	{
		this->animState = Boss_ANIMATION_STATES::SLEEP_boss;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		this->sleep_anim = false;
		this->opening1 = true;
	}
	//Animation opening
	if (this->opening1 == true)
	{
		this->animState = Boss_ANIMATION_STATES::WAKE1_boss;
	}
	if (this->opening2 == true)
	{
		this->animState = Boss_ANIMATION_STATES::WAKE2_boss;
	}
	if (this->opening3 == true)
	{
		this->animState = Boss_ANIMATION_STATES::WAKE3_boss;
	}
	if (this->fly_animation == true)
	{
		this->animState = Boss_ANIMATION_STATES::FLY_boss;
		boss.move(-2.f, 0.f);
		if (boss.getPosition().x == -300.f)
		{
			boss.move(2.f, 0.f);
			this->fly_animation = false;
			//this->idle_anim = true;
			//printf("stop");
		}
	}

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
	else if (this->animState == Boss_ANIMATION_STATES::SLEEP_boss)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 1.0f || this->getAnimSwitch_boss())
		{
			this->currentFrame.top = 960.f;
			this->currentFrame.left += 230.f;
			if (this->currentFrame.left > 230.f)
				this->currentFrame.left = 0.f;
			this->animationTimer.restart();
			this->boss.setTextureRect(this->currentFrame);
		}
		//this->boss.setScale(1.0f, 1.0f);
		//this->boss.setOrigin(this->boss.getGlobalBounds().width / 3.f, 0.f);
	}
	else if (this->animState == Boss_ANIMATION_STATES::WAKE1_boss)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >=0.5f || this->getAnimSwitch_boss())
		{
			//this->boss.setScale(-1.0f, 1.0f);
			//this->boss.setOrigin(this->boss.getGlobalBounds().width / 3.f, 0.f);
			this->currentFrame.top =1400.f;
			this->boss.setTextureRect(this->currentFrame);
			this->currentFrame.left += 230.f;
			this->animationTimer.restart();

			if (this->currentFrame.left >= 920.f)
			{
				this->currentFrame.left = 0.f;
				this->opening2 = true;
				this->opening1 = false;

			}


		}

	}
	else if (this->animState == Boss_ANIMATION_STATES::WAKE2_boss)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >=0.5f || this->getAnimSwitch_boss())
		{
			//this->boss.setScale(1.0f, 1.0f);
			//this->boss.setOrigin(this->boss.getGlobalBounds().width / 3.f, 0.f);
			this->currentFrame.top = 160.f;
			this->boss.setTextureRect(this->currentFrame);
			this->currentFrame.left += 230.f;
			this->animationTimer.restart();

			if (this->currentFrame.left >= 1380.f)
			{
				this->currentFrame.left = 0.f;
				this->opening3 = true;
				this->opening2 = false;

			}

		}

	}
	else if (this->animState == Boss_ANIMATION_STATES::WAKE3_boss)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f || this->getAnimSwitch_boss())
		{
			this->currentFrame.top = 340.f;
			this->boss.setTextureRect(this->currentFrame);
			this->currentFrame.left += 230.f;
			this->animationTimer.restart();
	
			if (this->currentFrame.left >= 460.f)
			{
				this->currentFrame.left = 0.f;
				this->fly_animation = true;
				this->opening3 = false;
			}

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
	//target.draw(this->boss);
}
