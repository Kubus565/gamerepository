#include "Player.h"


void Player::initTexture()
{
	//ladowanie tekstury
	if (!this->texture.loadFromFile("Textures/ship.png"))
	{
		std::cout << "ERROR::player::initTexture::Nie mozna zaladowac tekstury" << std::endl;
	}
}

void Player::initSprite()
{
	//³¹czenie tekstury se spritem
	this->sprite.setTexture(this->texture);
	//zmiana rozmiaru sprita, jezeli - to odbicie lustrzane
	this->sprite.scale(0.1f, 0.1f);
}

Player::Player()
{
	//predkosc gracza
	this->movementSpeed = 10.f;
	
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
