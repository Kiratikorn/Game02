#pragma once
#include <SFML\Graphics.hpp>
enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, DIG };
class Player
{
private:
	sf :: Sprite sprite;
	sf :: Texture textureSheet;
	//bool moving;
	sf::Clock animationTimer;

	//animation
	short animState;
	sf::IntRect currentFrame;

	//physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;

	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimation();
	void initPhysics();

public:
	Player();
	virtual ~Player();

	//Func
	void move(const float dir_x, const float dir_y);
	void updatePhysics();
	void updateMovement();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);
};

