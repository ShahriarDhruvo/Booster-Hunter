#include "Platform.h"
#include <iostream>

Platform::Platform(sf::Texture & texture)
{
	body.setSize(sf::Vector2f(120.0f, 55.0f));
	body.setScale(sf::Vector2f(1.5, 0.6));
	body.setOrigin((sf::Vector2f(120.0f, 55.0f)) / 2.0f);
	body.setTexture(&texture);
	texture.setSmooth(true);
}

Platform::~Platform()
{
}

void Platform::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Platform::position(sf::Vector2f position)
{
	body.setPosition(position);
}

float Platform::getPosition()
{
	return body.getPosition().y;
}
