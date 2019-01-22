#include "Life.h"
#include "Score.h"


Life::Life(sf::Texture & texture, int life)
{
	this->life = life;
	body.setSize(sf::Vector2f(28.0f, 28.0f));
	body.setTexture(&texture);
	texture.setSmooth(true);
}

Life::~Life()
{
}

void Life::smash()
{
	life--;
}

bool Life::chkDeath()
{
	if (life <= 0) return true;
	return false;
}

void Life::bonusLife()
{
	life = life + 3;
}

void Life::Draw(sf::RenderWindow & window, int positionX)
{
	for (int i = 0; i < life; i++) {
		body.setPosition(positionX + (i * 30), 5);
		window.draw(body);
	}
}