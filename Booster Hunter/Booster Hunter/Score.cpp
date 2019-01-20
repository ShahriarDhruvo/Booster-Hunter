#include "Score.h"
#include <sstream>
#include <iostream>

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
	winner.setPosition(600, 400);
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

bool Score::chkGameOver()
{
	if ((h1 + h2) == 250) {
		sf::RenderWindow window(sf::VideoMode(1200, 800), "Winner");
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
			if (h1 > h2) {
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
