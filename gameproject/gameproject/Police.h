#pragma once
#include "Bullet.h"

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

    float speedX;
    float speedY;
    float scrollingSpeed;

    void initVariables();
   

public:
    Police(sf::Texture* texture, float pos_x, float pos_y);
    ~Police();
    
    const sf::FloatRect getBounds() const;
    const int& getPoints() const; //ile punktow da mi kazdy wrog
    const int& getDamage() const;
    
    //funkcje
    void update();
    void render(sf::RenderTarget* target);


};

