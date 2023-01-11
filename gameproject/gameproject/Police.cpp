#include "Police.h"

void Police::createVariables()
{
	this->direction = rand() % 5 + 1; //wybor kierunku
	this->scrollingSpeed = 1;

	this->hpMax = 10;
	this->hp = this->hpMax;
	this->damage = 10;
	this->points = 100;//punkty za zabojstwo policji
}

Police::Police(sf::Texture* texture, float pos_x, float pos_y, int level_)
{
	this->createVariables();
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(pos_x, pos_y);

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

int Police::getPoints()
{
	return this->points;
}

int Police::getDamage()
{
	return this->damage;
}

void Police::update()
{
	this->sprite.move(this->speedX,  this->speedY); //predkosc opadania
}

void Police::updateStop()
{
	this->sprite.move(0.f, this->scrollingSpeed);
	//std::cout << "S";
}

void Police::render(sf::RenderTarget* target) //wskaznik na cel renderowania
{
	target->draw(this->sprite);
	//std::cout << "X";

}
