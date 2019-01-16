#include "Platform.h"

Platform::Platform(sf::Texture & texture, sf::Vector2f size)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(&texture);
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

void Platform::scale(sf::Vector2f scale)
{
	body.setScale(scale);
}
