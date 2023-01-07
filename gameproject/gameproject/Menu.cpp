#include "Menu.h"
#include <iostream>

////void Menu::initWindow()
//{
//	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "MENU", sf::Style::Close | sf::Style::Titlebar);
//	//this->window->setFramerateLimit(144);
//	this->window->setFramerateLimit(60);
//	this->window->setVerticalSyncEnabled(false);
//}

void Menu::initVision()
{
	//ladowanie czcionek
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
		std::cout << "ERROR::GAME::Nie udalo sie zaladowac czcionki" << " \n";

	this->menuText.setFont(this->font);
	this->menuText.setCharacterSize(100); //wielkosc czcionki
	this->menuText.setFillColor(sf::Color::Blue); //kolor czcionki
	this->menuText.setOutlineThickness(2.f);
	this->menuText.setOutlineColor(sf::Color::Red); 
	this->menuText.setString("Police grist!");
	this->menuText.setPosition(window->getSize().x/2, window->getSize().y / 2); // napis na srodku

	if (!this->worldBackgroundTex.loadFromFile("textures/background2.png"))
		std::cout << "ERROR::GAMECPP::Blad ladowania tla" << "\n";
	this->worldBachground.setTexture(this->worldBackgroundTex);
	//this->worldBachground.setColor(sf::Color(106, 166, 62));
	
}
Menu::Menu()
{
	MainWindow menu("menju");
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

void Menu::renderVision()
{
	this->window->draw(this->menuText);
	this->window->draw(this->worldBachground);
	
}


void Menu::render()
{
	this->window->clear();
	
	this->renderVision();
	this->window->draw(this->menuText);
	//this->window->draw(this->worldBachground);
	
	this->window->display();
}


