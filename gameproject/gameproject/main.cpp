//pliki gry to: main.cpp Game.cpp Game.h

//relikty: main1 testyzpasem trstdestruktora

#include <time.h>
#include "Game.h"
#include "Menu.h"
#include "Instruction.h"

//struct config
//{
//	//wartosci poczatkowe do wczytania
//	int points = 666;
//	int level = 1;
//	float spawnlevel = 0.5f; // 0.5f do 2.5f
//	int hp = 100; // max to 100
//
//};


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	//config  conf;

	//Menu menu;
	//Instruction inst;
	//Game game(conf.spawnlevel, conf.points, conf.hp);
	//menu.run();
	//inst.run();
	//game.run();
	
	Menu menu;
	while (true)
	{
		menu.run();
	}

	/*if (menu.run() == 1)
	{
		Game game(conf.spawnlevel, conf.points, conf.hp);
		game.run();

	}*/
	//if (menu.run() == 3)
	//{
	//	/*Instruction inst;
	//	if (inst.run() == true)
	//		menu.run();*/
	//}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		Game game(conf.spawnlevel, conf.points, conf.hp);
		game.run();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		Instruction inst;
		inst.run();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			
		}
	}*/

	
	
	


	return 0;
}