#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Game.h"
#include "Instruction.h"
class Menu
{
private:
	sf::RenderWindow* window;

	sf::Font font;
	sf::Text menuText[4];

	struct config
	{
		//wartosci poczatkowe do wczytania
		int points = 69;
		//int level = 1;
		float spawnlevel = 0.5f; // 0.5f do 2.5f
		int hp = 100; // max to 100

	};

	config  conf;
	//swiat
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBachground;

		//funkcje prywatne
		void initVision();
public:
		 Menu();
		~Menu();
				
		//void run();
		int run();
	
	
};

