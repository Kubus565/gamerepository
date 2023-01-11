#pragma once
//#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Police 
{
private:
    unsigned direction;
    sf::Sprite sprite;
    sf::Texture texture;
    int hp;
    int hpMax;
    int damage;
    int points;

    float speedX; // predkosc kazdego pojedynczego auta
    float speedY;
    float scrollingSpeed;

    void createVariables();
   

public:
    Police(sf::Texture* texture, float pos_x, float pos_y, int level_);
    ~Police();
    
    const sf::FloatRect getBounds() const;
    const int& getPoints() const; //ile punktow da mi kazdy wrog
    const int& getDamage() const;
    
    //funkcje
    void update();
    void updateStop();
    void render(sf::RenderTarget* target);


};

