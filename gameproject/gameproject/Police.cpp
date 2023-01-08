#include "Police.h"

void Police::initVariables()
{
	
	this->direction = rand() % 5 + 1; //wybor kierunku
	this->scrollingSpeed = 1;

	this->hpMax = 10;
	this->hp = this->hpMax;
	this->damage = 10;
	this->points = 100;
}

Police::Police(sf::Texture* texture, float pos_x, float pos_y, int level_)
{
	this->initVariables();
	//this->scrollingSpeed = (float)level_;
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(pos_x, pos_y);
	//this->sprite.setScale(1.f, -1.f);

	switch (direction)
	{
	
	
	case 1:
		this->sprite.setRotation(90);
		this->speedX = -(rand() % 2 + 1.f );
		this->speedY = this->scrollingSpeed;
		break;
	case 2:
		this->sprite.setRotation(270);
		this->speedX = rand() % 3 + 1.f;
		this->speedY = this->scrollingSpeed;
		break;
	case 3:
		this->speedX = 0;
		this->speedY = this->scrollingSpeed + (rand() % 3 + 1.f);
		break;
	case 4:
		this->speedX = 0;
		this->speedY = this->scrollingSpeed + (rand() % 2 + 1.f);
		break;
	case 5:
		this->speedX = 0;
		this->speedY = 3/2; //czasami wywala b³¹d
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

void Police::updateStop()
{
	this->sprite.move(0.f, this->scrollingSpeed);
	//std::cout << "S";
}

void Police::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
	//std::cout << "X";

}
