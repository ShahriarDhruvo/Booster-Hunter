#include "Life.h"
#include <iostream>

int x1 = 10;
int x2 = 10;

Life::Life(sf::Texture & texture)
{
	body.setSize(sf::Vector2f(28.0f, 28.0f));
	body.setTexture(&texture);
	texture.setSmooth(true);
}

Life::~Life()
{
}

void Life::smash1()
{
	x1--;
}

void Life::smash2()
{
	x2--;
}

void Life::Draw1(sf::RenderWindow & window)
{
	for (int i = 0; i < x1; i++) {
		body.setPosition(60 + ((signed)i * 30), 5);
		window.draw(body);
	}
}

void Life::Draw2(sf::RenderWindow & window)
{
	for (int i = 0; i < x2; i++) {
		body.setPosition(842 + ((signed)i * 30), 5);
		window.draw(body);
	}
}