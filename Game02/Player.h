#pragma once
#include <SFML\Graphics.hpp>
#include "Entity.h"
#include "Platform.h"

enum PLAYER_ANIMATION_STATES { IDLE = 0, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, DIG, ATTACK};
class Player : public Entity
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

	float velocityMaxY;

	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimation();
	void initPhysics();

public :
	Player();
	virtual ~Player();
	//hitbox_player
	sf::RectangleShape hitbox_player;
	sf::CircleShape circ;
	void hitbox_P();
	float bottom_hit;
	float left_hit;
	float top_hit;
	float right_hit;

	float gravity_player;

	//Accessors
	const bool& getAnimSwitch();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds() const;
	const sf::FloatRect getGlobalBounds_hit() const;
	//sf::Transformable move;

	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void resetVelocityY();
	//void collide(float xvel,float yvel,Platform level[5]);

	//Func
	void resetAnimationTimer();
	void move_x(const float dir_x, const float dir_y);
	void updatePhysics();
	void updateMovement();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);
};

