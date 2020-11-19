#pragma once
#include <SFML/Graphics.hpp>
#include"Player.h"
enum orc_ANIMATION_STATES { IDLE_orc = 0, MOVING_LEFT_orc, MOVING_RIGHT_orc};
class Orc
{
private:
	Player* player;
	//Game* game;
	sf::Sprite orc;
	sf::Texture OrcTex;
	sf::Clock animationTimer;

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
public:
	bool check_view=false;
	int check_move = 0;
	Orc(float pos_x,float pos_y);
	virtual ~Orc();
	//void spawn_orc();
	sf::RectangleShape hitbox_orc;
	sf::RectangleShape viewbox_orc;
	//sf::CircleShape circ;
	void hitbox_O();
	//float bottom_hit;
	//float left_hit;
	//float top_hit;
	//float right_hit;

	float gravity_orc;

	//Accessors
	const bool& getAnimSwitch_orc();
	const sf::Vector2f getPosition() const;
	const sf::FloatRect getGlobalBounds_orc() const;
	const sf::FloatRect getGlobalBounds_hit_orc() const;

	//void setPosition(const sf::Vector2f pos);
	//void setPosition(const float x, const float y);
	void resetVelocityY_orc();
	//void collide(float xvel,float yvel,Platform level[5]);

	//Func
	void resetAnimationTimer_orc();
	void move_orc(const float dir_x, const float dir_y);
	void updatePhysics_orc();
	void updateMovement_orc();
	void updateAnimations_orc();
	void update_orc();
	void render_orc(sf::RenderTarget& target);
};
