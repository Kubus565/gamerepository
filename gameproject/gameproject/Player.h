#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	//funkcje prywatne
	void initTexture();
	void initSprite();


public:
	Player();

	~Player();

	void update();
	void render(sf::RenderTarget& target);

};

