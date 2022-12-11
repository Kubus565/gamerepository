//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <string>
//using namespace std;
//using namespace sf;
//
//class Pokeball {
//private:
//	Vector2f position;
//	float xVel = 1, yVel = 1;
//	Texture tekstura;
//	Sprite pSprite;
//	Vector2f rozmiar_okna;
//
//public:
//	Pokeball(float x_in, float y_in)
//	{
//		position.x = x_in;
//		position.y = y_in;
//		tekstura.loadFromFile("pokeball.png");
//		pSprite.setTexture(tekstura);
//		pSprite.setPosition(position);
//
//	}
//	void przesun(float x_in, float y_in);
//
//	sf::Sprite getPokeball();
//	void sprawdzKolizjeSciany();
//	void animuj();
//
//};
//void Pokeball::przesun(float x_in, float y_in)
//{
//	sf::Vector2f pos;
//	pos.x = x_in;
//	pos.y = y_in;
//	pSprite.move(pos);
//	position = pSprite.getPosition();
//
//}
//Sprite Pokeball::getPokeball() {
//	return pSprite;
//
//}
//
//void Pokeball::sprawdzKolizjeSciany() {
//
//	rozmiar_okna.x = 800;
//	rozmiar_okna.y = 600;
//
//
//
//	if (position.x <= 0)
//		xVel = 1;
//	if (position.x >= rozmiar_okna.x - 32)
//		xVel = -1;
//	if (position.y <= 0)
//		yVel = 1;
//	if (position.y >= rozmiar_okna.y - 32)
//		yVel = -1;
//
//}
//void Pokeball::animuj() {
//	sprawdzKolizjeSciany();
//	przesun(xVel, yVel);
//}
//
//
//class Pracownik {
//private:
//	string imie;
//	string nazwisko;
//	int wiek;
//public:
//	Pracownik() {
//		cout << "konstruktor" << endl;
//	}
//
//	void getimie() {
//		string imiepomoc;
//		cin >> imiepomoc;
//		imie = imiepomoc;
//	}
//	void coutimie() {
//		cout << imie << endl;
//	}
//
//};
//
//class interfejs
//{
//private:
//	Vector2f position;
//
//	Vector2f rozmiarokna2;
//	RectangleShape blok;
//	Vector2f boki;
//public:
//
//	interfejs(float x_in, float y_in)
//	{
//		position.x = 22;
//		position.y = 50;
//		boki.x = x_in;
//		boki.y = y_in;
//
//
//
//
//	}
//	RectangleShape getfugura() {
//		blok.setSize(sf::Vector2f(boki.x, boki.y)); // tworzymy prostok¹t
//		blok.setPosition(position.x, position.y); // i ustawiamy mu pozycjê
//		blok.setFillColor(Color::Yellow);
//		return blok;
//	}
//
//
//	/*String gettekst(string lefttop, string righttop, string centerbottom)
//	{
//
//	}*/
//
//
//
//	~interfejs();
//
//
//};
//
//
//
//interfejs::~interfejs()
//{
//}
//
//
//
//int main() {
//
//	Pracownik marek;
//	Pracownik jan;
//
//
//
//	Pokeball pb(200, 0);
//
//	interfejs prostokat(755, 520);
//
//	string l = "Left top";
//	string r = "Right top";
//	string c = "Centre center";
//
//
//
//	Clock zegar;
//
//	RenderWindow window(VideoMode(800, 600), "animation");
//	Event event;
//	Texture tekstura;
//	tekstura.loadFromFile("pokeball.png");
//	Sprite pokeball(tekstura);
//
//	Text tekst;
//	String napis("helo");
//	//Font font;
//	//if (!font.loadFromFile("arial.ttf"))
//	//{
//	//	// error...
//	//}
//	//tekst.setFont(font);
//	tekst.setString("kupa");
//	tekst.setCharacterSize(24);
//	tekst.setFillColor(sf::Color::Red);
//	tekst.setStyle(sf::Text::Bold | sf::Text::Underlined);
//	tekst.setPosition(42, 42);
//
//
//
//	while (window.isOpen())
//	{
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//		}
//		window.clear(Color::Green);
//		window.draw(prostokat.getfugura());
//		window.draw(pb.getPokeball());
//		window.draw(tekst);
//
//		window.display();
//
//		if (zegar.getElapsedTime().asMilliseconds() > 5.0f)
//		{
//			//pb.przesun(1, 2);
//			pb.animuj();
//			zegar.restart();
//		}
//
//
//
//
//	}
//
//
//	return 0;
//}