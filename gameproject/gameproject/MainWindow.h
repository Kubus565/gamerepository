#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Game.h"
#include <string>
class MainWindow
{
private:
	//okno
	sf::RenderWindow* window;

public:
	MainWindow(std::string MainWindow);
	sf::RenderWindow* getWindow();
};

