#include "fireBeam.h"

void fireBeam::initTexture()
{
	this->firebeamTex.loadFromFile("Pic/firebeam.png");
}

void fireBeam::initSprite()
{
	this->firebeam_s1.setTexture(this->firebeamTex);
	this->currentFrame = sf::IntRect(0, 0, 65, 300);
	this->firebeam_s1.setTextureRect(this->currentFrame);
	this->firebeam_s1.setScale(1.f, 1.f);

	this->firebeam_s2.setTexture(this->firebeamTex);
	this->firebeam_s2.setTextureRect(this->currentFrame);
	this->firebeam_s2.setScale(1.f, 1.f);
}

fireBeam::fireBeam()
{
	this->initTexture();
	this->initSprite();

}

fireBeam::~fireBeam()
{
}

void fireBeam::setPosition(const float x, const float y)
{
	this->firebeam_s1.setPosition(x, y);
	this->firebeam_s2.setPosition(x-350.f, y);
}

const sf::Vector2f fireBeam::getPosition1() const
{
	return this->firebeam_s1.getPosition();

}

const sf::FloatRect fireBeam::getGlobalBounds1() const
{
	return this->firebeam_s1.getGlobalBounds();

}

const sf::Vector2f fireBeam::getPosition2() const
{

	return this->firebeam_s2.getPosition();
}

const sf::FloatRect fireBeam::getGlobalBounds2() const
{

	return this->firebeam_s2.getGlobalBounds();
}

void fireBeam::updateAnimations_firebeam()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
	{
		this->currentFrame.top = 0.f;
		this->currentFrame.left += 63.f;
		if (this->currentFrame.left > 300.f)
			this->currentFrame.left = 240;
		this->animationTimer.restart();
		this->firebeam_s1.setTextureRect(this->currentFrame);
		this->firebeam_s2.setTextureRect(this->currentFrame);
	}
}

void fireBeam::updateMovement_firebeam()
{

	if (this->skill == 0)
	{
		this->firebeam_s1.move(-1.f, 0.f);

	}
	if (this->skill == 1)
	{
		this->firebeam_s1.move(-1.f, 0.f);
		this->firebeam_s2.move(1.f, 0.f);

	}
	
}

void fireBeam::update_firebeam()
{
	this->updateMovement_firebeam();
	this->updateAnimations_firebeam();
}

void fireBeam::render(sf::RenderTarget& target)
{
	if (this->skill==0 && this->firebeam_s1.getPosition().x >=100.f)
	{
		target.draw(this->firebeam_s1);
	}
	else
	{
		this->currentFrame.left = 0.f;
	}

	if (this->skill == 0 && this->firebeam_s1.getPosition().x >= 300.f)
	{
		target.draw(this->firebeam_s1);
		target.draw(this->firebeam_s2);
	}
	else
	{
		this->currentFrame.left = 0.f;
	}

}
