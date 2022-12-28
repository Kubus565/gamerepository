#include "Game.h"

//Funkcje prywatne
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gra", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);

}

Game::Game()
{
	this->initWindow();

}

Game::~Game()
{
	delete this->window;
}
//funkcje
void Game::run()
{
	while (this->window->isOpen())
	{
	this->update();
	this->render();
	}
}

void Game::update()
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

void Game::render()
{
	this->window->clear();

	this->window->display();
}
