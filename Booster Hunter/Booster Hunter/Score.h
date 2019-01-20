#pragma once
#include <SFML\Graphics.hpp>

class Score
{
public:
	Score(sf::Vector2f position, sf::Vector2f posText);
	~Score();
	void addh(int myInt);
	void addv(int myInt);
	void Draw(sf::RenderWindow & window);
	bool chkGameOver();
private:
	sf::Font font;
	sf::Text score;
	sf::Text number;
	sf::Text winner;
};

