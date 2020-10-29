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
	bool animationSwitch;

	//physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;

	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimation();
	void initPhysics();

public:
	Player();
	virtual ~Player();
	//Accessors
	const bool& getAnimSwitch();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;

	void setPosition(const float x, const float y);
	void resetVelocityY();

	//Func
	void resetAnimationTimer();
	void move(const float dir_x, const float dir_y);
	void updatePhysics();
	void updateMovement();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);
};

