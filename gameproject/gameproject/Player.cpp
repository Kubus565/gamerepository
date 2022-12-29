#include "Player.h"


void Player::initVariables()
{
	//predkosc gracza
	this->movementSpeed = 10.f; //predkosc statku

	this->attackCooldownMax = 10.f;
	this->attackCooldown = this->attackCooldownMax;

	this->hpMax = 100;  //hp
	this->hp = this->hpMax;

}

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
	this->initVariables();
	
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

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}
const int& Player::getHp() const  //hp
{
	return this->hp;
}
const int& Player::getHpMax() const  //hp
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);

}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp) // hp
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;//end
	if (this->hp < 0)
		this->hp = 0;
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}



const bool Player::canAttack()
{
	if (this->attackCooldown >= this->attackCooldownMax)
	{
		this->attackCooldown = 0.f;
		return true;
	}
	
	return false;
}



void Player::updateAttack()
{
	if(this->attackCooldown < this->attackCooldownMax)
		this->attackCooldown += 0.5f;
}

void Player::update()
{
	this->updateAttack();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}


