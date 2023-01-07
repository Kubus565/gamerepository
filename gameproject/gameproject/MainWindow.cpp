#include "MainWindow.h"

MainWindow::MainWindow(std::string nameWindow)
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), nameWindow, sf::Style::Close | sf::Style::Titlebar);
	//this->window->setFramerateLimit(144);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

sf::RenderWindow* MainWindow::getWindow()
{
	return this->window;
}
