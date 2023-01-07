#include "Menu.h"
#include <iostream>

////void Menu::initWindow()
//{
//	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "MENU", sf::Style::Close | sf::Style::Titlebar);
//	//this->window->setFramerateLimit(144);
//	this->window->setFramerateLimit(60);
//	this->window->setVerticalSyncEnabled(false);
//}

void Menu::initGUI()
{
	//ladowanie czcionek
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
		std::cout << "ERROR::GAME::Nie udalo sie zaladowac czcionki" << " \n";

	this->menuText.setFont(this->font);
	this->menuText.setCharacterSize(100); //wielkosc czcionki
	this->menuText.setFillColor(sf::Color::Red); //kolor czcionki
	this->menuText.setString(" MENU MENU MENU MENU");
	this->menuText.setPosition(300.f, 300.f); // napis na srodku

}
void Menu::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("textures/background1.png"))
		std::cout << "ERROR::GAMECPP::Blad ladowania tla" << "\n";
	this->worldBachground.setTexture(this->worldBackgroundTex);
}
Menu::Menu()
{
	MainWindow menu("menju");
	this->window = menu.getWindow();
	
	this->initGUI();
	this->initWorld();
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

void Menu::updateGUI()
{
	std::stringstream ss; //liczba punktow
	ss << "Punkty: " << 69;
	//this->menuText.setString(ss.str());

}

void Menu::update()
{
	this->updateInput();
	this->updateGUI();
	
}

void Menu::renderGUI()
{
	this->window->draw(this->menuText);
	
}
void Menu::renderWorld()
{
	this->window->draw(this->worldBachground);

}

void Menu::render()
{
	this->window->clear();
	
	this->renderWorld();
	this->renderGUI();
	this->window->draw(this->menuText);
	//this->window->draw(this->worldBachground);
	
	this->window->display();
}


