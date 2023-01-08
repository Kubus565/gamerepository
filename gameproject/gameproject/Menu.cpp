#include "Menu.h"
#include <iostream>
void Menu::initVision()
{
	//ladowanie czcionek
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
		std::cout << "ERROR::GAME::Nie udalo sie zaladowac czcionki" << " \n";

	if (!this->worldBackgroundTex.loadFromFile("textures/background2.png"))
		std::cout << "ERROR::GAMECPP::Blad ladowania tla" << "\n";
	this->worldBachground.setTexture(this->worldBackgroundTex);
	//this->worldBachground.setColor(sf::Color(106, 166, 62));

	this->menuText[0].setFont(this->font); 
	this->menuText[0].setCharacterSize(100); //wielkosc czcionki
	this->menuText[0].setFillColor(sf::Color::Blue); //kolor czcionki
	this->menuText[0].setOutlineThickness(2.f); // obramowania
	this->menuText[0].setOutlineColor(sf::Color::White); 
	this->menuText[0].setString("Police pulp!");
	this->menuText[0].setPosition(80.f, 40.f); 

	this->menuText[1].setFont(this->font);
	this->menuText[1].setCharacterSize(50); //wielkosc czcionki
	this->menuText[1].setFillColor(sf::Color::Blue); //kolor czcionki
	this->menuText[1].setString("1 New Game");
	this->menuText[1].setPosition(80.f, 250.f);

	this->menuText[2].setFont(this->font);
	this->menuText[2].setCharacterSize(50); //wielkosc czcionki
	this->menuText[2].setFillColor(sf::Color::Blue); //kolor czcionki
	this->menuText[2].setString("2 Load last game");
	this->menuText[2].setPosition(80.f, 330.f);

	this->menuText[3].setFont(this->font);
	this->menuText[3].setCharacterSize(50); //wielkosc czcionki
	this->menuText[3].setFillColor(sf::Color::Blue); //kolor czcionki
	this->menuText[3].setString("3 instruction and control");
	this->menuText[3].setPosition(80.f, 410.f);

	
	
}
Menu::Menu()
{
	MainWindow menu("Menu");
	this->window = menu.getWindow();
	
	this->initVision();
}

Menu::~Menu()
{
	delete this->window;
}

//tu int
void Menu::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvent();	//over
		
		//if (this->player->getHp() > 0 && !isf1press)	//over
			this->update();

		this->render();
	}
	//return this->level
}

void Menu::updatePollEvent()
{
	sf::Event e2;
	while (this->window->pollEvent(e2))
	{
		//mozna to w jednym ifie TODO
		if (e2.Event::type == sf::Event::Closed)
			this->window->close();
		if (e2.Event::KeyPressed && e2.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Menu::updateInput()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i position = sf::Mouse::getPosition();
		std::cout << position.x<< " " << position.y << "\n";

	}
	
}

void Menu::updateVision()
{
	std::stringstream ss; //liczba punktow
	ss << "Punkty: " << 69;
	//this->menuText.setString(ss.str());

}

void Menu::update()
{
	this->updateInput();
	this->updateVision();
	
}
void Menu::render()
{
	this->window->clear();
	
	//this->renderVision();
	this->window->draw(this->worldBachground);
	this->window->draw(this->menuText[0]);
	this->window->draw(this->menuText[1]);
	this->window->draw(this->menuText[2]);
	this->window->draw(this->menuText[3]);
	
	this->window->display();
}


