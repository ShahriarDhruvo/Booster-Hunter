#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"

class Collectibles
{
public:
	Collectibles(sf::Texture & texture);
	~Collectibles();
	Collider GetCollider() { return Collider(body); }

public:
	sf::RectangleShape body;
};

