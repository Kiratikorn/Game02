#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
enum Boss_ANIMATION_STATES { IDLE_boss, ATTACK1_boss, ATTACK2_boss,SLEEP_boss,WAKE1_boss, WAKE2_boss, WAKE3_boss,DIE_boss,FLY_boss,BREAK_boss};
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

	bool idle_anim = false;
	bool sleep_anim = true;
	bool opening1 = false;
	bool opening2 = false;
	bool opening3 = false;
	bool fly_animation = false;

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
