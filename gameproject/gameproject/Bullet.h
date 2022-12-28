#pragma once
//#ifndef BULLET_H 
//#define BULLET_H
// spos�b na unikni�cie problem�w zwi�zanych z kilkukrotnym do��czeniem pliku nag��wkowego
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Bullet
{
private:
	sf::Sprite shape;
	//sf::Texture* texture;  //wskaznik, zeby szybciej ladowac wiele pociskow

	sf::Vector2f direction;
	float movementSpeed;

public:
	Bullet();
	Bullet(sf::Texture* texture,float pos_x, float pos_y, float dir_X, float dir_Y, float movement_speed);
	~Bullet();

	//dostep
	const sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget * target);

};

