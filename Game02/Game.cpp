#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(600,900),"Tower Escape", sf::Style::Close | sf::Style::Titlebar );
}

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::run()
{
	while (this->window->isOpen());
	{
		this->update();
		this->render();
	}
}

void Game::update()
{
	while (this->window->pollEvent(this->ev))
	{
		if(this->ev.type == sf::Event::Closed)
			this->window->close();
		else if(this->ev.type ==sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	this->window->display();
}

const sf::RenderWindow & Game::getWindow() const
{
	return *this->window;
}
