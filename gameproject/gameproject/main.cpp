//pliki gry to: main.cpp Game.cpp Game.h

//relikty: main1 testyzpasem trstdestruktora

//jutro GAME3/PART 10
#include <time.h>
#include "Game.h"


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Game game;
	game.run();


	return 0;
}