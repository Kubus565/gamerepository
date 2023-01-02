#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
class Line
{
private:
    
    sf::Sprite sprite;
    sf::Texture texture;

    float scrollingSpeed;

    void initVariables();


public:
    Line(sf::Texture* texture, float pos_x, float pos_y);
    ~Line();

    const sf::FloatRect getBounds() const;


    //funkcje
    void update();
    void render(sf::RenderTarget* target);


};

