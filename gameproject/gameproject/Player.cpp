#include "Player.h"

void Player::initTexture()
{
	//ladowanie tekstury


}

void Player::initSprite()
{
	//³¹czenie tekstury se spritem
	this->sprite.setTexture(this->texture);

}

Player::Player()
{
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}

void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
