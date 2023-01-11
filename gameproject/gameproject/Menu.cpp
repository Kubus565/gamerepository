#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
void Menu::initVision()
{
	//ladowanie czcionek
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
		std::cout << "ERROR::GAME::Nie udalo sie zaladowac czcionki" << " \n";

	if (!this->worldBackgroundTex.loadFromFile("textures/background2.png"))
		std::cout << "ERROR::GAMECPP::Blad ladowania tla" << "\n";
	this->worldBachground.setTexture(this->worldBackgroundTex);
	//this->worldBachground.setColor(sf::Color(106, 166, 62));

	this->menuText[0].setFont(this->font); 
	this->menuText[0].setCharacterSize(120); //wielkosc czcionki
	this->menuText[0].setFillColor(sf::Color::Blue); //kolor czcionki
	this->menuText[0].setOutlineThickness(2.f); // obramowania
	this->menuText[0].setOutlineColor(sf::Color::White); 
	this->menuText[0].setString("Police 7 siege!"); //tytu³ gry
	this->menuText[0].setPosition(80.f, 40.f); 

	this->menuText[1].setFont(this->font);
	this->menuText[1].setCharacterSize(50); //wielkosc czcionki
	this->menuText[1].setFillColor(sf::Color::White); //kolor czcionki
	this->menuText[1].setOutlineThickness(1.f); // obramowania
	this->menuText[1].setOutlineColor(sf::Color::Blue);
	this->menuText[1].setString("1 New Game");
	this->menuText[1].setPosition(80.f, 250.f);

	this->menuText[2].setFont(this->font);
	this->menuText[2].setCharacterSize(50); //wielkosc czcionki
	this->menuText[2].setFillColor(sf::Color::White); //kolor czcionki
	this->menuText[2].setOutlineThickness(1.f); // obramowania
	this->menuText[2].setOutlineColor(sf::Color::Blue);
	this->menuText[2].setString("2 Load last game");
	this->menuText[2].setPosition(80.f, 330.f);

	this->menuText[3].setFont(this->font);
	this->menuText[3].setCharacterSize(50); //wielkosc czcionki
	this->menuText[3].setFillColor(sf::Color::White); //kolor czcionki
	this->menuText[3].setOutlineThickness(1.f); // obramowania
	this->menuText[3].setOutlineColor(sf::Color::Blue);
	this->menuText[3].setString("`~ Instruction and control");
	this->menuText[3].setPosition(80.f, 410.f);

}
Menu::Menu()
{
	MainWindow menu("Menu");
	this->window = menu.getWindow();
	//this->fileWritting();
	//this->fileReading();
	this->initVision();
}

Menu::~Menu()
{
	delete this->window;
}

//void Menu::fileWritting()
//{
//	FILE* file = fopen("game.txt", "wb");
//	fwrite(&config.points, sizeof(int), 1, file);
//	fwrite(&config.hp, sizeof(int), 1, file);
//	fclose(file);
//}

//void Menu::fileReading()
//{
//	FILE* file = fopen("game.txt", "rb");
//	int hpFromFile, pointsFromFile;
//	float spawnlevelFromFile;
//	//fread(&conf.points, sizeof(int), 1, file);
//	//fread(&conf.hp, sizeof(int), 1, file);
//	fread(&spawnlevelFromFile, sizeof(int), 1, file);
//	fread(&pointsFromFile, sizeof(int), 1, file);
//	fread(&hpFromFile, sizeof(int), 1, file);
//	//printf("HP: %d\nLevel: %d\n", hp, level);
//	//std::cout << "hp: " << hpp << " punkty: " << pooi;
//	config.spawnlevel = spawnlevelFromFile;
//	config.points = pointsFromFile;
//	config.hp = hpFromFile;
//	fclose(file);
//}

void Menu::reading()
{
		
		std::fstream file;
		file.open("note.txt", std::ios::in);
		if (file.good() == false)
		{
			std::cout << "Plik nie istnieje!";
			exit(0);
		}
		file >> config[1].spawnlevel;
		file >> config[1].points;
		file >> config[1].hp;
		file.close();
}

//bool Menu::isFileEmpty(const char* file_name)
//{
//	std::ifstream file(file_name, std::ios::binary);
//	return file.peek() == std::ifstream::traits_type::eof();
//}



//tu int
//void Menu::run()
//{
//	while (this->window->isOpen())
//	{
//		this->updatePollEvent();	//over
//
//		this->update();
//		this->render();
//	}
//}

int Menu::run()//TODO zamienic int na void
{
	while (this->window->isOpen())
	{
		//updatePollEvent();	
		sf::Event e1;
		while (this->window->pollEvent(e1))
		{
			//mozna to w jednym ifie TODO
			if (e1.Event::type == sf::Event::Closed)
				this->window->close();
				
			if (e1.Event::KeyPressed && e1.Event::key.code == sf::Keyboard::Escape)
				//this->window->close();
				std::cout << " ";
				

			
		}

		//update();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			//this->window->close();
			config[0].spawnlevel = 0.5f;
			config[0].points = 100;
			config[0].hp = 100; // max to 100

			Game game(config[0].spawnlevel, config[0].points, config[0].hp);
			game.run();
			//std::cout << "nowa gra ";

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
				reading();
				Game game(config[1].spawnlevel, config[1].points, config[1].hp);
				game.run();
				//std::cout << "z configu  odczyt )";
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde))
		{
			//return 3;
			Instruction inst;
			/*if (inst.run() == true)
				break;*/
			inst.run();

		}
		//render();
		this->window->clear();
		this->window->draw(this->worldBachground);
		this->window->draw(this->menuText[0]);
		this->window->draw(this->menuText[1]);
		this->window->draw(this->menuText[2]);
		this->window->draw(this->menuText[3]);
		this->window->display();
	}
	return 0;
	
}

