#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Game
{
private:
	sf::RenderWindow *window;

	void initWindow();

public:
	Game();
	~Game();

	void run();
	
	void update();
	void render();



};

