#pragma once
#include <SFML/Graphics.hpp>
enum OP_ANIMATION_STATES {Sleep_op,Play_op,Fly_op };
class Opening
{
private:
	sf::Sprite boss;
	sf::Texture bossTex;
	sf::Clock animationTimer;
	bool first = true;
	short animState;
	sf::IntRect currentFrame;
	bool animationSwitch;
	void initTexture();
	void initSprite();
	void initAnimation();

public:
	Opening();
	virtual ~Opening();
	bool start_op = false;
	const bool& getAnimSwitch_op();
	void animation();
	void update();
	void render(sf::RenderTarget& target);
};

