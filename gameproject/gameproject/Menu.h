#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Game.h"
class Menu //: public Game
{
private:
	sf::RenderWindow* window;

	sf::Font font;
	sf::Text menuText;

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
		void renderVision();
		void render();
	
};

