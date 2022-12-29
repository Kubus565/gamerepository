#ifndef ENEMY_H 
#define ENEMY_H
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::CircleShape shape;
	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initShape();
	void initVariables();
public:
	Enemy(float pos_x, float pos_y);

	~Enemy();
	 
	//dostep
	const sf::FloatRect getBounds() const;
	
	//funkcje
	void update();
	void render(sf::RenderTarget* target);


};
#endif
