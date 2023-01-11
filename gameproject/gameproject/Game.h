#pragma once

#include <map>
#include <string>
#include <sstream>
#include "Tank.h"
#include "Bullet.h"
#include "Police.h"
#include "Line.h"
#include "MainWindow.h"
#include "Menu.h"
#include "Exit.h"
#include <cstdlib>//¿eby dzia³a³ exit(0) przy pliku

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
	sf::Text levelText;
	sf::Text gameOverText;//over
	//do exit
	
	
	sf::Text f1ToHelpText;
	sf::Text helpText;
	sf::RectangleShape helpRect;

	bool isf1press;

	unsigned speed = 1;
	//swiat
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBachground;

	//system
	//unsigned points;
	float spawnlevel;
	int points;
	int hp;
	int level;

	//gracz
	Tank* tank;

	//gracz GUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	
	//police
	float policeSpawnTimer;
	float policeSpawnTimerMax;
	std::vector<Police*> polices;

	//Linie
	float lineSpawnTimer;
	float lineSpawnTimerMax;
	std::vector<Line*> lines;


	
	//funkcje prywatne
			//przypisanie wartosci poczatkowych
	
	void createTextures();
	void createVision();
	void createBackground();
	void createTank();
	void createPolice(); //do police
	void createLine(); //do lini
	

public:
	Game(float spawnlevel_, int points_, int hp);
	
	~Game();

	bool getHelp();
	int getStartHp();

	void run();
	
	
	void f1Listener();

	void updatePollEvent();
	void updateInput();
	void updateVision();
	void updateCollision();
	void updateBullets();
	void updatePolice(); 
	void updateLine(); 
	void updateHit();
	void update();
	void renderVision();
	
	void renderBackground();
	void render();

	void writting(float a, int b, int c);
	
};

