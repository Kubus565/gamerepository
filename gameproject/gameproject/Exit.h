#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Game.h"
class Exit
{
private:
	sf::RenderWindow* windowExit;

	sf::Font font;
	sf::Text exitText;
	sf::Text choiceText[3];

	//swiat
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBachground;

	//funkcje prywatne
	void createVision();
public:
	Exit();
	~Exit();


	int run();

};

