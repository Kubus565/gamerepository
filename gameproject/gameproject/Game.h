#pragma once

#include <map>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game
{
private:
	//okno
	sf::RenderWindow *window;
	//zasoby
	std::map<std::string, sf::Texture*> textures; //para klucz-warto��, gdzie kluczem jest nazwa tekstury, a warto�ci� jest wska�nik na obiekt Texture.
	std::vector<Bullet*> bullets; // <Bullet*> - optymalizacja, jest mo�liwo�� dynamicznego dodawania i usuwania element�w oraz automatyczne dostosowywanie rozmiaru do liczby element�w
	
	//gracz
	Player* player;
	//wrogowie
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;
	//nie potrzebne juz Enemy* enemy;

	//funkcje prywatne
	void initWindow();
	void initTextures();
	void initPlayer();
	void initEnemies();

public:
	Game();
	~Game();

	void run();
	
	void updatePollEvent();
	void updateInput();
	void updateBullets();
	void updateEnemies();
	void update();
	void render();



};

