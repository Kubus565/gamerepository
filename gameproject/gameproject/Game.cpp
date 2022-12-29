#include "Game.h"

//Funkcje prywatne
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gra", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);

}

void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
}

void Game::initGUI()
{
	//ladowanie czcionek
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
		std::cout << "ERROR::GAME::Nie udalo sie zaladowac czcionki"<< " \n";

	//wlaczenie punktora
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(122); //wielkosc czcionki
	this->pointText.setFillColor(sf::Color::White); //kolor czcionki
	this->pointText.setString("test");

}

void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("textures/background1.jpg"))
		std::cout << "ERROR::GAMECPP::Blad ladowania tla" << "\n";
	this->worldBachground.setTexture(this->worldBackgroundTex);
}

void Game::initPlayer()
{
	this->player = new Player();

}

void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
		this->spawnTimer = this->spawnTimerMax;

}

Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initWorld();
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
		this->player->getPos().y, 0.f, -1.f, 14.f)); //0.f, -1.f, 5.f kierunek kierunek predkosc pocisku
	}
}

void Game::updateGUI()
{

}

void Game::updateWorld()
{

}

void Game::updateCollision() //zeby pojazd nie wychodzi³ poza ekran
{
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
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
	//respienie
	this->spawnTimer += 0.5f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 20.f,  -100));
		this->spawnTimer = 0.f;
	}
	//aktualizacja
	unsigned counter = 0;
	for (auto* enemy : this->enemies)
	{
		enemy->update();

		//usuwanie wrogow gdy wyjedzie z ekranu
		if (enemy->getBounds().top > this->window->getSize().y)
		{
			//usuwanie
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			--counter;

			//std::cout << this->bullets.size() << "\n";
		}
		++counter; // mala optymalizacja wzgledem counter++
	}
	
	
}

void Game::updateCombat() // sprawdza w³asnie usuwanego przeciwnika i patrzy na nastepny pocisk
{
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++) //sprawdzacz: je¿eli pocisk zabi³ kogos to omijamy ponizsza petle i przechodzimy do nastepnego wroga
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				enemy_deleted = true;
			}

		}

	}
}

void Game::update()
{
	this->updatePollEvent();
	this->updateInput();
	this->player->update();
	this->updateCollision();
	this->updateBullets();
	this->updateEnemies();
	this->updateCombat();
	this->updateGUI();
	this->updateWorld();
}

void Game::renderGUI()
{
	this->window->draw(this->pointText);
}

void Game::renderWorld()
{
	this->window->draw(this->worldBachground);
}

void Game::render()
{
	this->window->clear();

	//rysowanie tla
	this->renderWorld();
	
	//Rysowanie wszystkich rzeczy
	this->player->render(*this->window);

	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}

	this->renderGUI();

	this->window->display();
}
