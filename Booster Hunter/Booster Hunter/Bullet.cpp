#include "Bullet.h"
#include <iostream>

Bullet::Bullet(sf::Texture & texture, sf::Vector2f size, sf::Vector2f scale)
{
	body.setSize(size);
	body.setScale(scale);
	body.setOrigin(size / 2.0f);
	body.setTexture(&texture);
	texture.setSmooth(true);
}

Bullet::~Bullet()
{
}

void Bullet::fire(float speed, bool dir)
{
	if (dir == 1) {
		body.setRotation(180);
		body.move(speed, 0.0f);
	}
	else {
		body.setRotation(0);
		body.move(-speed, 0.0f);
	}
}

void Bullet::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Bullet::position(sf::Vector2f(position))
{
	body.setPosition(position);
}
