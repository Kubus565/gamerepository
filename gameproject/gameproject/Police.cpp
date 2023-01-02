#include "Police.h"

void Police::initVariables()
{
	
	this->pointCount = rand() % 8 + 3; //od 0 do 7 +3 tj. od 3 do 10
	this->speed = static_cast<float>(this->pointCount / 4);
	this->hpMax = 10;
	this->hp = this->hpMax;
	this->damage = 1;
	this->points = 5;
}

Police::Police(sf::Texture* texture, float pos_x, float pos_y)
{
	this->initVariables();
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(pos_x, pos_y);

}

Police::~Police()
{
}

const sf::FloatRect Police::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Police::getPoints() const
{
	return this->points;
}

const int& Police::getDamage() const
{
	return this->damage;
}

void Police::update()
{
	//ruch
	//this->sprite.move(this->movementSpeed * this->direction);
	this->sprite.move(0.f, this->speed); //predkosc opadania
}

void Police::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
