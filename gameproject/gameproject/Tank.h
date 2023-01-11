#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Tank
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;

	float shootCooldown;
	float shootCooldownMax;

	int hp;
	int hpMax;

	//tu nie moze byc  "="

	//funkcje prywatne
	void createVariables();
	void createTexture();
	void createSprite();

public:
	Tank(const float x, const float y, int hpTank);
	~Tank();

	//dostep
	sf::Vector2f getPos();
	sf::FloatRect getBounds();
	int getHp(); //hp
	int getHpMax();

	//modyfikacje
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);  //do hp
	void loseHp(const int value);

	//funkcje
	void move(const float dirX, const float dirY);
	bool canShoot();

	void updateShoot();
	void update();
	void render(sf::RenderTarget& target);

};

