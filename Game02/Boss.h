#pragma once
#include <SFML/Graphics.hpp>
enum Boss_ANIMATION_STATES { IDLE_boss = 0, ATTACK_boss };
class Boss
{
private:
	sf::Sprite boss;
	sf::Texture bossTex;
	sf::Clock animationTimer;

	short animState;
	sf::IntRect currentFrame;
	bool animationSwitch;

	//physics
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimation();

public:
	Boss();
	virtual ~Boss();
	//Accessors
	const bool& getAnimSwitch_boss();
	const sf::Vector2f getPosition_boss() const;
	const sf::FloatRect getGlobalBounds_boss() const;

	//Func
	void resetAnimationTimer_boss();
	void updateMovement_boss();
	void updateAnimations_boss();
	void update_boss();
	void render_boss(sf::RenderTarget& target);
};
