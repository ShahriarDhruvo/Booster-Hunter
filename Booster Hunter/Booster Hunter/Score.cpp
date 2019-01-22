#include "Score.h"
#include <sstream>
#include <SFML\Audio.hpp>

#define SC_WIDTH 1200
#define SC_HEIGHT 800

template <typename T>
std::string CtoString(T arg)
{
	std::stringstream s;
	s << arg;
	return s.str();
}

int h1 = 0;
int h2 = 0;


Score::Score(sf::Vector2f position, sf::Vector2f posText)
{
	font.loadFromFile("Font\\comicbd.ttf");
	score.setFont(font);
	score.setFillColor(sf::Color::Red);
	score.setString("Score : ");
	score.setPosition(posText);
	number.setFont(font);
	number.setFillColor(sf::Color::Blue);
	number.setString("0");
	number.setPosition(position);
	winner.setFont(font);
	winner.setFillColor(sf::Color::Green);
	winner.setCharacterSize(44);
	winner.setPosition(355, 370);
}

Score::~Score()
{
}

void Score::addh(int myInt)
{
	h1 += myInt;
	number.setString(CtoString<int>(h1));
}

void Score::addv(int myInt)
{
	h2 += myInt;
	number.setString(CtoString<int>(h2));
}

void Score::Draw(sf::RenderWindow & window)
{
	window.draw(score);
	window.draw(number);
}

bool Score::gameOver(int x)
{
	if ((h1 + h2) == 250 || x != 0) {
		sf::RenderWindow window(sf::VideoMode(SC_WIDTH, SC_HEIGHT), "Winner");

		// Winner Background:
		sf::RectangleShape background(sf::Vector2f(SC_WIDTH, SC_HEIGHT));
		sf::Texture backgroundTexture;
		if (!backgroundTexture.loadFromFile("Textures\\Winner\\Winner.png")) return EXIT_FAILURE;
		backgroundTexture.setSmooth(true);
		background.setTexture(&backgroundTexture);

		sf::Event event;
		while (window.isOpen()) {
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::EventType::Closed)
					window.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
			}
			window.clear();
			window.draw(background);
			if (x == 1) {
				winner.setString("   Player 2 is DEAD !!\nThe Winner is Player 1");
				window.draw(winner);
			}
			else if (x == 2) {
				winner.setString("   Player 1 is DEAD !!\nThe Winner is Player 2");
				window.draw(winner);
			}
			else if (x == 3 && h1 > h2) {
				winner.setString("   Time Up :)\nThe Winner is Player 1");
				window.draw(winner);
			}
			else if (x == 3 && h2 > h1) {
				winner.setString("   Time Up :)\nThe Winner is Player 2");
				window.draw(winner);
			}
			else if (x == 3 && h1 == h2) {
				winner.setString("      DRAW 0_o");
				window.draw(winner);
			}
			else if (h1 > h2) {
				winner.setString("The Winner is Player 1");
				window.draw(winner);
			}
			else if (h2 > h1) {
				winner.setString("The Winner is Player 2");
				window.draw(winner);
			}
			window.display();
		}
		return true;
	}
	return false;
}
