#include "Collectibles.h"

Collectibles::Collectibles(sf::Texture & texture, sf::Vector2f size, sf::Vector2f scale, sf::Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(&texture);
	body.setScale(scale);
	body.setPosition(position);
	texture.setSmooth(true);
}

Collectibles::~Collectibles()
{
}
void Collectibles::position(sf::Vector2f(position))
{
	body.setPosition(position);
}
void Collectibles::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}