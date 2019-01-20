#include "Trap.h"


Trap::Trap(sf::Texture & texture)
{
	body.setSize(sf::Vector2f(50, 100));
	body.setTexture(&texture);
	body.setScale(2, 2);
	texture.setSmooth(true);
}

Trap::~Trap()
{
}

void Trap::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Trap::setPosition(sf::Vector2f position)
{
	body.setPosition(position);
}
