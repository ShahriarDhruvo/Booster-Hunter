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

void Bullet::direction(bool dir)
{
	if (dir == 1) {
		body.setRotation(180);
		trigger = 1;
	}
	else {
		body.setRotation(0);
		trigger = 0;
	}
}

void Bullet::fire(float speed)
{
	if (trigger == 1) body.move(speed, 0.0f);
	else if (trigger == 0) body.move(-speed, 0.0f);
}

void Bullet::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Bullet::position(sf::Vector2f(position))
{
	body.setPosition(position);
}
