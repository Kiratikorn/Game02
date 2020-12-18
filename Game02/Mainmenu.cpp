#include "Mainmenu.h"

Mainmenu::Mainmenu(float width, float height)
{
	this->font.loadFromFile("Font/CRIT RACE.ttf");
	
	this->HowtoTex.loadFromFile("Pic/howto.png");
	this->Howto.setTexture(this->HowtoTex);
	this->scorePageWinTex.loadFromFile("Pic/scorepagewin.png");
	this->scorePageWin.setTexture(this->scorePageWinTex);
	this->menuScoreTex.loadFromFile("Pic/scorepage.png");
	this->menuScore.setTexture(this->menuScoreTex);
	
	this->scoreText.setFont(this->font);
	this->scoreText.setCharacterSize(60);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setOutlineColor(sf::Color::Black);
	this->scoreText.setOutlineThickness(2.f);
	this->scoreText.setPosition(120.f, 350.f);

	this->NameText.setFont(this->font);
	this->NameText.setCharacterSize(40);
	this->NameText.setFillColor(sf::Color::White);
	this->NameText.setOutlineColor(sf::Color::Black);
	this->NameText.setOutlineThickness(2.f);
	this->NameText.setString("63010086 Kiratikorn Phlappla");
	this->NameText.setPosition(80.f, 0.f);


	this->menuTex.loadFromFile("Pic/Menu_display.png");
	this->menu_s.setTexture(this->menuTex);
	this->menu_s.setPosition(0.f, 705.f);

	this->highscoreTex.loadFromFile("Pic/highscore_1.png");
	this->highscore_s.setTexture(this->highscoreTex);
	this->highscore_s.setScale(1.f, 1.f);
	this->button[0].setSize(sf::Vector2f(70.f, 68.f));
	this->button[0].setPosition(58.f, 793.f);


	this->button[1].setSize(sf::Vector2f(70.f, 68.f));
	this->button[1].setPosition(299.f, 793.f);

	this->button[2].setSize(sf::Vector2f(70.f, 68.f));
	this->button[2].setPosition(532.f, 793.f);

	//back_highscore
	this->button[3].setSize(sf::Vector2f(160.f, 60.f));
	this->button[3].setPosition(220.f, 700.f);
	
	//Howto
	this->HowtoText.setFont(this->font);
	this->HowtoText.setCharacterSize(30);
	this->HowtoText.setFillColor(sf::Color::White);
	this->HowtoText.setOutlineColor(sf::Color::Black);
	this->HowtoText.setOutlineThickness(2.f);
	this->HowtoText.setString("How to play");
	this->HowtoText.setPosition(250.f, 730.f);

	this->backText.setFont(this->font);
	this->backText.setCharacterSize(30);
	this->backText.setFillColor(sf::Color::White);
	this->backText.setOutlineColor(sf::Color::Black);
	this->backText.setOutlineThickness(2.f);
	this->backText.setString("Back");
	this->backText.setPosition(10.f, 730.f);

	//end
	this->EndText.setFont(this->font);
	this->EndText.setCharacterSize(30);
	this->EndText.setFillColor(sf::Color::White);
	this->EndText.setOutlineColor(sf::Color::Black);
	this->EndText.setOutlineThickness(2.f);
	this->EndText.setString("Submit Score");
	this->EndText.setPosition(250.f, 700.f);
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
	return this->button[3].getGlobalBounds();
}

const sf::FloatRect Mainmenu::getBounds_4() const
{
	return this->EndText.getGlobalBounds();
}

const sf::FloatRect Mainmenu::getBounds_5() const
{
	return this->HowtoText.getGlobalBounds();
}

const sf::FloatRect Mainmenu::getBounds_6() const
{
	return this->backText.getGlobalBounds();
}

void Mainmenu::render_Menu(sf::RenderWindow& target)
{
	if (playMenu == 1)
	{
		printf("State1\n");
		target.draw(this->menu_s);
		target.draw(this->HowtoText);
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
		//target.draw(this->button[3]);
		//target.draw(this->highscore_s);
	}
	if (playMenu == 3)
	{
		target.draw(this->menuScore);
		target.draw(this->scoreText);
		target.draw(this->EndText);
		//target.draw(this->highscore_s);
	}
	if (playMenu == 4)
	{
		target.draw(this->scorePageWin);
		target.draw(this->scoreText);
		target.draw(this->EndText);
	}
	if (playMenu == 6)
	{
		target.draw(this->Howto);
		target.draw(this->backText);
	}

}
