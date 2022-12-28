#include "Game.h"
using namespace sf;
//Funkcje prywatne
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gra", sf::Style::Close | sf::Style::Titlebar);
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

}

void Game::render()
{
	this->window->clear();

	this->window->display();
}
