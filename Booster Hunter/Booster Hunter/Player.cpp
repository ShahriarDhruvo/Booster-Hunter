#include "Player.h"



Player::Player(sf::Texture & texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	body.setPosition(200, 200);
	body.setTexture(texture);
	body.setScale(1.3, 1.3);
	texture.setSmooth(true);
}


Player::~Player()
{
}

void Player::update(float deltaTime)
{
	sf::Vector2f movement(0, 0);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		movement.x += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		movement.x -= speed * deltaTime;
	if (movement.x == 0)
		row = 0;
	else {
		row = 2;

		if (movement.x > 0)
			faceRight = true;
		else
			faceRight = false;
	}
	animation.update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

