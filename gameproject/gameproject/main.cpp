//pliki gry to: main.cpp Game.cpp Game.h

//relikty: main1 testyzpasem trstdestruktora

#include <time.h>
#include "Game.h"
#include "Menu.h"

struct config
{
	int points = 0;
	int speed = 1;
	int level = 1;
	int hp = 100;

};


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	config  c1;

	Menu menu;
	//int config = menu.run();
	
	Game game(c1.level, c1.points, c1.hp);
	//game.run(config);
	game.run();


	return 0;
}