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
	short animState;
	void initTexture();
	void initSprite();
	bool animationSwitch;
	void initVariables();
	void initAnimation();
public:
	Fire_above();
	virtual ~Fire_above();
	void updateMovement_FA();
	const bool& getAnimSwitch_FA();
	void updateAnimation_FA();
	void resetAnimationTimer_FA();
	void update_FA();
	void render(sf::RenderTarget& target);
};