#pragma once
#include <SFML\Graphics.hpp>
class fireBeam
{
	float x1;
	float x2;
	bool first = true;
	sf::Sprite firebeam_s1;
	sf::Sprite firebeam_s2;
	sf::Texture firebeamTex;
	sf::IntRect currentFrame;
	sf::Clock animationTimer;
	sf::RectangleShape hitbox1;
	sf::RectangleShape hitbox2;
	void initTexture();
	void initSprite();
public:
	int skill=2;

	fireBeam(float pos_x, float pos_y);
	virtual ~fireBeam();
	void setPosition(const float x, const float y);
	const sf::Vector2f getPosition1() const;
	const sf::FloatRect getGlobalBounds1() const;
	const sf::Vector2f getPosition2() const;
	const sf::FloatRect getGlobalBounds2() const;

	void updateAnimations_firebeam();
	void updateMovement_firebeam();
	void update_firebeam();
	void render(sf::RenderTarget& target);
};





