#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
enum Boss_ANIMATION_STATES { IDLE_boss, ATTACK1_boss, ATTACK2_boss,SLEEP_boss,WAKE1_boss, WAKE2_boss, WAKE3_boss,DIE_boss,FLY_boss,BREAK_boss};
class Boss
{
private:
	sf::Sprite boss;
	sf::RectangleShape hit_boxBoss;
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
	int animation_boss=0;
	bool bossFight = false;

	//Accessors
	const bool& getAnimSwitch_boss();
	void setPosition(const float x, const float y);
	const sf::Vector2f getPosition_boss() const;
	const sf::FloatRect getGlobalBounds_boss() const;
	const sf::FloatRect getGlobalBounds_hit_box_boss() const;

	//Func
	void resetAnimationTimer_boss();
	void updateMovement_boss();
	void updateAnimations_boss();
	void update_boss();
	void render_boss(sf::RenderTarget& target);
};
