#pragma once
#include <SFML\Graphics.hpp>

class Life
{
public:
	Life(sf::Texture & texture, int life);
	~Life();
	void Draw(sf::RenderWindow & window, int positionX);
	void smash();
	bool chkDeath();
	void bonusLife();
private:
	sf::RectangleShape body;
	int life;
};

