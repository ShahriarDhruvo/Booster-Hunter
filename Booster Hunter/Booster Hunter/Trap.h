#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"

class Trap
{
public:
	Trap(sf::Texture & texture);
	~Trap();
	void Draw(sf::RenderWindow & window);
	Collider GetCollider() { return Collider(body); }
	void setPosition(sf::Vector2f position);
private:
	sf::RectangleShape body;
};

