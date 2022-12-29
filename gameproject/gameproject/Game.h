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
	std::map<std::string, sf::Texture*> textures; //para klucz-wartoœæ, gdzie kluczem jest nazwa tekstury, a wartoœci¹ jest wskaŸnik na obiekt Texture.
	std::vector<Bullet*> bullets; // <Bullet*> - optymalizacja, jest mo¿liwoœæ dynamicznego dodawania i usuwania elementów oraz automatyczne dostosowywanie rozmiaru do liczby elementów
	
	//interface
	sf::Font font;
	sf::Text pointText;

	//gracz
	Player* player;

	//wrogowie
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	
	//funkcje prywatne
	void initWindow();
	void initTextures();
	void initGUI();
	void initPlayer();
	void initEnemies();

public:
	Game();
	~Game();

	void run();
	
	void updatePollEvent();
	void updateInput();
	void updateGUI();
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void update();
	void renderGUI();
	void render();



};

