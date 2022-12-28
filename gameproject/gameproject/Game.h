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
	std::map<std::string, sf::Texture*> textures; //para klucz-wartoœæ, gdzie kluczem jest nazwa tekstury, a wartoœci¹ jest wskaŸnik na obiekt Texture.
	std::vector<Bullet*> bullets; // <Bullet*> - optymalizacja, jest mo¿liwoœæ dynamicznego dodawania i usuwania elementów oraz automatyczne dostosowywanie rozmiaru do liczby elementów
	
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

