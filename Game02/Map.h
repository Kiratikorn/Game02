#pragma once
#ifndef MAP_H
#define MAP_H
#include <SFML/Graphics.hpp>
#include "Block.h"
class Map
{
public:
	Map();
	~Map();
	void showMap(sf::RenderWindow *window);
protected:
	sf::Texture one;
	sf::Texture two;
	Block block[200];
};
#endif

