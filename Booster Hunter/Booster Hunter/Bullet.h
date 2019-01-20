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
	void fire(float speed, bool dir);
	Collider GetCollider() { return Collider(body); }
	//sf::Vector2f getPosition();
	int getRight() { return body.getPosition().x + body.getSize().x; }
	int getLeft() {	return body.getPosition().x; }
	int getTop() { return body.getPosition().y; }
	int getBottom() { return body.getPosition().y + body.getSize().y;	}
private:
	sf::RectangleShape body;
};
