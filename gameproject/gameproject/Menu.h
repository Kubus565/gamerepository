#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Game.h"
class Menu
{
private:
	sf::RenderWindow* window;

	sf::Font font;
	sf::Text menuText[4];

	//swiat
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBachground;

		//funkcje prywatne
		void initVision();
public:
		 Menu();
		~Menu();
				
		void run();
				
		void updatePollEvent();
		void updateInput();
		void updateVision();

		void update();
		void render();
	
};

