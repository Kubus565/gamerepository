#include "Game.h"
#pragma region Game_inicjalizacja
//Funkcje prywatne
//void Game::initWindow()
//{
//	//this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Gra", sf::Style::Close | sf::Style::Titlebar);
//	////this->window->setFramerateLimit(144);
//	//this->window->setFramerateLimit(60);
//	//this->window->setVerticalSyncEnabled(false);
//}
void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	this->textures["BULLET"]->loadFromFile("Textures/bullet.png");
	this->textures["POLICE"] = new sf::Texture();
	this->textures["POLICE"]->loadFromFile("Textures/police.png");
	this->textures["LINE"] = new sf::Texture();
	this->textures["LINE"]->loadFromFile("Textures/line.png");
}
void Game::initGUI()
{
	//ladowanie czcionek
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
		std::cout << "ERROR::GAME::Nie udalo sie zaladowac czcionki"<< " \n";

	//wlaczenie punktora
	this->pointText.setPosition(600.f, 25.f);
	this->pointText.setFont(this->font);
	this->pointText.setCharacterSize(30); //wielkosc czcionki
	this->pointText.setFillColor(sf::Color::White); //kolor czcionki
	this->pointText.setString("test");
					
				//over
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(100); //wielkosc czcionki
	this->gameOverText.setFillColor(sf::Color::Red); //kolor czcionki
	this->gameOverText.setString("Game Over!");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f); // napis na srodku

	//strona help
	this->helpText.setPosition(70.f, 25.f);
	this->helpText.setFont(this->font);
	this->helpText.setCharacterSize(40); //wielkosc czcionki
	this->helpText.setFillColor(sf::Color::Green); //kolor czcionki
	this->helpText.setString("klawisz F1 \n klawisz < ^ > ");
																							  
																							  //player GUI, HP
	this->playerHpBar.setSize(sf::Vector2f(300.f, 25.f)); //pasek ¿ycia //hp
	this->playerHpBar.setFillColor(sf::Color::Red);
	this->playerHpBar.setPosition(sf::Vector2f(20.f, 20.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));

}
void Game::initWorld()
{
	if (!this->worldBackgroundTex.loadFromFile("textures/background1.png"))
		std::cout << "ERROR::GAMECPP::Blad ladowania tla" << "\n";
	this->worldBachground.setTexture(this->worldBackgroundTex);
}
void Game::initSystems()
{
	this->points = 0;
}
void Game::initPlayer()
{
	this->player = new Player(window->getSize().x/2 - 52.f, window->getSize().y / 2 - 71.f, hp);
}
void Game::initEnemies()
{
	this->spawnTimerMax = 50.f;
		this->spawnTimer = this->spawnTimerMax;
}
void Game::initPolice()
{
	this->policeSpawnTimerMax = 50.f; //im mniej tym wiecej policji
	this->policeSpawnTimer = this->policeSpawnTimerMax;
}
void Game::initLine()
{
	this->lineSpawnTimerMax = 50.f;
	this->lineSpawnTimer = this->lineSpawnTimerMax;
}
void Game::initHp(int hp_)
{
	this->hp = hp_;
}
#pragma endregion
// koniec initów %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Game::Game(int level_, int points_, int health_)
{
	MainWindow mainWindow("Graa");
	this->window = mainWindow.getWindow();
	//this->speed = s1.speed;
	this->points = points_;
	this->initHp(health_);
	
	//this->initWindow();
	this->initTextures();
	this->initGUI();
	this->initWorld();
	this->initSystems(); //punkty
	this->initPlayer();
	this->initEnemies();
	this->initPolice();
	this->initLine();
	this->isf1press = false;
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
	/*for (auto* i : this->enemies)
	{
		delete i;
	}*/
	//usuwanie policji
	for (auto* i : this->polices)
	{
		delete i;
	}
	//usuwanie lini
	for (auto* i : this->lines)
	{
		delete i;
	}

}

//funkcje
const bool& Game::getHelp() const
{
	return this->isf1press;
}
const int& Game::getStartHp() const
{
	return this->hp;
}
void Game::run()
{
	//while (this->window->isOpen())
		while (this->points < 3000 )
	{
		this->updatePollEvent();	//over
		this->keyListener(); //Mateusz od komentuje

		if(this->player->getHp() > 0 && !isf1press)	//over
		this->update();
	
	this->render();
	}
}

#pragma region Updatingi
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(0.f, 1.f);
	//strelanie
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack())
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack())
	{
		this->bullets.push_back(new Bullet(this->textures["BULLET"], 
		this->player->getPos().x + this->player->getBounds().width/2.f - 5.0f, 
		this->player->getPos().y, 0.f, -1.f, 34.f)); //0.f, -1.f, 5.f kierunek kierunek predkosc pocisku
	}
	//pomoc
	//bool isf1press = false;
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
	{
		isf1press =! isf1press;
		
	}*/

}

//funkcja mateusza
void Game::keyListener()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
	{
		//isf1press = !isf1press;
		isf1press = true;
	}
	else isf1press = false;
}
void Game::updateGUI()
{
	std::stringstream ss; //liczba punktow
	ss << "Punkty: " << this->points;
	this->pointText.setString(ss.str());

	//aktualizacja paska hp
	//this->player->setHp(5); //test paska hp
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(300.f * hpPercent, this->playerHpBar.getSize().y));

}
void Game::updateWorld()
{

}
void Game::updateCollision() //zeby pojazd nie wychodzi³ poza ekran
{
	//lewa granica swiata
	if (this->player->getBounds().left < 0.f)
	{
		this->player->setPosition(0.f, this->player->getBounds().top);
	}
	//prawa granica swiata
	else if (this->player->getBounds().left + this->player->getBounds().width >= this->window->getSize().x )
	{
		this->player->setPosition(this->window->getSize().x - this->player->getBounds().width, this->player->getBounds().top);
	}
	//gorna granica swiata
	if (this->player->getBounds().top < 0.f)
	{
		this->player->setPosition(this->player->getBounds().left, 0.f);
	}
	
	//dolna granica swiata
	else if (this->player->getBounds().top + this->player->getBounds().height >= this->window->getSize().y)
	{
		this->player->setPosition(this->player->getBounds().left, this->window->getSize().y - this->player->getBounds().height);
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

			//std::cout << this->bullets.size() << "\n";
		}
		
		++counter; // mala optymalizacja wzgledem counter++
	}
}
//void Game::updateEnemies()
//{
//	//respienie
//	this->spawnTimer += 0.5f;
//	if (this->spawnTimer >= this->spawnTimerMax)
//	{
//		this->enemies.push_back(new Enemy(rand() % this->window->getSize().x - 20.f,  -100));
//		this->spawnTimer = 0.f;
//	}
//	//aktualizacja
//	unsigned counter = 0;
//	for (auto* enemy : this->enemies)
//	{
//		enemy->update();
//
//		//usuwanie wrogow gdy wyjedzie z ekranu
//		if (enemy->getBounds().top > this->window->getSize().y)
//		{
//			//usuwanie wrogow
//			delete this->enemies.at(counter);
//			this->enemies.erase(this->enemies.begin() + counter);
//
//			//std::cout << this->bullets.size() << "\n";
//		}
//		//jezeli wrog dotknie gracza
//		else if (enemy->getBounds().intersects(this->player->getBounds())) 
//		{
//			this->player->loseHp(this->enemies.at(counter)->getDamage()); //end
//			
//			delete this->enemies.at(counter);
//			this->enemies.erase(this->enemies.begin() + counter);
//		}
//		++counter; // mala optymalizacja wzgledem counter++
//	}
//}
void Game::updatePolice()
{
	//respienie
	this->policeSpawnTimer += 0.5f;
	if (this->policeSpawnTimer >= this->policeSpawnTimerMax)
	{
		this->polices.push_back(new Police(this->textures["POLICE"], rand() % 212 + 44, -100)); //zeby policje nie tworzy³y sie na srodku
		this->polices.push_back(new Police(this->textures["POLICE"], rand() % 199 + 454, -200));
		this->policeSpawnTimer = 0.f;
	}
	//aktualizacja
	//jezeli policja st³ucze inny radiowóz to ma sie przykleiæ, nie przenikaæ
	for (int i = 0; i < this->polices.size(); i++)
	{
		bool police_stopped = false;
		for (size_t k = 0; k < this->polices.size() && police_stopped == false; k++) //sprawdzacz: je¿eli pocisk zabi³ kogos to omijamy ponizsza petle i przechodzimy do nastepnego wroga
		{
			if (this->polices[i]->getBounds().intersects(this->polices[k]->getBounds()))
			{
				this->polices[i]->updateStop();
				this->polices[k]->updateStop();
				police_stopped = true;
			}
		}
		this->polices[i]->update();
		//std::cout << " " << this->polices.size();
	}
	
	unsigned counter = 0;
	for (auto* police : this->polices)
	{
		//usuwanie  gdy wyjedzie z ekranu
		if (police->getBounds().top > this->window->getSize().y)
		{
			//usuwanie policji
			delete this->polices.at(counter);
			this->polices.erase(this->polices.begin() + counter);

			//std::cout << this->bullets.size() << "\n";
		}
		//jezeli policja dotknie gracza
		else if (police->getBounds().intersects(this->player->getBounds()))
		{
			this->player->loseHp(this->polices.at(counter)->getDamage()); //end

			delete this->polices.at(counter);
			this->polices.erase(this->polices.begin() + counter);
		}
		
		++counter; // mala optymalizacja wzgledem counter++
	}
}
void Game::updateLine()
{
	//respienie
	this->lineSpawnTimer += 1.2f;// 0.5f odleglosc pomiedzy liniami, im mniej tym wieksza
	if (this->lineSpawnTimer >= this->policeSpawnTimerMax)
	{
		this->lines.push_back(new Line( 142 - 2, -25)); //miejsce lini 1 pas
		this->lines.push_back(new Line( 251 - 2, -25));
		this->lines.push_back(new Line( 550 - 2, -25)); //miejsce lini 2 pas
		this->lines.push_back(new Line( 657 - 2, -25));
		this->lineSpawnTimer = 0.f;
	}
	//aktualizacja
	unsigned counter = 0;
	for (auto* line : this->lines)
	{
		line->update();
		//usuwanie lini gdy wyjedzie z ekranu
		if (line->getBounds().top > this->window->getSize().y)
		{
			//usuwanie lini
			delete this->lines.at(counter);
			this->lines.erase(this->lines.begin() + counter);
			//std::cout << this->bullets.size() << "\n";
		}
		++counter; // mala optymalizacja wzgledem counter++
	}
}
void Game::updateCombat() // sprawdza w³asnie usuwanego przeciwnika i patrzy na nastepny pocisk
{
	//do wrogow
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool enemy_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && enemy_deleted == false; k++) //sprawdzacz: je¿eli pocisk zabi³ kogos to omijamy ponizsza petle i przechodzimy do nastepnego wroga
		{
			if (this->enemies[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				//punkty za zabojstwo
				this->points += this->enemies[i]->getPoints();

				delete this->enemies[i];
				this->enemies.erase(this->enemies.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);
				
				enemy_deleted = true;
			}
		}
	}
	//do policji
	for (int i = 0; i < this->polices.size(); i++)
	{
		bool police_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && police_deleted == false; k++) //sprawdzacz: je¿eli pocisk zabi³ kogos to omijamy ponizsza petle i przechodzimy do nastepnego wroga
		{
			if (this->polices[i]->getBounds().intersects(this->bullets[k]->getBounds()))
			{
				//punkty za zabojstwo
				this->points += this->polices[i]->getPoints();

				delete this->polices[i];
				this->polices.erase(this->polices.begin() + i);

				delete this->bullets[k];
				this->bullets.erase(this->bullets.begin() + k);

				police_deleted = true;
			}
		}
	}

}
#pragma endregion
void Game::update()
{
	//usuwam pollEvent bo jest wyzej
	//this->updatePollEvent();
	this->updateInput(); //Mateusz komentuje
	this->player->update();
	this->updateCollision();
	this->updateBullets();
	//this->updateEnemies();
	this->updatePolice();
	this->updateLine();
	this->updateCombat();
	this->updateGUI();
	//this->updateWorld();
}

#pragma region Rendery
void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->playerHpBarBack); //hp
	this->window->draw(this->playerHpBar);
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
	for (auto* line : this->lines)
	{
		line->render(this->window);
	}

	for (auto* bullet : this->bullets)
	{
		bullet->render(this->window);
	}

	/*for (auto* enemy : this->enemies)
	{
		enemy->render(this->window);
	}*/
	
	for (auto* police : this->polices)
	{
		police->render(this->window);
	}
	

	this->player->render(*this->window);
	this->renderGUI();

	//Game over //over
	if (this->player->getHp() <= 0)	//over
		this->window->draw(this->gameOverText);	//over
	if (this->getHelp() == true)
		this->window->draw(this->helpText);	


	this->window->display();
}
#pragma endregion
