#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"

class Collectibles
{
public:
	Collectibles(sf::Texture & texture, sf::Vector2f size, sf::Vector2f scale, sf::Vector2f position);
	~Collectibles();
	Collider GetCollider() { return Collider(body); }
	void Draw(sf::RenderWindow & window);
	void position(sf::Vector2f(position));
	void move(float x, float y) { return body.move(x, y); }
public:
	sf::RectangleShape body;
};

