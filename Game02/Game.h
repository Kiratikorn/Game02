#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event ev;

	void initWindow();

public:
	Game();
	virtual ~Game();

	void run();
	void update();
	void render();
	const sf::RenderWindow & getWindow() const;
};

