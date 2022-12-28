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

	float attackCooldown;
	float attackCooldownMax;
	//tu nie moze byc  "="
	
	//funkcje prywatne
	void initVariables();
	void initTexture();
	void initSprite();


public:
	Player();
	~Player();

	//dostep
	const sf::Vector2f& getPos() const;

	//funkcje
	void move(const float dirX, const float dirY);
	const bool canAttack();

	void updateAttack();
	void update();
	void render(sf::RenderTarget& target);

};

