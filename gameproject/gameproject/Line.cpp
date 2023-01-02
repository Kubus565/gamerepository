#include "Line.h"

void Line::initVariables()
{
	this->scrollingSpeed = 1;
}

Line::Line(sf::Texture* texture, float pos_x, float pos_y)
{
	this->initVariables();
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(pos_x, pos_y);
}

Line::~Line()
{
}

const sf::FloatRect Line::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Line::update()
{
	this->sprite.move(0.f, this->scrollingSpeed); //predkosc opadania
}

void Line::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
