#pragma once
#include <SFML\Graphics.hpp>
enum FA_ANIMATION_STATES { IDLE_FA= 0};
class Fire_above
{
private:

	sf::Sprite fire_above_S;
	sf::Texture fire_aboveTex;
	sf::IntRect currentFrame;
	sf::Clock animationTimer;
	sf::Clock timeSpeed;
	int speed;
	short animState;
	void initTexture();
	void initSprite();
	bool animationSwitch;
	bool startfire = false;
	void initVariables();
	void initAnimation();
public:
	Fire_above();
	virtual ~Fire_above();
	int speedIncrease=1;
	void setPosition(const float x, const float y);
	void updateMovement_FA();
	const bool& getAnimSwitch_FA();
	void updateAnimation_FA();
	void resetAnimationTimer_FA();
	void update_FA();
	void render(sf::RenderTarget& target);
};