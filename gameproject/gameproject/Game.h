#pragma once

#include <map>
#include <string>
#include <sstream>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Police.h"
#include "Line.h"

class Game
{
private:
	//okno
	sf::RenderWindow *window;
	//zasoby
	
	std::map<std::string, sf::Texture*> textures; 
	//para klucz-warto��, gdzie kluczem jest nazwa tekstury, a warto�ci� jest wska�nik na obiekt Texture.
	std::vector<Bullet*> bullets;
	// <Bullet*> - optymalizacja, jest mo�liwo�� dynamicznego dodawania i usuwania element�w oraz automatyczne dostosowywanie rozmiaru do liczby element�w
	
	//interface
	sf::Font font;
	sf::Text pointText;

	sf::Text gameOverText;//over
	sf::Text helpText;

	bool isf1press;

	//swiat
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBachground;

	//system
	unsigned points;

	//gracz
	Player* player;

	//gracz GUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//wrogowie
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

	//police
	float policeSpawnTimer;
	float policeSpawnTimerMax;
	std::vector<Police*> polices;

	//Linie
	float lineSpawnTimer;
	float lineSpawnTimerMax;
	std::vector<Line*> lines;


	
	//funkcje prywatne
	void initWindow();		//przypisanie wartosci poczatkowych
	void initTextures();
	void initGUI();
	void initWorld();
	void initSystems();
	void initPlayer();
	void initEnemies(); 
	void initPolice(); //do police
	void initLine(); //do lini
	
	
	


public:
	Game();
	~Game();

	const bool& getHelp() const;

	void run();
	
	void keyListener();

	void updatePollEvent();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullets();
	void updateEnemies();
	void updatePolice(); //do police
	void updateLine(); 
	void updateCombat();
	void update();
	void renderGUI();
	void renderWorld();
	void render();
};

