#pragma once
#include <fstream>
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

	//struct startConfig //TODO zrobic z tych struktur tablice
	//{
	//	//wartosci poczatkowe do wczytania
	//	float spawnlevel = 0.5f; // 0.5f do 2.5f
	//	int points = 100;
	//	int hp = 100; // max to 100

	//};
	struct Configuration
	{
		//miejsce na zmienne z pliku
		float spawnlevel; // 0.5f do 2.5f
		int points;
		int hp; // max to 100

	};
	Configuration  config[2];
	//config[0].points = 100;


	//startConfig startConfig;

	//swiat
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBachground;

		//funkcje prywatne
		void initVision();
public:
		 Menu();
		~Menu();
				
		void reading();

		void fileWritting();
		void fileReading();
		bool isFileEmpty(const char* file_name);
		
		//void run();
		int run();
	
	
};

