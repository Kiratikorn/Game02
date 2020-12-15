#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#define MAX_NUMBER_OF_ITEMS 4
class Mainmenu
{
private:
	sf::Sprite menu_s;
	sf::Texture menuTex;
	bool playstate = false;
public:
	Mainmenu(float width, float height);
	virtual ~Mainmenu();
};
