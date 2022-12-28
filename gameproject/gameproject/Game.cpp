#include "Game.h"

//Funkcje prywatne
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gra", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);

}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initEnemies()
{
	this->spawnTimer = 50.f;
		this->spawnTimer = this->spawnTimerMax;

}

Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initPlayer();
	this->initEnemies();


}

Game::~Game()
{
	delete this->window;
	delete this->player;

	//usuwanie tekstur
	for (auto &i : this->textures)
	{
		delete i.second; //TODO co to znaczy
	}

	//usuwanie pociskow
	for (auto *i : this->bullets)
	{
		delete i;
	}
	//usuwanie wrogow
	for (auto* i : this->enemies)
	{
		delete i;
	}
}
//funkcje
void Game::run()
{
	while (this->window->isOpen())
	{
	this->update();
	this->render();
	}
}

void Game::updatePollEvent()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		//mozna to w jednym ifie TODO
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::updateInput()
{
	//Poruszanie graczem
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		this->player->move(0.f, 1.f);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"], 
		this->player->getPos().x + this->player->getBounds().width/2.f, 
		this->player->getPos().y, 0.f, -1.f, 50.f)); //0.f, -1.f, 5.f kierunek kierunek predkosc pocisku
	}
}

void Game::updateBullets()
{
	unsigned counter = 0;
	for (auto* bullet : this->bullets)
	{
		bullet->update();

		//usuwanie pocisku gdy wyjedzie z ekranu
		if (bullet->getBounds().top + bullet->getBounds().height < 0.f)
		{
			//usuwanie
			delete this->bullets.at(counter);
			this->bullets.erase(this->bullets.begin() + counter);
			--counter;

			//std::cout << this->bullets.size() << "\n";
		}
		++counter; // mala optymalizacja wzgledem counter++
	}
}

void Game::updateEnemies()
{
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % 200, rand() % 200));
		this->spawnTimer = 0.f;
	}

	for (auto* enemy : this->enemies)
	{
		enemy->update();
	}
}

void Game::update()
{
	this->updatePollEvent();
	this->updateInput();
	this->player->update();
	this->updateBullets();
	this->updateEnemies();
}

void Game::render()
{
	this->window->clear();
	
	//Rysowanie wszystkiego na ekranie
	this->player->render(*this->window);

	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}


	this->window->display();
}
