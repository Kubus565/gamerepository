#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
using namespace std;
using namespace sf;

class Streetline {
private:
	Vector2f position;
	float xspeed=1, ySpeed = 6; //predkosc poczotkowa
	Texture tekstura;
	Sprite pSprite;
	Vector2f rozmiar_okna;

public:
	Streetline(float x_in, float y_in, string nazwaTekstury)//TU COS ZMIENIAM!!
	{
		position.x = x_in;
		position.y = y_in;
		//tekstura.loadFromFile("streetline2.png");
		tekstura.loadFromFile(nazwaTekstury);

		pSprite.setTexture(tekstura);
		pSprite.setPosition(position);

	}
	~Streetline() {
	}
	void przesun(float x_in, float y_in);

	sf::Sprite getStreetLine();
	void sprawdzKolizjeSciany();
	void animuj();

};

	void Streetline::przesun(float x_in, float y_in)
	{
		sf::Vector2f pos;
		pos.y = y_in;
		pSprite.move(pos);
		position = pSprite.getPosition();

	}
	Sprite Streetline::getStreetLine() {
		return pSprite;

	}

	void Streetline::sprawdzKolizjeSciany() {

		rozmiar_okna.x = 800;
		rozmiar_okna.y = 600;
		int kupa = 0;

		if (position.y <= -rozmiar_okna.y)
			ySpeed = 2;
		if (position.y >= 0)
		{

			cout << "###Pozycja powinna byc zmieniona, "<<kupa<<" kilometrow\n";
			kupa++;
			ySpeed = -rozmiar_okna.y;


		}

	}
	void Streetline::animuj() {
		sprawdzKolizjeSciany();
		przesun(xspeed, ySpeed);
	}









int main() {


	int szerokoscOkna = 800;//ROZMIAR OKNA
	int wysokoscOkna = 600;



	Streetline line1(400, -600,"streetline2.png" );
	//Streetline car(szerokoscOkna / 2, wysokoscOkna - 280, "silvercar.png");
	
	Texture cartxt;
	cartxt.loadFromFile("silvercar.png"); //Creative Commons licenses,
	//Based on “[LPC] Skorpio's SciFi Sprite Pack” by Skorpio, which is dual licensed as CC-BY-SA 3.0 and GPL 3.0
	Sprite car(cartxt);
	car.setPosition(szerokoscOkna / 2, wysokoscOkna - 200);


	RectangleShape asphalt(sf::Vector2f(szerokoscOkna-(150*2), wysokoscOkna)); // tworzymy prostok¹t
	asphalt.setPosition(150, 0); // i ustawiamy mu pozycjê
	asphalt.setFillColor(Color::Black);
	

	Clock zegar;

	RenderWindow window(VideoMode(szerokoscOkna, wysokoscOkna), "animation");
	Event event;
	Texture tekstura;
	tekstura.loadFromFile("pokeball.png");
	Sprite pokeball(tekstura);

	Text tekst;
	String napis("helo");
	//Font font;
	//if (!font.loadFromFile("arial.ttf"))
	//{
	//	// error...
	//}
	//tekst.setFont(font);
	tekst.setString("kupa");
	tekst.setCharacterSize(24);
	tekst.setFillColor(sf::Color::Red);
	tekst.setStyle(sf::Text::Bold | sf::Text::Underlined);
	tekst.setPosition(42, 42);



	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color::Green);
		
		Vector2f carposition = car.getPosition();
			if (Keyboard::isKeyPressed(Keyboard::Key::A))
			{
				if(carposition.x>0)
				car.move(-0.2f,0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::D))
			{
				if (carposition.x < szerokoscOkna-88)
				car.move(0.2f, 0);
			}
		
		
		window.draw(asphalt);
		window.draw(line1.getStreetLine());
		window.draw(tekst);
		window.draw(car);

		window.display();

		if (zegar.getElapsedTime().asMilliseconds() > 5.0f)
		{
			//line1.przesun(1, 2);
			line1.animuj();
			zegar.restart();
		}




	}


	return 0;
}