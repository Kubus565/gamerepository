#include "Police.h"

void Police::initVariables()
{
	
	//this->pointCount = rand() % 4 + 1; //od 0 do 3 +1 
	this->rotationPointCount = rand() % 3 + 1; //wybor kierunku
	this->scrollingSpeed = 1;

	this->hpMax = 10;
	this->hp = this->hpMax;
	this->damage = 1;
	this->points = 100;
}

Police::Police(sf::Texture* texture, float pos_x, float pos_y)
{
	this->initVariables();
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(pos_x, pos_y);
	//this->sprite.setScale(1.f, -1.f);

	switch (rotationPointCount)
	{
	case 1:
		this->sprite.setRotation(90);
		this->speedX = rand() % 3;
		this->speedY = this->scrollingSpeed;

		break;
	case 2:
		this->sprite.setRotation(180);
		this->speedX = 0;
		this->speedY = this->scrollingSpeed + (rand() % 3);
		break;
	case 3:
		this->sprite.setRotation(270);
		this->speedX = -(rand() % 3);
		this->speedY = this->scrollingSpeed;
		break;
	default:
		std::cout << "blad w police >> switch case";
		break;
	}
	
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
	this->sprite.move(this->speedX,  this->speedY); //predkosc opadania
}

void Police::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
