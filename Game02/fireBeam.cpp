#include "fireBeam.h"

void fireBeam::initTexture()
{
	this->firebeamTex.loadFromFile("Pic/firebeam.png");
}

void fireBeam::initSprite()
{
	this->firebeam_s1.setTexture(this->firebeamTex);
	this->currentFrame = sf::IntRect(0, 0, 63, 300);
	this->firebeam_s1.setTextureRect(this->currentFrame);
	this->firebeam_s1.setScale(2.f, 2.f);

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
	this->x2 = pos_x-420.f;
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
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.4f)
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

	if (this->skill == 0)
	{
		this->x1 -= 2.f;
		this->firebeam_s1.setPosition(x1, this->firebeam_s1.getPosition().y);

	}
	if (this->skill == 1)
	{
		this->x1 -= 0.1f;
		this->x2 += 0.1f;
		this->firebeam_s1.setPosition(x1, this->firebeam_s1.getPosition().y);
		this->firebeam_s2.setPosition(x2, this->firebeam_s1.getPosition().y);

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


	if (this->skill == 1 && this->firebeam_s1.getPosition().x >= 300.f)
	{
		target.draw(this->firebeam_s1);
		target.draw(this->firebeam_s2);
	}


}
