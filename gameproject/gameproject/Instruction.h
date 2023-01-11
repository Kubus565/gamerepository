#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Game.h"
class Instruction
{
private:
	sf::RenderWindow* window;

	sf::Font font;
	sf::Text instructionText;
	sf::Text backText;

	//swiat
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBachground;

	//funkcje prywatne
	void createVision();
public:
	Instruction();
	~Instruction();
	void run();
};

