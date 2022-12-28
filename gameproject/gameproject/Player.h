#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;
	//tu nie moze byc  "="
	
	//funkcje prywatne
	void initTexture();
	void initSprite();


public:
	Player();
	~Player();

	//dostep
	const sf::Vector2f& getPos() const;

	//funkcje
	void move(const float dirX, const float dirY);
	void update();
	void render(sf::RenderTarget& target);

};

