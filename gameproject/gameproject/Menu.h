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

	sf::Text menuText;
	sf::Font font;

	//swiat
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBachground;

		//funkcje prywatne
		//void initWindow();		//przypisanie wartosci poczatkowych
		void initGUI();
		void initWorld();
public:
		 Menu();
		~Menu();

		
		void run();

		
		void updatePollEvent();
		void updateInput();
		void updateGUI();

		void update();
		void renderGUI();
		void render();
	
};

