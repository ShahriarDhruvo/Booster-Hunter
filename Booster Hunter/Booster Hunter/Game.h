#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class Game
{
public:
	Game();
	~Game();
	int newGame();
	sf::Vector2f coinRandom(int i);
};

