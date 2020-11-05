#pragma once
#ifndef Block_H
#define Block_H
#include <SFML/Graphics.hpp>
#include<time.h>
class Block
{
private:
	sf::Window window;
public:
	Block();
	~Block();
	void showBlock(sf::RenderWindow *window);
	void updateBlock(sf::Texture* one, sf::Texture* two);
	void setPosition(int x, int y);
protected:
	int type;
	sf::Sprite terrain;
};
#endif

