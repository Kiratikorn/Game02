
#include"Orc.h"
Orc::Orc(float pos_x, float pos_y)
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->orc.setPosition(pos_x, pos_y);

	//this->initPhysics();
}

Orc::~Orc()
{
}

void Orc::setPosition(const float x, const float y)
{
	this->orc.setPosition(x, y);
}

//void Orc::spawn_Orc()
//{
//
//}



void Orc::initVariables()
{
	this->animState = orc_ANIMATION_STATES::IDLE_orc;
}

void Orc::initTexture()
{
	this->OrcTex.loadFromFile("Pic/Orc_sprite.png");

}

void Orc::initSprite()
{
	this->orc.setTexture(this->OrcTex);
	this->currentFrame = sf::IntRect(0, 0, 58, 57);//x,y,w,h
	this->orc.setTextureRect(this->currentFrame);
	//this->orc.setPosition(300.f, 600.f);
	this->orc.setScale(1.0f, 1.0f);

}

void Orc::initAnimation()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Orc::initPhysics()
{
	this->velocityMax = 6.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.f;
	//this->drag = 0.94f;
	this->gravity_orc = 1.f;
	this->velocityMaxY = 15.f;
}

void Orc::gravity()
{
	if (this->check_gravity == true)
	{
		this->orcMoveY = 2.f;
	}
	else
	{
		this->orcMoveY = 0.f;
	}

}

//void Orc::initPlayer()
//{
//	this->game = new Game();
//}


void Orc::hitbox_O()
{
	viewbox_orc.setFillColor(sf::Color::Green);
	viewbox_orc.setPosition(0.f,orc.getPosition().y);
	viewbox_orc.setSize(sf::Vector2f(650, 60));
	hitbox_orc.setOutlineColor(sf::Color::Red);
	hitbox_orc.setOutlineThickness(2.0f);
	hitbox_orc.setSize(sf::Vector2f(40.f, 50.f));
	hitbox_orc.setPosition(this->orc.getPosition().x + 13.f, this->orc.getPosition().y);

	this->blocknext_orc.setSize(sf::Vector2f(10.f, 20.f));
	this->blocknext_orc.setPosition(this->orc.getPosition().x-10.f, this->orc.getPosition().y+15.f) ;

	this->blockbelow_orc.setFillColor(sf::Color::Red);
	this->blockbelow_orc.setSize(sf::Vector2f(30.f, 20.f));
	this->blockbelow_orc.setPosition(this->orc.getPosition().x , this->orc.getPosition().y +50.f);

	//circ.setFillColor(sf::Color::Red);
	//circ.setRadius(2.f);
	//circ.setPosition(this->sprite.getPosition().x, this->sprite.getPosition().y + 80.f);

}

const bool& Orc::getAnimSwitch_orc()
{
	bool anim_switch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return anim_switch;

}

const sf::Vector2f Orc::getPosition() const
{
	return this->orc.getPosition();
}

const sf::FloatRect Orc::getGlobalBounds_orc() const
{
	return this->orc.getGlobalBounds();
}
const sf::FloatRect Orc::getGlobalBounds_hit_orc() const
{
	return this->viewbox_orc.getGlobalBounds();
}

const sf::FloatRect Orc::getGlobalBounds_next_orc() const
{
	return this->blocknext_orc.getGlobalBounds();
}

const sf::FloatRect Orc::getGlobalBounds_below_orc() const
{
	return this->blockbelow_orc.getGlobalBounds();
}

//void Player::setPosition(const sf::Vector2f pos)
//{
//	this->sprite.setPosition(pos);
//}

//void Player::setPosition(const float x, const float y)
//{
//	this->sprite.setPosition(x, y);
//	left_hit = x + 13.f;
//	right_hit = x + 40.f + 13.f;
//	top_hit = y + 25.f;
//	bottom_hit = y + 80.f;
//
//}

void Orc::resetVelocityY_orc()
{
	this->velocity.y = 2.f;
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


void Orc::resetAnimationTimer_orc()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Orc::move_orc(const float dir_x, const float dir_y)
{
	//acce
	this->velocity.x += dir_x * this->acceleration;

	//limit velo
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void Orc::updatePhysics_orc()
{
	//GRAVITY
	this->velocity.y += 1.0 * this->gravity_orc;
	if (std::abs(this->velocity.x) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}
	//deceleration
	//this->velocity *= this->drag;

	//limitdece
	if (std::abs(this->velocity.x) < this->velocityMin)
		this->velocity.x = 0.f;
	if (std::abs(this->velocity.y) < this->velocityMin)
		this->velocity.y = 0.f;

	this->orc.move(this->velocity);
}

void Orc::updateMovement_orc()
{
	this->animState= orc_ANIMATION_STATES::IDLE_orc;

	if (this->check_move == 3)
	{
		this->animState = orc_ANIMATION_STATES::ATTACK_orc;
	}
	else if (this->check_view==true && check_blocknext==true)
	{
		if (this->check_move == 1)
		{
			orc.move(-1.5f, orcMoveY);
			this->animState = orc_ANIMATION_STATES::MOVING_LEFT_orc;
		}
		else if (this->check_move == 2)
		{
			orc.move(1.5f, orcMoveY);
			this->animState = orc_ANIMATION_STATES::MOVING_RIGHT_orc;
		}
	}

	else
	{
		orc.move(0.f, orcMoveY);
	}

}


void Orc::updateAnimations_orc()
{

	if (this->animState == orc_ANIMATION_STATES::IDLE_orc)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f || this->getAnimSwitch_orc())
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 60.f;
			if (this->currentFrame.left > 180.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->orc.setTextureRect(this->currentFrame);
		}
	}

	else if (this->animState == orc_ANIMATION_STATES::MOVING_LEFT_orc)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.15f)
		{
			this->currentFrame.top = 90.f;
			this->currentFrame.left += 60.f;
			if (this->currentFrame.left >= 480.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->orc.setTextureRect(this->currentFrame);
		}
		this->orc.setScale(1.f, 1.f);
		this->orc.setOrigin(0.f, 0.f);
		this->blocknext_orc.setScale(1.f, 1.f);
		this->blocknext_orc.setOrigin(0.f, 0.f);

		this->blockbelow_orc.setScale(1.f, 1.f);
		this->blockbelow_orc.setOrigin(0.f, 0.f);
	}
	else if (this->animState == orc_ANIMATION_STATES::MOVING_RIGHT_orc)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.15f)
		{
			this->currentFrame.top = 90.f;
			this->currentFrame.left += 60.f;
			if (this->currentFrame.left >= 480.f)
				this->currentFrame.left = 0;
			this->animationTimer.restart();
			this->orc.setTextureRect(this->currentFrame);
		}
		this->orc.setScale(-1.f, 1.f);
		this->orc.setOrigin(this->orc.getGlobalBounds().width / 3.f, 0.f);
		this->blocknext_orc.setScale(-1.f, 1.f);
		this->blocknext_orc.setOrigin(this->blocknext_orc.getGlobalBounds().width / 3.f+30.f, 0.f);

		this->blockbelow_orc.setScale(-1.f, 1.f);
		this->blockbelow_orc.setOrigin(this->blockbelow_orc.getGlobalBounds().width / 3.f, 0.f);

	}
	else if (this->animState == orc_ANIMATION_STATES::ATTACK_orc)
	{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f)
		{
			this->currentFrame.top = 180.f;
			this->currentFrame.left += 60.f;
			if (this->currentFrame.left >= 120.f)
				this->currentFrame.left = 0;
				this->animationTimer.restart();
			this->orc.setTextureRect(this->currentFrame);
		}
	}
	//else if (this->animState == PLAYER_ANIMATION_STATES::ATTACK_orc)
	//{
	//	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
	//	{
	//		this->currentFrame.top = 500.f;
	//		this->currentFrame.left += 150.f;
	//		if (this->currentFrame.left >= 450.f)
	//			this->currentFrame.left = 0;
	//		this->animationTimer.restart();
	//		this->sprite.setTextureRect(this->currentFrame);
	//	}
	//}
	else
		this->animationTimer.restart();
}

void Orc::update_orc()
{
	if (remove_orc == false)
	{
		this->gravity();
		this->updateMovement_orc();
		this->updateAnimations_orc();
		this->updatePhysics_orc();
		this->hitbox_O();
	}
}

void Orc::render_orc(sf::RenderTarget& target)
{
	//target.draw(this->hitbox_player);
	//target.draw(this->viewbox_orc);
	//target.draw(this->blockbelow_orc);
	if (remove_orc == false)
	{
		//target.draw(this->blocknext_orc);
		target.draw(this->orc);
	}
	
	//target.draw(circ);
}