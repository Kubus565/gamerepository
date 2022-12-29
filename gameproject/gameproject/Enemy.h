#ifndef ENEMY_H 
#define ENEMY_H
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	unsigned pointCount;
	sf::CircleShape shape;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initVariables();
	void initShape();
public:
	Enemy(float pos_x, float pos_y);

	~Enemy();
	 
	//dostep, stworzenie nowych funkcji
	const sf::FloatRect getBounds() const;
	const int& getPoints() const; //ile punktow da mi kazdy wrog
	const int& getDamage() const;
	
	//funkcje
	void update();
	void render(sf::RenderTarget* target);


};
#endif
