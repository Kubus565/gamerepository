#include "Exit.h"

void Exit::createVision()
{
	this->windowExit = new sf::RenderWindow(sf::VideoMode(400, 300), "Exit", sf::Style::Close | sf::Style::Titlebar);
	//this->window->setFramerateLimit(144);
	this->windowExit->setFramerateLimit(60);
	this->windowExit->setVerticalSyncEnabled(false);
	//ladowanie czcionek
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
		std::cout << "ERROR::GAME::Nie udalo sie zaladowac czcionki" << " \n";

	if (!this->worldBackgroundTex.loadFromFile("textures/background3.png"))
		std::cout << "ERROR::GAMECPP::Blad ladowania tla" << "\n";
	this->worldBachground.setTexture(this->worldBackgroundTex);
	//this->worldBachground.setColor(sf::Color(106, 166, 62));

	this->exitText.setFont(this->font);
	this->exitText.setCharacterSize(50); //wielkosc czcionki
	this->exitText.setFillColor(sf::Color::Blue); //kolor czcionki
	this->exitText.setOutlineThickness(1.f); // obramowania
	this->exitText.setOutlineColor(sf::Color::White);
	this->exitText.setString("Are you sure \nwant to exit?");
	this->exitText.setPosition(40.f, 20.f);

	this->choiceText[0].setFont(this->font);
	this->choiceText[0].setCharacterSize(30); //wielkosc czcionki
	this->choiceText[0].setFillColor(sf::Color::White); //kolor czcionki
	this->choiceText[0].setOutlineThickness(1.f); // obramowania
	this->choiceText[0].setOutlineColor(sf::Color::Red);
	this->choiceText[0].setString("Save and exit");
	this->choiceText[0].setPosition(60.f, 130.f);

	this->choiceText[1].setFont(this->font);
	this->choiceText[1].setCharacterSize(30); //wielkosc czcionki
	this->choiceText[1].setFillColor(sf::Color::White); //kolor czcionki
	this->choiceText[1].setOutlineThickness(1.f); // obramowania
	this->choiceText[1].setOutlineColor(sf::Color::Red);
	this->choiceText[1].setString("Exit without saving");
	this->choiceText[1].setPosition(60.f, 170.f);

	this->choiceText[2].setFont(this->font);
	this->choiceText[2].setCharacterSize(30); //wielkosc czcionki
	this->choiceText[2].setFillColor(sf::Color::White); //kolor czcionki
	this->choiceText[2].setOutlineThickness(1.f); // obramowania
	this->choiceText[2].setOutlineColor(sf::Color::Red);
	this->choiceText[2].setString("Back to Game");
	this->choiceText[2].setPosition(60.f, 210.f);
}

Exit::Exit()
{
	this->createVision();
}

Exit::~Exit()
{
	delete this->windowExit;
}

int Exit::run() 
{
	while (this->windowExit->isOpen())
	{
		sf::Event e2;
		while (this->windowExit->pollEvent(e2))
		{
			if (e2.Event::type == sf::Event::Closed)
				this->windowExit->close();
		}
			if (e2.type == sf::Event::MouseButtonPressed)
			if (e2.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(*windowExit);
				sf::FloatRect textRect = choiceText[0].getGlobalBounds();

				if (textRect.contains(static_cast<sf::Vector2f>(mousePos)))
				{
					this->windowExit->close();
					return 1;
					//teraz trzeba zapisa�
				}
			}
			if (e2.type == sf::Event::MouseButtonPressed)
			if (e2.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(*windowExit);
				sf::FloatRect textRect = choiceText[1].getGlobalBounds();

				if (textRect.contains(static_cast<sf::Vector2f>(mousePos)))
				{
					//std::cout << "Clicked on text 2!" << std::endl;
					return 2;
					this->windowExit->close();
				}
			}
			if (e2.type == sf::Event::MouseButtonPressed)
			if (e2.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(*windowExit);
				sf::FloatRect textRect = choiceText[2].getGlobalBounds();

				if (textRect.contains(static_cast<sf::Vector2f>(mousePos)))
				{
					this->windowExit->close();
					return 3;

				}
			}

		this->windowExit->clear();
		this->windowExit->draw(this->worldBachground);
		this->windowExit->draw(this->exitText);
		this->windowExit->draw(this->choiceText[0]);
		this->windowExit->draw(this->choiceText[1]);
		this->windowExit->draw(this->choiceText[2]);
				
		this->windowExit->display();
	}

}
