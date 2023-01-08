//pliki gry to: main.cpp Game.cpp Game.h

//relikty: main1 testyzpasem trstdestruktora

#include <time.h>
#include "Game.h"
#include "Menu.h"
#include "Instruction.h"

struct config
{
	//wartosci poczatkowe do wczytania
	int points = 666;
	int level = 1;
	float spawnlevel = 0.5f; // 0.5f do 2.5f
	int hp = 100; // max to 100

};


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	config  conf;

	Menu menu;
	menu.run();

	Instruction inst;
	inst.run();
	
	Game game(conf.spawnlevel, conf.points, conf.hp);
	game.run();


	return 0;
}