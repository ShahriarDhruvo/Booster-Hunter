#pragma once
#include <SFML\Graphics.hpp>

class Life
{
public:
	Life(sf::Texture & texture);
	~Life();
	void Draw1(sf::RenderWindow & window);
	void Draw2(sf::RenderWindow & window);
	void smash1();
	void smash2();
private:
	sf::RectangleShape body;
};

