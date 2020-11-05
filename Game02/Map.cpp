#include "Map.h"

Map::Map()
{
	int i = 0, j = 0, k = 0, x = 0, y = 0;


	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 6; j++)
		{
			this->block[k].updateBlock(&this->one, &this->two);
			this->block[k].setPosition(x, y);
			x += 120;
			k++;
		}
		x = 0;
		y += 100;
		k++;
	}
}

Map::~Map()
{
}

void Map::showMap(sf::RenderWindow* window)
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			this->block[k].showBlock(window);
			k++;
		}
		k++;
	}
}
