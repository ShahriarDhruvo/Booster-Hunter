#include "Collectibles.h"


Collectibles::Collectibles(sf::Texture & texture)
{
	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setOrigin(50.0f, 50.0f);
	body.setTexture(&texture);
	body.setScale(0.3, 0.3);
	body.setPosition(500.0f, 240.0f);
	texture.setSmooth(true);

}

Collectibles::~Collectibles()
{
}
