//pliki gry to: main.cpp Game.cpp Game.h

//relikty: main1 testyzpasem trstdestruktora

#include <time.h>
#include "Game.h"
#include "Menu.h"
#include "Instruction.h"

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	Menu menu;
	while (true)
	{
		menu.run();
	}

	return 0;
}