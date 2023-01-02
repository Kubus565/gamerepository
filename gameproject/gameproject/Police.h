#pragma once
#include "Bullet.h"
class Police :
    public Bullet
{
private:
    unsigned pointCount;
    sf::Sprite sprite;
    sf::Texture texture;
    int hp;
    int hpMax;
    int damage;
    int points;

    float speed;

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

