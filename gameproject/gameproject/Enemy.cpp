#include "Enemy.h"


void Enemy::initVariables()
{
	this->pointCount = rand() % 8 + 3; //od 0 do 7 +3 tj. od 3 do 10
	this->type    = 0;
	this->speed = static_cast<float>(this->pointCount/4); //kiedys 3.f
	this->hpMax = static_cast<int>(this->pointCount); // kiedys 10
	this->hp = this->hpMax; //kiedys 0
	this->damage  = this->pointCount; // kiedys 1
	this->points  = this->pointCount; // kiedys 5
}
void Enemy::initShape()
{
	this->shape.setRadius(this->pointCount * 8); //wielkosc przeciwnika
	this->shape.setPointCount(this->pointCount);
	this->shape.setFillColor(sf::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255));
}

Enemy::Enemy(float pos_x, float pos_y)
{
	this->initVariables();
	this->initShape();

	this->shape.setPosition(pos_x, pos_y);
}

Enemy::~Enemy()
{

}
//dostep
const sf::FloatRect Enemy::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int& Enemy::getPoints() const
{
	return this->points;
}

//funkcje
void Enemy::update()
{
	this->shape.move(0.f, this->speed); //predkosc opadania wrogow
	// jak zmienic stala w zmienna INFO
}

void Enemy::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}


