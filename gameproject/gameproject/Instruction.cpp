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
	this->instructionText.setOutlineThickness(1.f); // obramowania
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


void Instruction::run()
{
	while (this->window->isOpen())
	{
		//this->updatePollEvent();
		sf::Event e2;
		while (this->window->pollEvent(e2))
		{
			//mozna to w jednym ifie TODO
			if (e2.Event::type == sf::Event::Closed)
				this->window->close();
			if (e2.Event::KeyPressed && e2.Event::key.code == sf::Keyboard::Escape)
				this->window->close();
		}

		//this->update();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			this->window->close();
			//return true;
		}

		//this->render();
		this->window->clear();
		this->window->draw(this->worldBachground);
		this->window->draw(this->instructionText);
		this->window->draw(this->backText);


		this->window->display();
	}
	

}

