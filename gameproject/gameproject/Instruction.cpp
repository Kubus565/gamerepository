#include "Instruction.h"
void Instruction::initVision()
{
	//ladowanie czcionek
	if (!this->font.loadFromFile("Fonts/PixellettersFull.ttf"))
		std::cout << "ERROR::GAME::Nie udalo sie zaladowac czcionki" << " \n";

	if (!this->worldBackgroundTex.loadFromFile("textures/background2.png"))
		std::cout << "ERROR::GAMECPP::Blad ladowania tla" << "\n";
	this->worldBachground.setTexture(this->worldBackgroundTex);
	//this->worldBachground.setColor(sf::Color(106, 166, 62));
		  
	this->instructionText.setFont(this->font);
	this->instructionText.setCharacterSize(50); //wielkosc czcionki
	this->instructionText.setFillColor(sf::Color::Blue); //kolor czcionki
	this->instructionText.setOutlineThickness(2.f); // obramowania
	this->instructionText.setOutlineColor(sf::Color::White);
	this->instructionText.setString("Don't get caught by the police\nJust shoot them all!");
	this->instructionText.setPosition(80.f, 250.f);

	this->backText.setFont(this->font);
	this->backText.setCharacterSize(30); //wielkosc czcionki
	this->backText.setFillColor(sf::Color::White); //kolor czcionki
	
	this->backText.setString("Let's back to menu SPACE");
	this->backText.setPosition(80.f, 450.f);
		  
}
Instruction::Instruction()
{
	MainWindow instructions("Instruction");
	this->window = instructions.getWindow();

	this->initVision();
}

Instruction::~Instruction()
{
	delete this->window;
}

//tu int
void Instruction::run()
{
	while (this->window->isOpen())
	{
		this->updatePollEvent();	//over

		//if (this->player->getHp() > 0 && !isf1press)	//over
		this->update();

		this->render();
	}
	//return this->level
}

void Instruction::updatePollEvent()
{
	sf::Event e2;
	while (this->window->pollEvent(e2))
	{
		//mozna to w jednym ifie TODO
		if (e2.Event::type == sf::Event::Closed)
			this->window->close();
		if (e2.Event::KeyPressed && e2.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}
void Instruction::updateInput()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::Vector2i position = sf::Mouse::getPosition();
		std::cout << position.x << " " << position.y << "\n";

	}

}

void Instruction::update()
{
	this->updateInput();
	
}
void Instruction::render()
{
	this->window->clear();

	//this->renderVision();
	this->window->draw(this->worldBachground);
	this->window->draw(this->instructionText);
	this->window->draw(this->backText);
	

	this->window->display();
}