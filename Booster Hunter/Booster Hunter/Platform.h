#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Platform
{
public:
	Platform(sf::Texture & texture);
	~Platform();
	void Draw(sf::RenderWindow & window);
	Collider GetCollider() { return Collider(body); }
	void position(sf::Vector2f position);
	void scale(sf::Vector2f scale);
	float getPosition();
private:
	sf::RectangleShape body;
};

