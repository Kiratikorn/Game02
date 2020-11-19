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
	//this->orc_enemy = new Orc(20.f,20.f);
	this->fire_above = new Fire_above();
	this->boss = new Boss();
}

void Game::initEnemy()
{
	this->spawnTimerMax=1000.f;
	this->spawnTimer = this->spawnTimerMax;
}

Game::Game()
{
	this->initWindow();
	this->initWorld();
	this->initPlayer();
	this->initEnemy();
}

Game::~Game()
{
	delete this->player;
	for (auto* i: this->orc_enemies)
	{
		delete i;
	}
	for (auto* i : this->coins)
	{
		delete i;
	}
}

int Game::Block()
{
	this->type = rand() % 4;
	return type;
}


void Game::showBlock()
{
	int x = 100, y = 500;

	if (this->ran == false)
	{
		for (column = 0; column < 50; column++)
		{

				for (row = 0; row <= 5; row++)
				{

					Block();
					if (this->type <= 1)
					{
						this->terrain[column][row].setTexture(one);
						this->have_terr[column][row] = 1;
					}
					else if (this->type == 2)
					{
						this->terrain[column][row].setTexture(two);
						this->have_terr[column][row] = 2;
					}
					else if (this->type == 3)
					{

						this->have_terr[column][row] = 0;
					}
					else
					{

					}

				}

		}
		this->ran = true;
	}

	//collide();

	if (this->ran == true)
	{
		for (column = 0; column < 50; column++)
		{
			if (this->player->getPosition().y + 400.f >= column * 120.f * 0.75 + 500.f )
			{
				for (row = 0; row <= 4; row++)
				{
					this->terrain[column][row].setScale(0.75f, 0.75f);
					this->terrain[column][row].setPosition(x, y);
					this->window->draw(this->terrain[column][row]);

					if (this->have_terr[column][row] != 0)
					{
						this->blockCheck.setOutlineColor(sf::Color::Cyan);
						this->blockCheck.setOutlineThickness(2.f);
						this->blockCheck.setFillColor(sf::Color::Transparent);
						this->blockCheck.setPosition(terrain[column][row].getPosition().x, terrain[column][row].getPosition().y);
						this->blockCheck.setSize(sf::Vector2f(120.f * 0.75f, 120.f * 0.75f));
						this->window->draw(this->blockCheck);
					}
					else if (have_terr[column][row] == 0)
					{
						this->coins.push_back(new Point(terrain[column][row].getPosition().x+20.f, terrain[column][row].getPosition().y+30.f));
					}

					x += 88;

					//collision
					//if (this->player->getGlobalBounds_hit().intersects(blockCheck.getGlobalBounds()))
					//{
					//	this->player->setPosition(this->player->getPosition().x, i*120*0.75+500.f-100.f*0.8);
					//	printf("hit~");
					//}


					//plat_left_hit = j * 120.f * 0.8f + 0.f + 90.f - (5.0f * j);
					//plat_right_hit = j * 120.f * 0.8f + (120.f * 0.8f) - (5.0f * j);
					//plat_top_hit = i * 120.f * 0.8f + 500.f - (5.0f * i);
					//plat_bottom_hit = i * 120.f * 0.8f + 500.f + (120.f * 0.8f) - (5.0f * i);
					//		if (this->player->left_hit < plat_right_hit)
					//		{
					//			this->player->setPosition(j * 120.f * 0.8f + 0.f + 90.f - (5.0f * j), (player->getPosition().y));
					//		}
					//		if (this->player->right_hit > plat_left_hit)
					//		{
					//			this->player->setPosition(j * 120.f * 0.8f + (120.f * 0.8f) - (5.0f * j), (player->getPosition().y));
					//		}
				}
				x = 100;
				y += 88;
			}
		}
	}
	if (column == 99)
	{
		column = 0;
	}
	test.setFillColor(sf::Color::Red);
	test.setRadius(2.f);
	test.setPosition(90.f + (120.f * 0.8f) - 5.f, 500.f + (120.f * 0.8f) - 5.0f*2);
	this->window->draw(this->test);

}

void Game::updateBlock()
{
	//int levelArray[5][5] = { { 0,0,0,0,0 },
	//						{ 0,0,0,0,0 },
	//						{ 1,1,1,1,1 },
	//						{ 1,1,1,1,1 },
	//						{ 1,1,1,1,1 }, };
	//Platform level[100];
	//int sizeOflevel = 0;
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		if (levelArray[i][j] == 1)
	//		{
	//			level[sizeOflevel].init(j * 120, i * 120, 120, 120);
	//			level[sizeOflevel].setTexture("Pic/block1.png");
	//			sizeOflevel++;
	//		}
	//	}
	//}
	//for (int i = 0; i < sizeOflevel; i++)
	//{

	//}
	this->one.loadFromFile("Pic/block1.png");
	this->two.loadFromFile("Pic/block2.png");

	/*if (this->type > 1)
	{
		this->terrain[].setTexture(this->one);
	}
	else
	{
		this->terrain[].setTexture(this->two);
	}*/
}

void Game::enemy_view()
{
	//if (this->player->getGlobalBounds_hit().intersects(this->orc_enemy->getGlobalBounds_hit_orc()))
	//{
	//	if (this->player->getPosition().x > this->orc_enemy->getPosition().x)
	//	{
	//		this->orc_enemy->check_move = 2;
	//	}
	//	else if (this->player->getPosition().x < this->orc_enemy->getPosition().x)
	//	{
	//		this->orc_enemy->check_move = 1;
	//	}
	//	this->orc_enemy->check_view = true;
	//	

	//}
	//else
	//{
	//	this->orc_enemy->check_view = false;
	//}
}

void Game::update_enemy()
{
	//this->spawnTimer += 5.f;
	//if (this->spawn==1)
	//{
		//this->orc_enemies.push_back(new Orc(terrain[column][row].getPosition().x, terrain[column][row].getPosition().y));
		//this->spawnTimer = 0.f;
	//}

	for (int i = 0; i < this->orc_enemies.size(); ++i)
	{
		{

			if (this->player->getGlobalBounds_hit().intersects(this->orc_enemies[i]->getGlobalBounds_hit_orc()))
			{
				if (this->player->getPosition().x > this->orc_enemies[i]->getPosition().x)
				{
					orc_enemies[i]->check_move = 2;
				}
				else if (this->player->getPosition().x < this->orc_enemies[i]->getPosition().x)
				{
					orc_enemies[i]->check_move = 1;
				}
				orc_enemies[i]->check_view = true;


			}
			else
			{
				orc_enemies[i]->check_view = false;
			}
			orc_enemies[i]->update_orc();
		}
	}
}

void Game::player_attack()
{
	for (int i = 0; i < this->orc_enemies.size(); ++i)
	{
		if (this->player->attack == true)
		{
			if (this->player->getGlobalBounds_next().intersects(this->orc_enemies[i]->getGlobalBounds_orc()))
			{
				this->orc_enemies.erase(orc_enemies.begin()+i);
			}
		}
	}
}

void Game::update_coin()
{
	
	for (int i = 0; i < this->coins.size(); i++)
	{
		//printf("%d A\n", coins.size());
		if (this->player->getGlobalBounds_hit().intersects(this->coins[i]->getGlobalBounds_coin()))
		{
			this->coins.erase(this->coins.begin()+i);
			this->score+=5;
			printf("%d\n", score);
			
		}
	}
}

//void Game::setPositionBlock(int x, int y)
//{
//	this->terrain[].setPosition(x, y);
//}

void Game::updateCollision()
{
	//collision buttom
	//if (this->player->getPosition().y + this->player->getGlobalBounds().height > this->window->getSize().y)
	//{
	//	this->player->resetVelocityY();
	//	this->player->setPosition(
	//		this->player->getPosition().x,
	//		this->window->getSize().y - this->player->getGlobalBounds().height
	//	);
	//}
	//if (this->player->getGlobalBounds().top <= 500.f)
	//{
	//	this->player->setPosition(this->player->getPosition().x, 400.f);
	//}
	if (this->player->getGlobalBounds().left <= 80.f)
	{
		this->player->setPosition(130.f, this->player->getGlobalBounds().top);
	}
	else if (this->player->getGlobalBounds().left >= 480.f)
	{
		this->player->setPosition(480.f, this->player->getGlobalBounds().top);
	}
}

void Game::collide()
{
	for (int i = 1; i < 19; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			if (this->have_terr[i][j] > 0)
			{
				plat_left_hit = j * 120.f * 0.8f + 0.f + 90.f - (5.0f * j);
				plat_right_hit = j * 120.f * 0.8f + (120.f * 0.8f) - (5.0f * j);
				plat_top_hit = i * 120.f * 0.8f + 500.f - (5.0f * i);
				plat_bottom_hit = i * 120.f * 0.8f + 500.f + (120.f * 0.8f) - (5.0f * i);
				if (this->player->top_hit < plat_bottom_hit &&
					this->player->bottom_hit  > plat_top_hit)
				{
					this->player->setPosition(player->getPosition().x, i * 120.f * 0.8f + 450.f - (5.0f * i));
				}
				if (this->player->left_hit < plat_right_hit)
				{
					this->player->setPosition(j * 120.f * 0.8f + 0.f + 90.f - (5.0f * j), (player->getPosition().y));
				}
				if (this->player->right_hit  > plat_left_hit)
				{
					this->player->setPosition(j * 120.f * 0.8f + (120.f * 0.8f) - (5.0f * j), (player->getPosition().y));
				}
			}
		}
	}
}

void Game::updatePlayer()
{
	this->fire_above->update_FA();
	this->fire->update_firer();
	this->boss->update_boss();
	this->update_coin();
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
	/*this->update_enemy();*/

	this->player_attack();

	this->updateBlock();

	this->updatePlayer();

	this->updateCollision();

	this->updateWorld();

	//this->enemy_view();
}

void Game::renderPlayer()
{
	this->fire->render(*this->window);
	//this->orc_enemy->render_orc(*this->window);
		for (auto* enemy : this->orc_enemies)
	{
		enemy->render_orc(*this->window);
	}
		for (auto* coin : this->coins)
		{
			coin->render(*this->window);
		}
	this->fire_above->render(*this->window);
	this->boss->render_boss(*this->window);
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

	//sf::Vector2f(0.0f, 0.0f), sf::Vector2f(650.f, 950.f));
	this->view.setSize(650.f,950.f);
	this->view.setCenter(650.f/2,this->player->getPosition().y);
	this->window->setView(view);
	this->window->display();
}

const sf::RenderWindow& Game::getWindow() const
{
	return *this->window;
}
