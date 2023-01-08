#include "Line.h"

void Line::initVariables()
{
	this->scrollingSpeed = 3.f;//1
	//this->scrollingSpeed = level_;//1
}

//Line::Line(sf::Texture* texture, float pos_x, float pos_y)
Line::Line(float pos_x, float pos_y, int level_)
{
	this->initVariables();
	
	//this->scrollingSpeed = (float)level_;
	this->rectangle.setSize(sf::Vector2f(5.f, 25.f));
	this->rectangle.setFillColor(sf::Color(233, 244, 255));
	this->rectangle.setPosition(sf::Vector2f(pos_x, pos_y));
}

Line::~Line()
{
}

const sf::FloatRect Line::getBounds() const
{
	return this->rectangle.getGlobalBounds();
}

void Line::update()
{
	this->rectangle.move(0.f, this->scrollingSpeed); //predkosc opadania
}

void Line::render(sf::RenderTarget* target)
{
	target->draw(this->rectangle);
}
