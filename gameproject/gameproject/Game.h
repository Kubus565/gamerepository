#pragma once

#include <map>
#include "Player.h"
#include "Bullet.h"

class Game
{
private:
	//okno
	sf::RenderWindow *window;
	//zasoby
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets; // <Bullet*> - optymalizacja
	
	//gracz
	Player* player;
	//funkcje prywatne
	void initWindow();
	void initTextures();
	void initPlayer();

public:
	Game();
	~Game();

	void run();
	
	void updatePollEvent();
	void updateInput();
	void updateBullets();
	void update();
	void render();



};

