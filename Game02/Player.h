#pragma once
#include <SFML\Graphics.hpp>
class Player
{
private:
	sf :: Sprite sprite;
	sf :: Texture textureSheet;
	bool moving;

	//animation
	sf::IntRect currentFrame;
	//movement

	void initVariable();
	void initTexture();
	void initSprite();
	void initAnimation();

public:
	Player();
	virtual ~Player();

	//Func
	void updateMovement();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);
};

