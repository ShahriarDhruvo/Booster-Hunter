#include "Player.h"
#include <iostream>

Player::Player(sf::Texture & texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(70.0f, 70.0f));
	body.setTexture(&texture);
	body.setScale(1.3, 1.4);
	texture.setSmooth(true);
}

Player::~Player()
{
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f) {
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f) {
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f) {
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f) {
		velocity.y = 0.0f;
	}
}

void Player::position(sf::Vector2f position)
{
	body.setPosition(position);
}

void Player::yPosition(float yPosition)
{
	float x = body.getPosition().x;
	body.setPosition(x, yPosition - 100);
}

void Player::Dead()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "You are Dead !");
	sf::Text dead;
	sf::Font font;
	dead.setFillColor(sf::Color::Red);
	dead.setString("Dead");
	while (window.isOpen()) {
		window.clear();
		window.draw(dead);
		window.display();
	}
}

bool Player::chkCollision(Bullet bullet)
{
	if (bullet.getRight() < body.getPosition().x && bullet.getTop() < body.getPosition().y + body.getSize().y && bullet.getBottom() > body.getPosition().y)
		return true;
}

void Player::update(float deltaTime)
{
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		velocity.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump) {
		canJump = false;
		velocity.y = -sqrt(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0)
		row = 0;
	else {
		row = 1;

		if (velocity.x > 0)
			faceRight = true;
		else
			faceRight = false;
	}
	animation.update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

sf::Vector2f Player::getPosition()
{
	float x = body.getPosition().x + 100.0f;
	float y = body.getPosition().y;
	return sf::Vector2f(x, y);
}

void Player::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}