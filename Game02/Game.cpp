#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(600,900),"Tower Escape", sf::Style::Close | sf::Style::Titlebar );
	this->window->setFramerateLimit(60);
}

void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("Pic/Bg_1.png"))
	{
		printf("BG ERROR");
	}
	this->worldBackground.setTexture(this->worldBackgroundTex);
}

void Game::initPlayer()
{
	this->player = new Player();
}

Game::Game()
{
	this->initWindow();
	this->initWorld();
	this->initPlayer();
}

Game::~Game()
{
	delete this->player;
}

void Game::updateCollision()
{
	//collision buttom
	if (this->player->getPosition().y + this->player->getGlobalBounds().height > this->window->getSize().y)
	{
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			this->window->getSize().y - this->player->getGlobalBounds().height
			);
	}
	if (this->player->getGlobalBounds().left <= 20.f)
	{
		this->player->setPosition(30.f, this->player->getGlobalBounds().top);
	}
	else if (this->player->getGlobalBounds().left >= 580.f)
	{
		this->player->setPosition(570.f, this->player->getGlobalBounds().top);
	}
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::updateWorld()
{
}

//void Game::run()
//{
//	while (this->window->isOpen());
//	{
//		this->update();
//		this->render();
//	}
//}

void Game::update()
{
	while (this->window->pollEvent(this->ev))
	{
		if(this->ev.type == sf::Event::Closed)
			this->window->close();
		else if(this->ev.type ==sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window->close();

		if (this->ev.type == sf::Event::KeyReleased &&
			(this->ev.key.code == sf::Keyboard::A ||
				this->ev.key.code == sf::Keyboard::D ||
				this->ev.key.code == sf::Keyboard::W ||
				this->ev.key.code == sf::Keyboard::S
				)
			)
		{
			this->player->resetAnimationTimer();
		}
	}
	this->updatePlayer();

	this->updateCollision();

	this->updateWorld();
}

void Game::renderPlayer()
{
	this->player->render(*this->window);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBackground);
}

void Game::render()
{
	this->window->clear();

	//draw world
	this->renderWorld();

	this->window->clear();
	this->renderPlayer();
	this->window->display();
}

const sf::RenderWindow & Game::getWindow() const
{
	return *this->window;
}
