#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include<string>
#include<sstream>
#define MAX_BUTTON 3
class Mainmenu
{
private:
	int selectedITEMindex;
	sf::Sprite menu_s;
	sf::Texture menuTex;
	sf::Sprite highscore_s;
	sf::Texture highscoreTex;
	

	sf::RectangleShape button[MAX_BUTTON];
	sf::RectangleShape button_high;
	sf::Font font;
	sf::Text NameText;
	
public:
	Mainmenu(float width, float height);
	virtual ~Mainmenu();
	sf::Text scoreText;
	int playMenu = 1;
	void update_Menu();
	void Nameupdate();
	void buttoncheck(const int button);
	const sf::FloatRect getBounds_0() const;
	const sf::FloatRect getBounds_1() const;
	const sf::FloatRect getBounds_2() const;
	const sf::FloatRect getBounds_3() const;
	void render_Menu(sf::RenderWindow& window);
};
