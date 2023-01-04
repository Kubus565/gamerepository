#include "Menu.h"
#include <iostream>

void Menu::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "MENU", sf::Style::Close | sf::Style::Titlebar);
	//this->window->setFramerateLimit(144);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Menu::initGUI()
{
	this->menuText.setFont(this->font);
	this->menuText.setCharacterSize(100); //wielkosc czcionki
	this->menuText.setFillColor(sf::Color::Red); //kolor czcionki
	this->menuText.setString(" MENU MENU MENU MENU");
	this->menuText.setPosition(300.f, 300.f); // napis na srodku

}
Menu::Menu()
{
	this->initWindow();
	this->initGUI();
}

Menu::~Menu()
{
	delete this->window;
}

void Menu::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvent();	//over
		
		//if (this->player->getHp() > 0 && !isf1press)	//over
			this->update();

		this->render();
	}
}

void Menu::updatePollEvent()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		//mozna to w jednym ifie TODO
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
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
	this->menuText.setString(ss.str());

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

void Menu::render()
{
	this->window->clear();
	this->renderGUI();
	this->window->display();
}


