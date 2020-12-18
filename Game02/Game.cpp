#include "Game.h"


void Game::playgame()
{
	if (play == true)
	{
		this->menu->playMenu = false;
		this->player->player_play = true;
		this->fire_above->fire_above_play = true;
		this->opening->start_op = true;
	}
}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(650, 800), "Tower Escape", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->menu = new Mainmenu(this->window->getSize().x, window->getSize().y);
	this->musicBG.openFromFile("Music/bgMusic.wav");
	this->musicBG.setVolume(20);
}

void Game::initSystem()
{
	this->coinSound.loadFromFile("Music/coinCollect.wav");
	this->coinsSound.setBuffer(this->coinSound);
}

void Game::initItem()
{
	this->shield = new Shield();
	this->potion = new Potion();
}

void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("Pic/Background_2.png"))
	{
		printf("BG ERROR");
	}
	this->op_BackgroundTex.loadFromFile("Pic/Menu.png");

	this->worldBackground.setTexture(this->worldBackgroundTex);
	this->op_Background.setTexture(this->op_BackgroundTex);

}

void Game::initPlayer()
{
	this->player = new Player();
	this->player->setPosition(280.f, 400.f);
	//this->orc_enemy = new Orc(20.f,20.f);
	//this->firebeam = new fireBeam(450.f, this->player->getPosition().y - 200.f);
	
	
}

void Game::initEnemy()
{

	this->opening = new Opening();
	this->boss = new Boss();
	this->fire_above = new Fire_above();
	//this->spawnTimerMax=1000.f;
	//this->spawnTimer = this->spawnTimerMax;
}

void Game::deleteblock()
{
	//if(this->player->getPosition().y>=blocks[i].getposition)
}

void Game::loadMap()
{
	if (delayLoadMap <= 3 && level >=2)
	{
		this->player->setPosition(this->player->getPosition().x, 0.f);
		this->player->gravity_check = false;
		this->change_level = true;
	}
	else if (delayLoadMap > 3 && level >=2)
	{
		this->player->gravity_check = true;
		this->change_level = false;
	}
}

Game::Game()
{
	this->initWindow();
	this->initSystem();
	this->initWorld();
	this->initPlayer();
	this->initEnemy();
	this->initGUI();
	this->initItem();
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
	for (auto* i : this->dirtBlocks)
	{
		delete i;
	}
	for (auto* i : this->stoneBlocks)
	{
		delete i;
	}
	for (auto* i : this->firers)
	{
		delete i;
	}
	for (auto* i : this->fires)
	{
		delete i;
	}
	for (auto* i : this->fireballs)
	{
		delete i;
	}
	for (auto* i : this->firebeams)
	{
		delete i;
	}
	//for (auto* i : this->blocks)
	//{
	//	delete i;
	//}
}

void Game::run()
{
	Textbox playernametextbox(50, sf::Color::White, true);
	playernametextbox.setFont(this->font);
	playernametextbox.setPosition({ 200.f,320.f });
	playernametextbox.setlimit(true, 10);



	this->fp = fopen("./scores.txt", "r");
	for (int i = 0; i < 5; i++) {
		fscanf(fp, "%s", &temp);
		name[i] = temp;
		fscanf(fp, "%d", &scorep[i]);
		userScore.push_back(make_pair(scorep[i], name[i]));
	}
	this->musicBG.play();
;
	while (window->isOpen()) {
		this->musicBG.setLoop(true);
	
		while (this->window->pollEvent(this->ev))
		{

			switch (ev.type)
			{
			case sf::Event::Closed:
				window->close();

			
			case sf::Event::TextEntered:
				if (gameState == 1) {
					playernametextbox.typeOn(ev);
				}

			default:
				break;
			}
			if( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				window->close();
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
		window->clear();

		
		if (gameState == 0)
		{
			this->update();
			this->render();
			this->menu->playMenu = 1;
			if (this->menu->getBounds_1().contains(this->mousePosview))
			{
				//if (canswitch) {
				//	this->switcs.play();
				//	canswitch = false;
				//}
				this->menu->buttoncheck(1);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					//this->clicks.play();
					this->gameState = 1;

				}

			}
			else if (this->menu->getBounds_2().contains(this->mousePosview))

			{
				//if (canswitch) {
				//	this->switcs.play();
				//	canswitch = false;
				//}
				this->menu->buttoncheck(2);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					//this->clicks.play();
					this->window->close();
				}
			}
			else if (this->menu->getBounds_0().contains(this->mousePosview))

			{
				//if (canswitch) {
				//	this->switcs.play();
				//	canswitch = false;
				//}
				this->menu->buttoncheck(2);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					//this->clicks.play();
					gameState = 2;
				}
			}
			else if (this->menu->getBounds_5().contains(this->mousePosview))

			{
	
				this->menu->buttoncheck(5);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					//this->clicks.play();
					gameState = 6;
				}
			}
		}


		//if (enterName == true)
		//{
		//	
		//}
		else if (gameState == 1)
		{
			
			this->update();
			this->render();
			if (this->stopName == false)
			{
				playernametextbox.drawTo(*this->window);
			}
			
			
			
			enterName = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && enterName) {
				play = true;
				this->menu->playMenu = 0;
				stopName = true;
				//enter = false;
				//gamestate = 1;
				name[5] = playernametextbox.gettext();

			}
			if (health <= 0) {
				gameState = 3;
			}
			else if (bossHplose<= 0) {
				gameState = 4;
			}
		}
		
		else if (gameState == 2)
		{
			this->updateMousePositions();
			this->menu->playMenu = 2;
			this->menu->render_Menu(*this->window);
			//highscorena eiei
			
		if (this->menu->getBounds_3().contains(this->mousePosview))

		{
			printf("click");
			this->menu->buttoncheck(3);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				
				//this->clicks.play();
				this->gameState = 0;
			}
		}
			for (int i = 135; i <= 475; i += 85) {
				showhighscore(450, i, to_string(userScore[(i - 135) / 85].first), *this->window, &font);
				showhighscore(100, i, userScore[(i - 135) / 85].second, *this->window, &font);
			}

		}
		else if (gameState == 3)
		{
		this->updateMousePositions();
			std::stringstream your_score;
			this->menu->playMenu = 3;
			this->menu->render_Menu(*this->window);
			
			
			//printf("stage 3");
			your_score <<"YOUR SCORE: "<< this->score;
			//std::cout << "YOUR SCORE:" << this->score;
			
			this->menu->scoreText.setString(your_score.str());
			if (this->menu->getBounds_4().contains(this->mousePosview))

			{
				printf("click");
				//this->menu->buttoncheck(3);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					//this->clicks.play();
					this->gameState = 5;
				}
			}
		
		}
		else if (gameState == 4)
		{
		this->updateMousePositions();
		std::stringstream your_score;
		this->menu->playMenu = 4;
		this->menu->render_Menu(*this->window);


		//printf("stage 3");
		your_score << "YOUR SCORE: " << this->score;
		//std::cout << "YOUR SCORE:" << this->score;

		this->menu->scoreText.setString(your_score.str());
		if (this->menu->getBounds_4().contains(this->mousePosview))

		{
			printf("click");
			//this->menu->buttoncheck(3);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				//this->clicks.play();
				this->gameState = 5;
			}
		}

		}
		else if (gameState ==5)
		{
		printf("stage 4");
			if (endgames == false) {
				this->fp = fopen("./scores.txt", "r");
				scorep[5] = score;
				userScore.push_back(make_pair(scorep[5], name[5]));
				sort(userScore.begin(), userScore.end());
				fclose(fp);
				fopen("./scores.txt", "w");
				for (int i = 5; i >= 1; i--) {
					strcpy(temp, userScore[i].second.c_str());
					fprintf(fp, "%s %d\n", temp, userScore[i].first);
				}
				fclose(fp);
				endgames = true;
			}
		}
		else if (gameState == 6)
		{
		this->updateMousePositions();
		this->menu->playMenu = 6;
		this->menu->render_Menu(*this->window);


		if (this->menu->getBounds_6().contains(this->mousePosview))

		{
			printf("click");
			//this->menu->buttoncheck(3);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

				//this->clicks.play();
				this->gameState = 0;
			}
		}

		}
		window->display();
	}
}

void Game::showhighscore(int x, int y, string word, sf::RenderWindow& window, sf::Font* font)
{
	sf::Text text;
	text.setFont(*font);
	text.setPosition(x, y);
	text.setString(word);
	text.setCharacterSize(100);
	text.setOutlineThickness(2.f);
	text.setOutlineColor(sf::Color::Black);
	window.draw(text);
}

void Game::updateMousePositions()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosview = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::initGUI()
{
	this->font.loadFromFile("Font/CRIT RACE.ttf");

	this->auraText.setFont(this->font);
	this->auraText.setCharacterSize(30);
	this->auraText.setFillColor(sf::Color::White);
	this->auraText.setOutlineColor(sf::Color::Black);
	this->auraText.setOutlineThickness(2.f);

	this->healthText.setFont(this->font);
	this->healthText.setCharacterSize(30);
	this->healthText.setFillColor(sf::Color::White);
	this->healthText.setOutlineColor(sf::Color::Black);
	this->healthText.setOutlineThickness(2.f);

	this->healthTex.loadFromFile("Pic/heart.png");
	this->shieldTex.loadFromFile("Pic/shieldIcon1.png");
	this->health_s.setTexture(this->healthTex);
	this->shield_s.setTexture(this->shieldTex);
	this->shield_s.setScale(0.7f, 0.7f);

	this->scoreText.setFont(this->font);
	this->scoreText.setCharacterSize(40);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setOutlineColor(sf::Color::Black);
	this->scoreText.setOutlineThickness(2.f);

	this->bossHpBar.setSize(sf::Vector2f(500.f, 25.f));
	this->bossHpBar.setFillColor(sf::Color::Red); 

	this->BossHpTex.loadFromFile("Pic/bossHpbar.png");
	this->BossHp.setTexture(this->BossHpTex);
	this->BossHp.setScale(0.7f, 0.7f);
}

int Game::Block_ran()
{
	this->type = rand() % 17;
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

					Block_ran();
					if (this->type <= 1)
					{
						//this->terrain[column][row].setTexture(one);
						this->have_terr[column][row] = 1;
					}
					else if (this->type == 2)
					{
						//this->terrain[column][row].setTexture(two);
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
			if (this->player->getPosition().y + 400.f >= column * 120.f * 0.75 + 500.f)
			{
				for (row = 0; row <= 4; row++)
				{
					
					//this->terrain[column][row].setScale(0.75f, 0.75f);
					//this->terrain[column][row].setPosition(x, y);
					
					//this->window->draw(this->terrain[column][row]);

					if (this->have_terr[column][row] == 1)
					{

						//this->blocks.push_back(new Block(x, y));
						//this->blockCheck.setOutlineColor(sf::Color::Cyan);
						//this->blockCheck.setOutlineThickness(2.f);
						//this->blockCheck.setFillColor(sf::Color::Transparent);
						//this->blockCheck.setPosition(x, y);
						//this->blockCheck.setSize(sf::Vector2f(120.f * 0.75f, 120.f * 0.75f));
						//this->window->draw(this->blockCheck);
					}
					else if (have_terr[column][row] == 0)
					{
						this->coins.push_back(new Point(x+20.f, y+30.f));
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


}

void Game::createBlock()
{
	this->difficulty = this->timedifficulty.getElapsedTime().asSeconds();
	this->delayLoadMap = this->timeLoadMap.getElapsedTime().asSeconds();
	this->delayItem = this->timeItem.getElapsedTime().asSeconds();
	//printf("%d\n", delayLoadMap);
	if (this->player->getPosition().y+600.f>=this->y)
	{
		

		for (row = 0; row < 5; row++)
		{
			Block_ran();

			plat_left_hit = x;
			plat_right_hit = x + 88;
			plat_top_hit = y;
			if (x == 188 || x==364)
			{
				if (this->type == 6 || this->type == 7)
				{
					this->type = 0;
				}
			}
			change_level = false;
			if (y <=500 && level == 1) //opening
			{

				if (x == 100 || x == 452) 
				{
					type = 6;
				}
				else
				{
					type = 0;
				}
			}
			else if (y <= 800 && y>=500 && level == 1)
			{
				if (type > 8)
				{
					type = 0;
				}
			}

			if (level == 1 && y >= 6500)
			{
				type = 14;
				
				if (y > 7200)
				{
					//change_level = true;
					level = 2;
					itemcount = 0;
					x = 100; 
					y = 212;
					this->fire_above->setPosition(50.f, -100.f);
					this->fire_above->speedIncrease = 2;
					this->timeLoadMap.restart();
					//this->player->setPosition(this->player->getPosition().x, 0.f);
				}
			}
			if (level == 2 && y >= 7700)
			{
				type = 14;
				
				if (y > 8400)
				{
					//change_level = true;
					level = 3;
					itemcount = 0;
					x = 100;
					y = 212;
					this->fire_above->setPosition(50.f, -100.f);
					this->fire_above->speedIncrease = 3;
					this->timeLoadMap.restart();
					//this->player->setPosition(this->player->getPosition().x, 0.f);
				}
			}
			if (level == 3 && y >= 8700)
			{
				type = 14;
			
				if (y > 9200)
				{
					//change_level = true;
					level = 4;
					x = 100;
					y = 950;
					this->timeLoadMap.restart();
					this->timeFireball.restart();
					this->fire_above->setPosition(50.f, -100.f);
					this->fire_above->speedIncrease = 0;
					//this->player->setPosition(this->player->getPosition().x, 0.f);
				}
			}

			if (level == 2 && y<=900)
			{
				if (x >= 188 && x <= 364 && y == 300)
				{
					type = 0;
				}
				else if (x == 364 && y == 388)
				{
					type = 0;
				}
				else if (x >= 188 && x <= 364 && y == 476)
				{
					type = 0;
				}
				else if (x == 188 && y == 564)
				{
					type = 0;
				}
				else if (x >= 188 && x <= 364 && y == 652)
				{
					type = 0;
				}
				else if (y == 828)
				{
					type = 0;
				}
				else
				{
					type = 14;
				}
			}

			if (level == 3 && y <= 900)
			{
				if (x >= 188 && x <= 364 && y == 300)
				{
					type = 0;
				}
				else if (x == 364 && y == 388)
				{
					type = 0;
				}
				else if (x >= 188 && x <= 364 && y == 476)
				{
					type = 0;
				}
				else if (x == 364 && y == 564)
				{
					type = 0;
				}
				else if (x >= 188 && x <= 364 && y == 652)
				{
					type = 0;
				}
				else if (y == 828)
				{
					type = 0;
				}
				else
				{
					type = 14;
				}
			}
			if (level == 4)
			{
				type = 6;
			}
			if ((type == 11 || type ==12) && itemcount > 5)
			{
				type = 14;
			}
				//if (y >= 5000.f && y<=5700.f)
			//{
			//	type = 11;
			//}
			//else if (y >= 5600.f)
			//{
			//	this->dirtBlocks.push_back(new Block_dirt(1000.f,6400.f));
			//	type = 6;
			//	
			//}
			
			if (this->type <= 5)
			{
				this->dirtBlocks.push_back(new Block_dirt(x, y));
				//if (this->player->getPosition().y>= 6500)
				//{
				//	this->dirtBlocks.push_back(new Block_dirt(x+1000.f, y+500.f));
				//}
			}
			else if (this->type == 6 || this->type == 7)
			{
				this->stoneBlocks.push_back(new Block_Stone(x, y));
				//this->stoneBlocks.push_back(new Block_Stone(x + 800.f, y + 500.f));
				
			}
			else if (this->type == 8)
			{
				this->coins.push_back(new Point(x + 20.f, y + 30.f));
				this->coins.push_back(new Point(x + 600.f, y + 500.f));

			}
			else if (this->type == 9)
			{
				if (level == 1)
				{
					if (difficulty%3 ==0)
					{
						this->orc_enemies.push_back(new Orc(x, y));
						//this->orc_enemies.push_back(new Orc(x + 1000.f, y + 500.f));
					}
				}
				if (level == 2)
				{
					if (difficulty % 2 == 0)
					{
						this->orc_enemies.push_back(new Orc(x, y));
						//this->orc_enemies.push_back(new Orc(x + 1000.f, y + 500.f));
					}
				}
				if (level == 3)
				{
	
					this->orc_enemies.push_back(new Orc(x, y));
					//this->orc_enemies.push_back(new Orc(x + 1000.f, y + 500.f));

					
				}

			}
			else if(this->type == 10 )
			{
				if (level == 1)
				{
					if (difficulty %3 == 1 && firecheck % 3 != 1)
					{
						this->fires.push_back(new Fire(100.f, y + 10.f));
						this->firers.push_back(new firer(33.f, y));
					}
				}
				if (level == 2)
				{
					if (difficulty % 2 == 1 && firecheck % 3 != 1)
					{
						this->fires.push_back(new Fire(100.f, y + 10.f));
						this->firers.push_back(new firer(33.f, y));
					}
				}
				if (level == 3)
				{
					if (firecheck % 3 != 1)
					{
						this->fires.push_back(new Fire(100.f, y + 10.f));
						this->firers.push_back(new firer(33.f, y));
					}
				}

				firecheck++;
			}
			else if(this->type ==11 && this->shield->remove_shield ==true && delayItem > 10.f)
			{
		
				this->shield->setPosition_shield(x + 20.f, y + 15.f);
				this->shield->remove_shield = false;
				itemcount++;
				this->timeItem.restart();
			}
			else if (this->type == 12 && this->potion->remove_potion == true && delayItem>10.f)
			{

				this->potion->setPosition_potion(x+20.f, y+15.f);
				this->potion->remove_potion = false;
				itemcount++;
				this->timeItem.restart();
			}
			x += 88;
		}
		//if (x >= 452)
		//{
			y += 88;
			x = 100;
		//}
		
	}
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

void Game::enemy_walk()
{

	for (int i = 0; i < this->orc_enemies.size(); ++i)
	{
		for (int j = 0; j < this->dirtBlocks.size(); ++j)
		{

			//dirt
			if (this->orc_enemies[i]->getGlobalBounds_next_orc().intersects(this->dirtBlocks[j]->getGlobalBounds()))
			{
				this->orc_enemies[i]->check_blocknext = false;
			}
			else
			{
				//this->orc_enemies[i]->check_blocknext = true;
			}
			
			if (this->orc_enemies[i]->getGlobalBounds_below_orc().intersects(this->dirtBlocks[j]->getGlobalBounds()))
			{

				this->orc_enemies[i]->check_gravity = false;
			}
			else
			{
				//this->orc_enemies[i]->check_gravity = true;
			}
			
			
		}

		//stone
		for (int j = 0; j < this->stoneBlocks.size(); ++j)
		{
			if (this->orc_enemies[i]->getGlobalBounds_next_orc().intersects(this->stoneBlocks[j]->getGlobalBounds()))
			{
				this->orc_enemies[i]->check_blocknext = false;
			}
			else
			{
				//this->orc_enemies[i]->check_blocknext = true;
			}
			if (this->orc_enemies[i]->getGlobalBounds_below_orc().intersects(this->stoneBlocks[j]->getGlobalBounds()))
			{
				this->orc_enemies[i]->check_gravity = false;
			}
			else
			{
				//this->orc_enemies[i]->check_gravity = true;
			}
		}
		
	}
}


void Game::update_boss()
{
	if (this->level == 4)
	{
		this->boss->bossFight = true;
	}
	if (this->player->getGlobalBounds_attack().intersects(this->boss->getGlobalBounds_hit_box_boss()) && this->player->attack == true)
	{
		this->bossHplose-=10;
	}
	
}

void Game::update_fireabove()
{
	this->fire_above->update_FA();
	
	if (change_level == true)
	{
		this->fire_above->opRestart = 0;
	}

	if (level == 4)
	{
		this->fire_above->fire_above_play = false;
	}
	if (this->fire_above->getGlobalBounds().intersects(this->player->getGlobalBounds_hit()))
	{
		this->health = 0;
	}
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
		this->delayEnemyAttack=this->timeEnemyAttack.getElapsedTime().asSeconds();
		if (change_level == true && this->orc_enemies[i]->getPosition().y >= 700.f)
		{
			this->orc_enemies[i]->setPosition(-200.f, 500.f);
			orc_enemies[i]->check_view = false;
			orc_enemies[i]->check_gravity = false;
			orc_enemies[i]->check_blocknext = false;
			orc_enemies[i]->check_move = false;

		}
		if (this->player->getGlobalBounds_hit().intersects(this->orc_enemies[i]->getGlobalBounds_next_orc()))
		{
			if (this->delayEnemyAttack >= 1.5f && this->shield->aura_shield==false)
			{
				this->timeEnemyAttack.restart();
				health--;
			}
			orc_enemies[i]->check_move = 3;

		}
		else if (this->player->getGlobalBounds_hit().intersects(this->orc_enemies[i]->getGlobalBounds_hit_orc()))
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


		if (this->player->getPosition().y - 700.f >= this->orc_enemies[i]->getPosition().y && orc_enemies[i]->getPosition().x == -200.f)
		{
			if (this->level == 1 || this->level == 2 || this->level == 3)
			{
				this->orc_enemies[i]->remove_orc = true;
				//this->orc_enemies.erase(this->orc_enemies.begin() + i);
			}
		}
		else if (this->player->getPosition().y - 800.f >= this->orc_enemies[i]->getPosition().y)
		{
			if (this->level == 1 || this->level == 2 || this->level == 3)
			{
				this->orc_enemies[i]->setPosition(-200.f, this->player->getPosition().y + 1500.f);
				orc_enemies[i]->check_view = false;
				orc_enemies[i]->check_gravity = false;
				orc_enemies[i]->check_blocknext = false;
				orc_enemies[i]->check_move = false;
			}

		}

		orc_enemies[i]->update_orc();
	}
}

void Game::update_block()
{
	//this->blocks.push_back(new Block());
	/*for (int i = 0; i < this->blocks.size(); ++i)
	{

		if (this->player->getGlobalBounds_hit().intersects(this->blocks[i]->getGlobalBounds()))
		{
			this->player->setPosition(this->player->getPosition().x, this->blocks[i]->getPosition().y-88.f);
		}
		if (this->player->getPosition().y - 400.f >= this->blocks[i]->getPosition().y)
		{
			this->blocks.erase(this->blocks.begin() + i);
		}
		if (this->player->digdown == true)
		{
			if (this->player->getGlobalBounds_down().intersects(blocks[i]->getGlobalBounds()))
			{
				this->blocks.erase(this->blocks.begin() + i);
			}
		}
		if (this->player->digup == true)
		{
			if (this->player->getGlobalBounds_up().intersects(blocks[i]->getGlobalBounds()))
			{
				this->blocks.erase(this->blocks.begin() + i);
			}
		}
		if (this->player->digdown == true)
		{
			if (this->player->getGlobalBounds_down().intersects(blocks[i]->getGlobalBounds()))
			{
				this->blocks.erase(this->blocks.begin() + i);
			}
		}
		if (this->player->attack == true)
		{
			if (this->player->getGlobalBounds_attack().intersects(blocks[i]->getGlobalBounds()))
			{
				this->blocks.erase(this->blocks.begin() + i);
			}
		}
		blocks[i]->update();

	}*/
}

void Game::update_dirtBlock()
{
	for (int i = 0; i < this->dirtBlocks.size(); ++i)
	{
		//change level
		if (change_level == true && this->dirtBlocks[i]->getPosition().y >= 700.f)
		{
			this->dirtBlocks[i]->setPosition(-200.f, 500.f);

		}

		//end level


		if (this->player->getGlobalBounds_down().intersects(this->dirtBlocks[i]->getGlobalBounds()))
		{
			this->player->setPosition(this->player->getPosition().x, this->dirtBlocks[i]->getPosition().y - 88.f);
		}
		if (this->player->getGlobalBounds_next().intersects(this->dirtBlocks[i]->getGlobalBounds()))
		{
			//if (this->player->getGlobalBounds_hit().intersects(this->dirtBlocks[i]->getGlobalBounds()))
			//{
			if (this->player->getGlobalBounds_hit().left < this->dirtBlocks[i]->getGlobalBounds().left
				&& this->player->getGlobalBounds_hit().left + this->player->getGlobalBounds_hit().width < this->dirtBlocks[i]->getGlobalBounds().left + this->dirtBlocks[i]->getGlobalBounds().width
				&& this->player->getGlobalBounds_hit().top<this->dirtBlocks[i]->getGlobalBounds().top + this->dirtBlocks[i]->getGlobalBounds().height
				&& this->player->getGlobalBounds_hit().top + this->player->getGlobalBounds_hit().height>this->dirtBlocks[i]->getGlobalBounds().top
				) {
				this->player->setPosition(this->dirtBlocks[i]->getGlobalBounds().left - this->player->getGlobalBounds_hit().width-20.f, this->player->getPosition().y);
			}
			if (this->player->getGlobalBounds_hit().left > this->dirtBlocks[i]->getGlobalBounds().left
				&& this->player->getGlobalBounds_hit().left + this->player->getGlobalBounds_hit().width > this->dirtBlocks[i]->getGlobalBounds().left + this->dirtBlocks[i]->getGlobalBounds().width
				&& this->player->getGlobalBounds_hit().top<this->dirtBlocks[i]->getGlobalBounds().top + this->dirtBlocks[i]->getGlobalBounds().height
				&& this->player->getGlobalBounds_hit().top + this->player->getGlobalBounds_hit().height>this->dirtBlocks[i]->getGlobalBounds().top
				) {
				this->player->setPosition(this->dirtBlocks[i]->getGlobalBounds().left+ this->dirtBlocks[i]->getGlobalBounds().width+5.f, this->player->getPosition().y);
				
			}
				//if (this->player->getPosition().x > this->dirtBlocks[i]->getPosition().x)
				//{
				//	this->player->setPosition(this->dirtBlocks[i]->getPosition().x + 80.f, this->player->getPosition().y);
				//}
				//else if (this->player->getPosition().x < this->dirtBlocks[i]->getPosition().x)
				//{
				//	this->player->setPosition(this->dirtBlocks[i]->getPosition().x - this->player->hitbox_player.getGlobalBounds().width, this->player->getPosition().y);
				//}
			//}
		}


		if (this->player->getPosition().y - 800.f >= this->dirtBlocks[i]->getPosition().y)
		{
			this->dirtBlocks.erase(this->dirtBlocks.begin() + i);
		}
		if (this->player->digdown == true && this->player->getGlobalBounds_down().intersects(dirtBlocks[i]->getGlobalBounds()))
		{
			if (this->level == 1 && this->player->getPosition().y>=6300)
			{
				this->dirtBlocks[i]->setPosition(-200.f, 6500.f);
			}
			else if (this->level == 2 && this->player->getPosition().y >= 7500)
			{
				this->dirtBlocks[i]->setPosition(-200.f, 7700.f);
			}
			else if (this->level == 3 && this->player->getPosition().y >= 8500)
			{
				this->dirtBlocks[i]->setPosition(-200.f,8700.f);
			}
			else
			{
				this->dirtBlocks.erase(this->dirtBlocks.begin() + i);
			}
		}
		if (this->player->digup == true)
		{
			if (this->player->getGlobalBounds_up().intersects(dirtBlocks[i]->getGlobalBounds()))
			{
				this->dirtBlocks.erase(this->dirtBlocks.begin() + i);
			}
		}
		else if (this->player->digdown == true)
		{
			if (this->player->getGlobalBounds_down().intersects(dirtBlocks[i]->getGlobalBounds()))
			{
				this->dirtBlocks.erase(this->dirtBlocks.begin() + i);
			}
		}
		else if (this->player->attack == true)
		{
			if (this->player->getGlobalBounds_attack().intersects(dirtBlocks[i]->getGlobalBounds()))
			{
				this->dirtBlocks.erase(this->dirtBlocks.begin() + i);
			}
		}
		dirtBlocks[i]->update();

	}
}

void Game::update_stoneBlock()
{
	for (int i = 0; i < this->stoneBlocks.size(); ++i)
	{
		if (change_level == true && this->stoneBlocks[i]->getPosition().y >= 700.f)
		{
			this->stoneBlocks[i]->setPosition(-200.f, 500.f);

		}
		if (this->player->getGlobalBounds_down().intersects(this->stoneBlocks[i]->getGlobalBounds()))
		{
			this->player->setPosition(this->player->getPosition().x, this->stoneBlocks[i]->getPosition().y - 88.f);
		}

		if (this->player->getGlobalBounds_next().intersects(this->stoneBlocks[i]->getGlobalBounds()) && this->player->getGlobalBounds_hit().intersects(this->stoneBlocks[i]->getGlobalBounds()))
		{
			if (this->player->getGlobalBounds_hit().left < this->stoneBlocks[i]->getGlobalBounds().left
				&& this->player->getGlobalBounds_hit().left + this->player->getGlobalBounds_hit().width < this->stoneBlocks[i]->getGlobalBounds().left + this->stoneBlocks[i]->getGlobalBounds().width
				&& this->player->getGlobalBounds_hit().top<this->stoneBlocks[i]->getGlobalBounds().top + this->stoneBlocks[i]->getGlobalBounds().height
				&& this->player->getGlobalBounds_hit().top + this->player->getGlobalBounds_hit().height>this->stoneBlocks[i]->getGlobalBounds().top
				) {
				this->player->setPosition(this->stoneBlocks[i]->getGlobalBounds().left - this->player->getGlobalBounds_hit().width-20.f, this->player->getGlobalBounds_hit().top-41.f);
			}
			if (this->player->getGlobalBounds_hit().left > this->stoneBlocks[i]->getGlobalBounds().left
				&& this->player->getGlobalBounds_hit().left + this->player->getGlobalBounds_hit().width > this->stoneBlocks[i]->getGlobalBounds().left + this->stoneBlocks[i]->getGlobalBounds().width
				&& this->player->getGlobalBounds_hit().top<this->stoneBlocks[i]->getGlobalBounds().top + this->stoneBlocks[i]->getGlobalBounds().height
				&& this->player->getGlobalBounds_hit().top + this->player->getGlobalBounds_hit().height>this->stoneBlocks[i]->getGlobalBounds().top
				) {
				this->player->setPosition(this->stoneBlocks[i]->getGlobalBounds().left + this->stoneBlocks[i]->getGlobalBounds().width, this->player->getGlobalBounds_hit().top - 41.f);

			}
			//if (this->player->getGlobalBounds_hit().intersects(this->stoneBlocks[i]->getGlobalBounds()))
			//{
			//	if (this->player->getPosition().x > this->stoneBlocks[i]->getPosition().x)
			//	{
			//		this->player->setPosition(this->stoneBlocks[i]->getPosition().x + 80.f, this->player->getPosition().y);
			//		//std::cout << this->player->getPosition().x<<" " << this->player->getPosition().y << "\n";
			//	}
			//	else if (this->player->getPosition().x < this->stoneBlocks[i]->getPosition().x)
			//	{
			//		this->player->setPosition(this->stoneBlocks[i]->getPosition().x - this->player->hitbox_player.getGlobalBounds().width, this->player->getPosition().y);
			//		//std::cout << this->player->getPosition().x <<" "<< this->player->getPosition().y << "\n";
			//	}
			//}
		}
		if (this->player->getPosition().y - 700.f >= this->stoneBlocks[i]->getPosition().y && stoneBlocks[i]->getPosition().x == -100.f)
		{
			if (this->level == 1 || this->level == 2 || this->level == 3)
			{
				this->stoneBlocks.erase(this->stoneBlocks.begin() + i);
			}
		}
		else if (this->player->getPosition().y - 800.f >= this->stoneBlocks[i]->getPosition().y)
		{
			if (this->level == 1 || this->level == 2 || this->level == 3)
			{
				this->stoneBlocks[i]->setPosition(-100.f, this->player->getPosition().y + 1500.f);
			}

		}
		stoneBlocks[i]->update();
	}
}

void Game::update_firer()
{

	for (int i = 0; i < this->firers.size(); ++i)
	{
		if (change_level == true && this->firers[i]->getPosition().y >= 700.f)
		{
			this->firers[i]->setPosition(-200.f, 500.f);

		}
		if (this->player->getPosition().y - 700.f >= this->firers[i]->getPosition().y && firers[i]->getPosition().x == -200.f)
		{
			if (this->level == 1 || this->level == 2 || this->level == 3)
			{
				this->firers.erase(this->firers.begin() + i);
			}
		}
		else if (this->player->getPosition().y - 800.f >= this->firers[i]->getPosition().y)
		{
			if (this->level == 1 || this->level == 2 || this->level == 3)
			{
				this->firers[i]->setPosition(-200.f, this->player->getPosition().y + 1500.f);
			}

		}

	}
}

void Game::update_fire()
{
	this->delayfire = this->timefire.getElapsedTime().asSeconds();
	for (int i = 0; i < this->fires.size(); ++i)
	{
		if (this->delayfire >= 1.f)
		{
			if (this->player->getGlobalBounds_hit().intersects(this->fires[i]->getGlobalBounds()) && this->shield->aura_shield == false)
			{
				health--;
				this->timefire.restart();
			}

		}
		if (this->player->getGlobalBounds_hit().intersects(this->fires[i]->getGlobalBounds()))
		{

			this->fires.push_back(new Fire(100.f, this->fires[i]->getPosition().y));
			this->fires.erase(fires.begin() + i);
		}

	
		if (change_level == true)
		{
			if (this->player->getPosition().y >= this->fires[i]->getPosition().y)
			{
				this->fires[i]->setPosition(-200.f, this->player->getPosition().y + 1000.f);
			}

		}
		if (this->player->getPosition().y - 400.f >= this->fires[i]->getPosition().y)
		{

			this->fires[i]->setPosition(-200.f, this->player->getPosition().y + 1500.f);

		}
		if (this->player->getPosition().y - 700.f >= this->fires[i]->getPosition().y && fires[i]->getPosition().x == -200.f)
		{
			if (this->level == 1 || this->level == 2 || this->level == 3)
			{
				this->fires.erase(this->fires.begin() + i);
			}
		}
		else if (this->player->getPosition().y - 800.f >= this->fires[i]->getPosition().y)
		{
			if (this->level == 1 || this->level == 2 || this->level == 3)
			{
				this->fires[i]->setPosition(-200.f, this->player->getPosition().y + 1500.f);
			}

		}



		fires[i]->update_fire();
	}

}

void Game::update_fireball()
{
	this->delayLoseHpFireball = this->timeLoseHpFireball.getElapsedTime().asSeconds();
	for (int i = 0; i < this->fireballs.size(); ++i)
	{
		if (this->player->getGlobalBounds_hit().intersects(this->fireballs[i]->getGlobalBounds()))
		{
			this->fireballs[i]->setPosition(-100.f, this->player->getPosition().y);
			if (this->delayLoseHpFireball > 1 && this->shield->aura_shield == false)
			{
				//this->fireballs.erase(this->fireballs.begin() + i);
				this->health--;
				this->timeLoseHpFireball.restart();
			}
		}
		
		if (this->player->getPosition().y + 200.f <= this->fireballs[i]->getPosition().y)
		{
			this->fireballs[i]->remove = false;
		}




		
		fireballs[i]->update_fireball();
	}
}

void Game::update_firebeam()
{
	this->delayLoseHpfirebeam=this->timeLoseHpfirebeam.getElapsedTime().asSeconds();
	for (int i = 0; i < this->firebeams.size(); ++i)
	{
		if (this->player->getGlobalBounds_hit().intersects(this->firebeams[i]->getGlobalBounds1()) && 
			this->shield->aura_shield==false && this->delayLoseHpfirebeam >1.f)
		{
			health--;
			this->timeLoseHpfirebeam.restart();
		}
		else if (this->player->getGlobalBounds_hit().intersects(this->firebeams[i]->getGlobalBounds2()) &&
			this->shield->aura_shield == false && this->delayLoseHpfirebeam > 1.f)
		{
			health--;
			this->timeLoseHpfirebeam.restart();
		}
		//this->firebeams[i]->skill = rand() % 2;
		this->firebeams[i]->update_firebeam();
	}
}

void Game::updateGUI()
{
	std::stringstream healthNum;
	std::stringstream auraNum;
	std::stringstream scoreNum;

	scoreNum << "Score :" << score;
	healthNum << " x " << health;
	auraNum << " x " << aura;
	this->healthText.setString(healthNum.str());
	this->auraText.setString(auraNum.str());
	this->bossHpBar.setSize(sf::Vector2f(bossHplose, this->bossHpBar.getSize().y));
	if (level == 4 && this->player->getPosition().y >= 400)
	{
		this->scoreText.setPosition(sf::Vector2f(480.f, this->player->getPosition().y - 550.f));
		this->auraText.setPosition(sf::Vector2f(135.f, this->player->getPosition().y - 550.f));
		this->healthText.setPosition(sf::Vector2f(35.f, this->player->getPosition().y - 550.f));
		this->health_s.setPosition(sf::Vector2f(0.f, this->player->getPosition().y - 550.f));
		this->shield_s.setPosition(sf::Vector2f(100.f, this->player->getPosition().y - 550.f));

		this->BossHp.setPosition(sf::Vector2f(60.f, 345.f));
		this->bossHpBar.setPosition(sf::Vector2f(85.f, 350.f));
	}
	else
	{
		this->scoreText.setPosition(sf::Vector2f(480.f, this->player->getPosition().y - 470.f));
		this->auraText.setPosition(sf::Vector2f(135.f, this->player->getPosition().y - 470.f));
		this->healthText.setPosition(sf::Vector2f(35.f, this->player->getPosition().y - 470.f));
		this->health_s.setPosition(sf::Vector2f(0.f, this->player->getPosition().y - 470.f));
		this->shield_s.setPosition(sf::Vector2f(100.f, this->player->getPosition().y - 470.f));

	}
	

	this->scoreText.setString(scoreNum.str());
	


}

void Game::update_Item()
{
	this->shield->update();
	this->potion->update();
	this->delayShield=this->timeShield.getElapsedTime().asSeconds();
	this->shield->setPosition_aura(this->player->getPosition().x-25.f, this->player->getPosition().y-10.f);
	if (this->delayShield > 5.f)
	{
		this->shield->aura_shield = false;
		if (this->aura > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E) )
		{
			aura=0;
			this->shield->aura_shield = true;
			this->timeShield.restart();
			
		}
	}
	
	if (this->player->getGlobalBounds_hit().intersects(this->potion->getGlobalBounds_potion()))
	{
		this->potion->setPosition_potion(-100.f, this->player->getPosition().y);
		this->potion->remove_potion = true;
		this->health++;

	}
	if (this->player->getGlobalBounds_hit().intersects(this->shield->getGlobalBounds_shield()))
	{
		this->shield->setPosition_shield(20.f, this->player->getPosition().y);
		this->shield->remove_shield = true;
		this->aura++;
		
	}
	 if(this->player->getPosition().y - 700.f >= this->potion->getPosition_potion().y)
	{
		this->potion->setPosition_potion(-100.f, this->player->getPosition().y);
		this->potion->remove_potion = true;

	}
	else if (this->player->getPosition().y - 700.f >= this->shield->getPosition_shield().y)
	{
		this->shield->setPosition_shield(-100.f, this->player->getPosition().y);
		this->shield->remove_shield = true;

	}
}

void Game::boss_attack()
{
	//spawnTimer += 20.f;
	sudoX = this->player->getPosition().x;
	this->delaySkill=this->timeSkill.getElapsedTime().asSeconds();
	this->delayFireball = this->timeFireball.getElapsedTime().asSeconds();
	
	if (this->bossStart==1)
	{
		this->boss->setPosition(380.f,900.f);
		this->boss->animation_boss = 0;
		
		bossStart = 2;
	}
	else if (level == 4 && this->bossStart ==0)
	{
		this->bossStart = 1;
		this->timeSkill.restart();
	}
	if (this->delaySkill >= rand()%10 +10.f  && bossStart == 2)
	{
		boss_skill = sudoX %2+1 ;
		this->timeSkill.restart();
	}
	printf("[%d]", boss_skill);
	if (boss_skill == 2)
	{
		if (this->delayFireball >= 1)
		{
			fireballX = rand() % 450 + 100.f;
			this->fireballs.push_back(new Fireball(fireballX, this->player->getPosition().y - 1000.f));
			this->timeFireball.restart();
		}

	}
	else if (boss_skill == 1)
	{
		if (this->delayFireball >= 4)
		{
			this->firebeams.push_back(new fireBeam(550.f, this->player->getPosition().y - 400.f));
			this->timeFireball.restart();
		}
	}
}




void Game::player_attack()
{
	for (int i = 0; i < this->orc_enemies.size(); ++i)
	{
		if (this->player->attack == true)
		{
			if (this->player->getGlobalBounds_attack().intersects(this->orc_enemies[i]->getGlobalBounds_orc()))
			{
				this->orc_enemies.erase(orc_enemies.begin()+i);
			}
		}
	}
}

void Game::update_coin()
{
	
	for (int i = 0; i < this->coins.size(); ++i)
	{
		//printf("%d A\n", coins.size());
		if (change_level == true && this->coins[i]->getPosition().y >= 700.f)
		{
			this->coins[i]->setPosition(-200.f, 500.f);

		}
		if (this->player->getGlobalBounds_hit().intersects(this->coins[i]->getGlobalBounds_coin()))
		{
			this->coins[i]->setPosition(-100.f, this->player->getPosition().y + 1000.f);
			this->score+=5;
			this->coinsSound.play();
			//printf("%d\n", score);
		}
		if (this->player->digup == true)
		{
			if(this->player->getGlobalBounds_up().intersects(this->coins[i]->getGlobalBounds_coin()))
			{
				this->coins.erase(this->coins.begin() + i);
				this->score += 5;
				//printf("%d\n", score);
			}
		}

		if (this->player->getPosition().y - 700.f >= this->coins[i]->getPosition().y && coins[i]->getPosition().x == -100.f)
		{
			if (this->level == 1 || this->level == 2 || this->level == 3)
			{
				this->coins.erase(this->coins.begin() + i);
			}
		}
		else if (this->player->getPosition().y - 800.f >= this->coins[i]->getPosition().y)
		{
			if (this->level == 1 || this->level == 2 || this->level == 3)
			{
				this->coins[i]->setPosition(-100.f, this->player->getPosition().y + 1500.f);
			}

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
	if (this->player->getGlobalBounds().left <= 60.f)
	{
		this->player->setPosition(95.f, this->player->getGlobalBounds().top);
	}
	else if (this->player->getGlobalBounds().left >= 480.f)
	{
		this->player->setPosition(480.f, this->player->getGlobalBounds().top);
	}
}

void Game::MenuGUI()
{
	this->menu->render_Menu(*this->window);
	
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

void Game::updateOp()
{
	this->opening->update();
}

void Game::updatePlayer()
{

	if (this->player->test==true)
	{
		this->health = 5;
	}
	this->boss->update_boss();
	this->update_coin();
	this->player->update();
	std::cout << this->player->getPosition().x << " -- " << this->player->getPosition().y << "\n";
}

void Game::updateWorld()
{
	int WorldY;
	//worldY += 900.f;
	WorldY = this->player->getPosition().y;
	if (level == 4)
	{
		this->worldBackground.setPosition(0.f, 250.f);
	}
	else if (this->player->getPosition().y >= 450)
	{
		this->worldBackground.setPosition(0.f, WorldY - 450.f);
	}

	this->op_Background.setPosition(-73.f, 60.f);
	this->op_Background.setScale(1.45f, 1.45f);
	//if (WorldY%900 >= 800.f)
	//{
	//	
	//	this->worldBackground.setPosition(0.f, WorldY);
	//	printf("%f\n", worldY);

	//}
}



void Game::update()
{


	this->playgame();
	this->updateMousePositions();
	
	this->enemy_walk();
	this->loadMap();

	this->updateGUI();

	this->update_enemy();

	//this->update_block();
	this->update_dirtBlock();
	this->update_stoneBlock();

	this->update_fireabove();
	this->update_fire();
	this->update_firer();
	this->update_fireball();
	this->update_firebeam();
	
	this->updateOp();

	this->update_boss();
	this->boss_attack();
	this->player_attack();

	//this->updateBlock();

	this->updatePlayer();

	this->updateCollision();

	this->updateWorld();

	this->update_Item();
	//this->enemy_view();
}

void Game::renderItem()
{
	this->shield->render(*this->window);
	this->potion->render(*this->window);
}

void Game::renderOp()
{
	this->opening->render(*this->window);
}

void Game::renderBlock()
{

	for (auto* dirtblock : this->dirtBlocks)
	{
		dirtblock->render(*this->window);
	}
	for (auto* stoneblock : this->stoneBlocks)
	{
		stoneblock->render(*this->window);
	}
}

void Game::renderGUI()
{
	if (play == true)
	{
		this->window->draw(shield_s);
		this->window->draw(health_s);
		this->window->draw(scoreText);
		this->window->draw(healthText);
		this->window->draw(auraText);
	}


	if (level == 4 && this->player->getPosition().y >= 880)
	{
		this->window->draw(bossHpBar);
		this->window->draw(BossHp);
	}


}


void Game::renderPlayer()
{

	//this->orc_enemy->render_orc(*this->window);
		for (auto* enemy : this->orc_enemies)
	{
		enemy->render_orc(*this->window);
	}
		for (auto* coin : this->coins)
		{
			coin->render(*this->window);
		}
		for (auto* fire : this->fires)
		{
			fire->render(*this->window);
		}
		for (auto* firer : this->firers)
		{
			firer->render(*this->window);
		}
		for (auto* fireball : this->fireballs)
		{
			fireball->render(*this->window);
		}
		for (auto* firebeam : this->firebeams)
		{
			firebeam->render(*this->window);
		}
		if (this->level != 4)
		{
			
			this->fire_above->render(*this->window);
		}

	this->boss->render_boss(*this->window);
	this->player->render(*this->window);

}

void Game::renderWorld()
{
	//for (auto* worldbackground : this->worldbackgrounds)
	//{
	//	worldbackground->render(*this->window);
	//}

	this->window->draw(this->worldBackground);

}

void Game::render()
{

	
	//draw world

	this->renderWorld();
	//this->showBlock();
	this->createBlock();

	this->renderBlock();
	if (this->player->getPosition().y <= 1000.f && this->level == 1)
	{
		this->window->draw(this->op_Background); 
	}

	this->renderItem();
	this->renderPlayer();
	this->renderOp();
	//sf::Vector2f(0.0f, 0.0f), sf::Vector2f(650.f, 950.f));
	this->view.setSize(650.f,950.f);
	if (health<=0 ||  bossHplose <= 0)
	{
		this->view.setCenter(650.f / 2, this->window->getSize().y/2);
	}
	else if (level == 4)
	{
		this->view.setCenter(650.f / 2, this->player->getPosition().y-300.f);
	}
	else
	{
		this->view.setCenter(650.f / 2, this->player->getPosition().y);
	}
	this->window->setView(view);
	this->MenuGUI();
	this->renderGUI();
	
}

const sf::RenderWindow& Game::getWindow() const
{
	return *this->window;
}
