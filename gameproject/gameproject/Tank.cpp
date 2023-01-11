#include "Tank.h"
#include "Game.h"


void Tank::createVariables()
{
	//predkosc gracza
	this->movementSpeed = 10.f; //predkosc statku

	this->shootCooldownMax = 10.f;
	this->shootCooldown = this->shootCooldownMax;

	this->hpMax = 100;  //hp
	
}

void Tank::createTexture()
{
	//ladowanie tekstury
	if (!this->texture.loadFromFile("Textures/tank.png"))
	{
		std::cout << "ERROR::player::initTexture::Nie mozna zaladowac tekstury" << std::endl;
	}
}

void Tank::createSprite()
{
	//³¹czenie tekstury se spritem
	this->sprite.setTexture(this->texture);
	//zmiana rozmiaru sprita, jezeli - to odbicie lustrzane
	//this->sprite.scale(0.1f, 0.1f);
}

Tank::Tank(const float x, const float y, int hpPlayer)
{
	this->createVariables();
	this->hp = hpPlayer;
	this->createTexture();
	this->createSprite();
	this->sprite.setPosition(x, y);
}

Tank::~Tank()
{
}

const sf::Vector2f& Tank::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Tank::getBounds() const
{
	return this->sprite.getGlobalBounds();
}
const int& Tank::getHp() const  //hp
{
	return this->hp;
}
const int& Tank::getHpMax() const  //hp
{
	return this->hpMax;
}

void Tank::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);

}

void Tank::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Tank::setHp(const int hp) // hp
{
	this->hp = hp;
}

void Tank::loseHp(const int value)
{
	this->hp -= value;//end
	if (this->hp < 0)
		this->hp = 0;
}

void Tank::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Tank::canShoot()
{
	if (this->shootCooldown >= this->shootCooldownMax)
	{
		this->shootCooldown = 0.f;
		return true;
	}
	
	return false;
}

void Tank::updateShoot()
{
	if(this->shootCooldown < this->shootCooldownMax)
		this->shootCooldown += 0.5f;
}

void Tank::update()
{
	this->updateShoot();
}

void Tank::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}


