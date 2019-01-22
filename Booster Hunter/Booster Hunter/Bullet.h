#pragma once
#include <SFML\Graphics.hpp>
#include "Collider.h"

class Bullet
{
public:
	Bullet(sf::Texture & texture, sf::Vector2f size, sf::Vector2f scale);
	~Bullet();
	void Draw(sf::RenderWindow & window);
	void position(sf::Vector2f(position));
	void fire(float speed);
	Collider GetCollider() { return Collider(body); }
	void direction(bool dir);
private:
	sf::RectangleShape body;
	int trigger;
};
