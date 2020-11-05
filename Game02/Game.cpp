#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(650, 900), "Tower Escape", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("Pic/Background_2.png"))
	{
		printf("BG ERROR");
	}
	this->worldBackground.setTexture(this->worldBackgroundTex);
}

void Game::initPlayer()
{
	this->player = new Player();
	this->fire = new firer();
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

int Game::Block()
{
	this->type = rand() % 3;
	return type;
}


void Game::showBlock()
{
	int i = 0, j = 0, x = 90, y = 500, k=0;
	if (this->ran == false)
	{
		for (i = 0; i < 5; i++)
		{
			for (j = 0; j < 5; j++, k++)
			{
				Block();
				/*this->terrain[k].setPosition(x, y);*/
				if (this->type > 1)
				{

					this->terrain[k].setTexture(two);
				}
				else
				{
					this->terrain[k].setTexture(one);
				}
				//this->window->draw(this->terrain[k]);
				//x += 120;
			}
			//x = 70;
			//y += 100;
			k++;
		}
		this->ran = true;
	}
	else
	{
		for (k = 0; k < 29; k++)
		{
			this->terrain[k].setScale(0.8f, 0.8f);
			this->terrain[k].setPosition(x, y);
			this->window->draw(this->terrain[k]);
			x += 90;
			if (x > 600)
			{
				x = 90;
				y += 90;
			}
		}

	}


	
	
}

void Game::updateBlock()
{
	this->one.loadFromFile("Pic/block1.png");
	this->two.loadFromFile("Pic/block2.png");
	this->blockOne.setTexture(this->one);
	this->blockTwo.setTexture(this->two);
	this->blockOne.setScale(0.8f, 0.8f);
	this->blockTwo.setScale(0.8f, 0.8f);

	/*if (this->type > 1)
	{
		this->terrain[].setTexture(this->one);
	}
	else
	{
		this->terrain[].setTexture(this->two);
	}*/
}

//void Game::setPositionBlock(int x, int y)
//{
//	this->terrain[].setPosition(x, y);
//}

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
	if (this->player->getGlobalBounds().top <= 500.f)
	{
		this->player->setPosition(this->player->getPosition().x, 400.f);
	}
	if (this->player->getGlobalBounds().left <= 70.f)
	{
		this->player->setPosition(140.f, this->player->getGlobalBounds().top);
	}
	else if (this->player->getGlobalBounds().left >= 480.f)
	{
		this->player->setPosition(480.f, this->player->getGlobalBounds().top);
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
		if (this->ev.type == sf::Event::Closed)
			this->window->close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
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
	this->updateBlock();

	this->updatePlayer();

	this->updateCollision();

	this->updateWorld();
}

void Game::renderPlayer()
{
	this->fire->render(*this->window);
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
	this->showBlock();
	this->renderPlayer();
	this->window->display();
}

const sf::RenderWindow& Game::getWindow() const
{
	return *this->window;
}
