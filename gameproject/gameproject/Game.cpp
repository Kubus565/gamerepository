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
	this->pointText.setCharacterSize(40); //wielkosc czcionki
	this->pointText.setFillColor(sf::Color::White); //kolor czcionki
	this->pointText.setOutlineThickness(1.f);
	this->pointText.setOutlineColor(sf::Color::Blue);

	//level
	this->levelText.setPosition(600.f, 100.f);
	this->levelText.setFont(this->font);
	this->levelText.setCharacterSize(40); //wielkosc czcionki
	this->levelText.setFillColor(sf::Color::White); //kolor czcionki
	this->levelText.setOutlineThickness(1.f);
	this->levelText.setOutlineColor(sf::Color::Red);
	
	// f1
	this->f1ToHelpText.setPosition(600.f, 585.f);
	this->f1ToHelpText.setFont(this->font);
	this->f1ToHelpText.setCharacterSize(30); //wielkosc czcionki
	this->f1ToHelpText.setFillColor(sf::Color::White); //kolor czcionki
	this->f1ToHelpText.setString("press f1 to help");
					
				//over
	this->gameOverText.setFont(this->font);
	this->gameOverText.setCharacterSize(150); //wielkosc czcionki
	this->gameOverText.setFillColor(sf::Color::Red); //kolor czcionki
	this->gameOverText.setString("Game Over!");
	this->gameOverText.setPosition(
		this->window->getSize().x / 2.f - this->gameOverText.getGlobalBounds().width / 2.f,
		this->window->getSize().y / 2.f - this->gameOverText.getGlobalBounds().height / 2.f); // napis na srodku
	this->gameOverText.setOutlineThickness(3.f);
	this->gameOverText.setOutlineColor(sf::Color::White);
	//strona help
	this->helpText.setPosition(70.f, 30.f);
	this->helpText.setFont(this->font);
	this->helpText.setCharacterSize(60); //wielkosc czcionki
	this->helpText.setOutlineThickness(1.f);
	this->helpText.setOutlineColor(sf::Color::Blue);
	this->helpText.setFillColor(sf::Color::White); //kolor czcionki
	this->helpText.setString("Help F1 \nMove up W\nMove down S\nMove left A\nMove right D\nShoot! SPACE\nSave level L\n");
																							  
																							  //player GUI, HP
	this->playerHpBar.setSize(sf::Vector2f(800.f, 25.f)); //pasek �ycia //hp
	this->playerHpBar.setFillColor(sf::Color(247, 25, 35));
	this->playerHpBar.setPosition(sf::Vector2f(0.f, 575.f));

	this->playerHpBarBack = this->playerHpBar;
	this->playerHpBarBack.setFillColor(sf::Color(25, 25, 25, 20));

}
void Game::initBackground()
{
	if (!this->worldBackgroundTex.loadFromFile("textures/background1.png"))
		std::cout << "ERROR::GAMECPP::Blad ladowania tla" << "\n";
	this->worldBachground.setTexture(this->worldBackgroundTex);
}
void Game::initPlayer()
{
	this->player = new Player(window->getSize().x/2 - 52.f, window->getSize().y / 2 - 71.f, hp);
}
void Game::initPolice()
{
	this->policeSpawnTimerMax = 50.f; //im mniej tym wiecej policji
	this->policeSpawnTimer = this->policeSpawnTimerMax;
}
void Game::initLine()
{
	this->lineSpawnTimerMax = 50.f; //im mniej tym wiecej lini
	this->lineSpawnTimer = this->lineSpawnTimerMax;
}
#pragma endregion
// koniec init�w %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Game::Game(float spawnlevel_, int points_, int hp_)
{
	MainWindow mainWindow("Game");
	this->window = mainWindow.getWindow();

	this->points = points_;
	this->level = 1;//1  2  3
	this->spawnlevel = spawnlevel_;// 0.5, 1.5, 2.5
	this->hp = hp_;

	this->initTextures();
	this->initGUI();
	this->initBackground();
	this->initPlayer();
	this->initPolice();
	this->initLine();
	this->isf1press = false;
	this->changedPoints1000 = false;
	this->changedPoints2000 = false;
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
const bool& Game::getChangedPoints1000() const
{
	return this->changedPoints1000;
}
const bool& Game::getChangedPoints2000() const
{
	return this->changedPoints2000;
}
const int& Game::getStartHp() const
{
	return this->hp;
}
void Game::run()
{
	//while (this->window->isOpen())
	//bool changedPoints1000 = false;// zeby zmieni�o sie tylko raz
	//bool changedPoints2000 = false;
	while (this->points < 3000 )
	{
		this->updatePollEvent();	//over
		this->f1Listener(); //Mateusz od komentuje

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
void Game::f1Listener()
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
	std::stringstream pp; //liczba punktow
	pp << "Score: " << this->points;
	this->pointText.setString(pp.str());  

	std::stringstream ll; //level
	ll << "Level: " << this->level;
	this->levelText.setString(ll.str());

	//aktualizacja paska hp
	float hpPercent = static_cast<float>(this->player->getHp()) / this->player->getHpMax();
	this->playerHpBar.setSize(sf::Vector2f(800.f * hpPercent, this->playerHpBar.getSize().y));

}

void Game::updateCollision() //zeby pojazd nie wychodzi� poza ekran
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
void Game::updatePolice()
{
	//respienie
	this->policeSpawnTimer += this->spawnlevel;//0.5f, im wiecej tym wiecej policji
	if (this->policeSpawnTimer >= this->policeSpawnTimerMax)
	{
		this->polices.push_back(new Police(this->textures["POLICE"], rand() % 212 + 44, -100, level)); //zeby policje nie tworzy�y sie na srodku
		this->polices.push_back(new Police(this->textures["POLICE"], rand() % 199 + 454, -200, level));
		this->policeSpawnTimer = 0.f;
	}
	//aktualizacja
	//jezeli policja st�ucze inny radiow�z to ma sie przyklei�, nie przenika�
	for (int i = 0; i < this->polices.size(); i++)
	{
		bool police_stopped = false;
		for (size_t k = 0; k < this->polices.size() && police_stopped == false; k++) //sprawdzacz: je�eli pocisk zabi� kogos to omijamy ponizsza petle i przechodzimy do nastepnego wroga
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
		this->lines.push_back(new Line( 142 - 2, -25, level*3)); //miejsce lini 1 pas
		this->lines.push_back(new Line( 251 - 2, -25, level*3));
		this->lines.push_back(new Line( 550 - 2, -25, level*3)); //miejsce lini 2 pas
		this->lines.push_back(new Line( 657 - 2, -25, level*3));
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
void Game::updateCombat() // sprawdza w�asnie usuwanego przeciwnika i patrzy na nastepny pocisk
{

	//do policji
	for (int i = 0; i < this->polices.size(); i++)
	{
		bool police_deleted = false;
		for (size_t k = 0; k < this->bullets.size() && police_deleted == false; k++) //sprawdzacz: je�eli pocisk zabi� kogos to omijamy ponizsza petle i przechodzimy do nastepnego wroga
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
	this->updateInput(); //Mat komentuje
	this->player->update();
	this->updateCollision();
	this->updateBullets();
	this->updatePolice();
	this->updateLine();
	this->updateCombat();
	this->updateGUI();
}

#pragma region Rendery
void Game::renderGUI()
{
	this->window->draw(this->pointText);
	this->window->draw(this->levelText);
	this->window->draw(this->f1ToHelpText);
	this->window->draw(this->playerHpBarBack); //hp
	this->window->draw(this->playerHpBar);
}
void Game::renderBackground()
{
	this->window->draw(this->worldBachground);
}
void Game::render()
{
	this->window->clear();

	//rysowanie tla
	this->renderBackground();
	
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
	//f1
	if (this->getHelp() == true)
		this->window->draw(this->helpText);	
	
	
	if (this->points >= 1000 && this->points < 2000 && this->getChangedPoints1000() == false)
	{
		spawnlevel += 1.0f;
		//std::cout << spawnlevel << "\n";
		level = 2;
		this->changedPoints1000 = true;
	}
	if (this->points >= 2000 && this->points < 3000 && this->getChangedPoints2000() == false)
	{
		spawnlevel += 1.0f;
		//std::cout << spawnlevel << "\n";
		level = 3;
		this->changedPoints2000 = true;
	}

	 
	this->window->display();
}
#pragma endregion
