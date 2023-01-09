#pragma once

#include <map>
#include <string>
#include <sstream>
#include "Player.h"
#include "Bullet.h"
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
	//para klucz-warto��, gdzie kluczem jest nazwa tekstury, a warto�ci� jest wska�nik na obiekt Texture.
	std::vector<Bullet*> bullets;
	// <Bullet*> - optymalizacja, jest mo�liwo�� dynamicznego dodawania i usuwania element�w oraz automatyczne dostosowywanie rozmiaru do liczby element�w
	
	//interface
	sf::Font font;
	sf::Text pointText;
	sf::Text levelText;
	sf::Text f1ToHelpText;
	sf::Text gameOverText;//over
	sf::Text helpText;

	bool isf1press;
	
	//bool changedPoints1000;
	//bool changedPoints2000;

	unsigned speed = 1;
	//swiat
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBachground;

	//system
	//unsigned points;
	int points;
	int hp;
	int level;
	float spawnlevel;

	//gracz
	Player* player;

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
	//void initWindow();		//przypisanie wartosci poczatkowych
	
	void initTextures();
	void initGUI();
	void initBackground();
	void initPlayer();
	void initPolice(); //do police
	void initLine(); //do lini
	
	
	


public:
	Game(float spawnlevel_, int points_, int hp);
	
	~Game();

	const bool& getHelp() const;
	//const bool& getChangedPoints1000() const;
	//const bool& getChangedPoints2000() const;
	const int& getStartHp() const;

	void run();
	
	void f1Listener();

	void updatePollEvent();
	void updateInput();
	void updateGUI();
	void updateCollision();
	void updateBullets();
	void updatePolice(); //do police
	void updateLine(); 
	void updateCombat();
	void update();
	void renderGUI();
	void renderBackground();
	void render();
};

