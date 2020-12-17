#include "fireBeam.h"

void fireBeam::initTexture()
{
	this->firebeamTex.loadFromFile("Pic/firebeam.png");
}

void fireBeam::initSprite()
{

	this->hitbox1.setFillColor(sf::Color::Green);
	this->hitbox1.setSize(sf::Vector2f(50.f, 100.f));

	this->firebeam_s1.setTexture(this->firebeamTex);
	this->currentFrame = sf::IntRect(0, 0, 63, 300);
	this->firebeam_s1.setTextureRect(this->currentFrame);
	this->firebeam_s1.setScale(2.f, 2.f);


	this->hitbox1.setFillColor(sf::Color::Red);
	this->hitbox2.setSize(sf::Vector2f(50.f, 100.f));

	this->firebeam_s2.setTexture(this->firebeamTex);
	this->firebeam_s2.setTextureRect(this->currentFrame);
	this->firebeam_s2.setScale(2.f, 2.f);
}

fireBeam::fireBeam(float pos_x, float pos_y)
{
	this->initTexture();
	this->initSprite();
	this->firebeam_s1.setPosition(pos_x, pos_y);
	this->firebeam_s2.setPosition(pos_x, pos_y);
	this->x1 = pos_x;
	this->x2 = pos_x-600.f;
	if (first == true)
	{
		skill = rand()%2;
		first = false;
		//printf("first");
	}
}

fireBeam::~fireBeam()
{
}

void fireBeam::setPosition(const float x, const float y)
{
	this->firebeam_s1.setPosition(x, y);
	this->firebeam_s2.setPosition(x, y);
}

const sf::Vector2f fireBeam::getPosition1() const
{
	return this->firebeam_s1.getPosition();

}

const sf::FloatRect fireBeam::getGlobalBounds1() const
{
	return this->hitbox1.getGlobalBounds();

}

const sf::Vector2f fireBeam::getPosition2() const
{

	return this->firebeam_s2.getPosition();
}

const sf::FloatRect fireBeam::getGlobalBounds2() const
{

	return this->hitbox2.getGlobalBounds();
}

void fireBeam::updateAnimations_firebeam()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.3f)
	{
		this->currentFrame.top = 0.f;
		this->firebeam_s1.setTextureRect(this->currentFrame);
		this->firebeam_s2.setTextureRect(this->currentFrame);
		this->currentFrame.left += 61.f;
		if (this->currentFrame.left > 305.f)
			this->currentFrame.left = 244;
		

		this->animationTimer.restart();
	}
}

void fireBeam::updateMovement_firebeam()
{
	//printf("(%d)", skill);
	if (this->skill == 0)
	{
		this->x1 -= 1.5f;
		this->firebeam_s1.setPosition(x1, this->firebeam_s1.getPosition().y);

	}
	if (this->skill == 1)
	{
		this->x1 -= 1.1f;
		this->x2 += 0.7f;
		this->firebeam_s1.setPosition(x1, this->firebeam_s1.getPosition().y);
		this->firebeam_s2.setPosition(x2, this->firebeam_s2.getPosition().y);

	}
	this->hitbox1.setPosition(this->firebeam_s1.getPosition().x + 60.f, this->firebeam_s1.getPosition().y+400.f);
	this->hitbox2.setPosition(this->firebeam_s2.getPosition().x + 50.f, this->firebeam_s2.getPosition().y+400.f);
	
}

void fireBeam::update_firebeam()
{
	this->updateMovement_firebeam();
	this->updateAnimations_firebeam();
}

void fireBeam::render(sf::RenderTarget& target)
{

	
	if (this->skill==0 && this->firebeam_s1.getPosition().x >=120.f)
	{

		target.draw(this->firebeam_s1);
		target.draw(this->hitbox1);
	}


	if (this->skill == 1 && this->firebeam_s1.getPosition().x >= 350.f)
	{

		target.draw(this->firebeam_s1);
		target.draw(this->firebeam_s2);
		target.draw(this->hitbox1);
		target.draw(this->hitbox2);
	}


}
