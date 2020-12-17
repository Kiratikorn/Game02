#include "Mainmenu.h"

Mainmenu::Mainmenu(float width, float height)
{
	this->font.loadFromFile("Font/CRIT RACE.ttf");
	
	this->scoreText.setFont(this->font);
	this->scoreText.setCharacterSize(60);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setOutlineColor(sf::Color::Black);
	this->scoreText.setOutlineThickness(2.f);
	this->scoreText.setPosition(100.f, 400.f);

	this->NameText.setFont(this->font);
	this->NameText.setCharacterSize(40);
	this->NameText.setFillColor(sf::Color::White);
	this->NameText.setOutlineColor(sf::Color::Black);
	this->NameText.setOutlineThickness(2.f);
	this->NameText.setString("63010086 Kiratikorn Phlappla");
	this->NameText.setPosition(80.f, 0.f);

	if (this->playMenu == 1)
		this->menuTex.loadFromFile("Pic/Menu_display.png");
	else
		this->menuTex.loadFromFile("Pic/Highscore.png");
	this->menu_s.setTexture(this->menuTex);
	this->menu_s.setPosition(0.f, 705.f);

	this->highscoreTex.loadFromFile("Pic/Highscore.png");
	this->highscore_s.setTexture(this->highscoreTex);
	this->highscore_s.setScale(1.2f, 1.2f);
	this->button[0].setSize(sf::Vector2f(70.f, 68.f));
	this->button[0].setPosition(58.f, 793.f);


	this->button[1].setSize(sf::Vector2f(70.f, 68.f));
	this->button[1].setPosition(299.f, 793.f);

	this->button[2].setSize(sf::Vector2f(70.f, 68.f));
	this->button[2].setPosition(532.f, 793.f);

	this->button_high.setSize(sf::Vector2f(70.f, 68.f));
	this->button_high.setPosition(58.f, 793.f);
}

Mainmenu::~Mainmenu()
{
}

void Mainmenu::update_Menu()
{
	this->Nameupdate();
}

void Mainmenu::Nameupdate()
{
	//this->NameText.setString("63010086 Kiratikorn Phlappla");
	//this->NameText.setString(NameNum.str());
}

void Mainmenu::buttoncheck(const int button)
{
	for (int i = 0; i < MAX_BUTTON; i++) {
		if (button == i) {
			selectedITEMindex = button;
		}

	}
}
const sf::FloatRect Mainmenu::getBounds_0() const
{
	return this->button[0].getGlobalBounds();
}
const sf::FloatRect Mainmenu::getBounds_1() const
{
	return this->button[1].getGlobalBounds();
}

const sf::FloatRect Mainmenu::getBounds_2() const
{
	return this->button[2].getGlobalBounds();
}

const sf::FloatRect Mainmenu::getBounds_3() const
{
	return sf::FloatRect();
}

void Mainmenu::render_Menu(sf::RenderWindow& target)
{
	if (playMenu == 1)
	{
		printf("State1\n");
		target.draw(this->menu_s);
		
		target.draw(this->NameText);
		//for (int i = 0; i < MAX_BUTTON; i++)
		//{
		//	target.draw(button[i]);
		//}
	}
	if (playMenu == 2 )
	{
		printf("State2\n");
		target.draw(this->highscore_s);

		//target.draw(this->highscore_s);
	}
	if (playMenu == 3)
	{
		target.draw(this->scoreText);

		//target.draw(this->highscore_s);
	}

}
