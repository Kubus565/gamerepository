#pragma once

#include <map>
#include <string>
#include <sstream>
#include "Player.h"
#include "Bullet.h"
//#include "Enemy.h"
#include "Police.h"
#include "Line.h"
#include "MainWindow.h"

class Game
{
private:
	//okno
	sf::RenderWindow *window;
	//zasoby
	
	std::map<std::string, sf::Texture*> textures; 
	//para klucz-wartoœæ, gdzie kluczem jest nazwa tekstury, a wartoœci¹ jest wskaŸnik na obiekt Texture.
	std::vector<Bullet*> bullets;
	// <Bullet*> - optymalizacja, jest mo¿liwoœæ dynamicznego dodawania i usuwania elementów oraz automatyczne dostosowywanie rozmiaru do liczby elementów
	
	//interface
	sf::Font font;
	sf::Text pointText;
	sf::Text f1ToHelpText;
	sf::Text gameOverText;//over
	sf::Text helpText;

	bool isf1press;

	unsigned speed = 1;
	//swiat
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBachground;

	//system
	unsigned points;
	int hp;
	int level;

	//gracz
	Player* player;

	//gracz GUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//wrogowie
	//float spawnTimer;
	//float spawnTimerMax;
	//std::vector<Enemy*> enemies;

	//police
	float policeSpawnTimer;
	float policeSpawnTimerMax;
	std::vector<Police*> polices;

	//Linie
	float lineSpawnTimer;
	float lineSpawnTimerMax;
	std::vector<Line*> lines;


	
	//funkcje prywatne
	//void initWindow();		//przypisanie wartosci poczatkowych
	
	void initTextures();
	void initGUI();
	void initBackground();
	void initSystems();
	void initPlayer();
	//void initEnemies(); 
	void initPolice(); //do police
	void initLine(); //do lini
	void initHp(int hp);
	
	
	


public:
	Game(int level_, int points_, int hp);
	
	~Game();

	const bool& getHelp() const;
	const int& getStartHp() const;

	void run();
	
	void keyListener();

	void updatePollEvent();
	void updateInput();
	void updateGUI();
	//void updateBackground();
	void updateCollision();
	void updateBullets();
	//void updateEnemies();
	void updatePolice(); //do police
	void updateLine(); 
	void updateCombat();
	void update();
	void renderGUI();
	void renderBackground();
	void render();
};

