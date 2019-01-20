#include "Villain.h"


Villain::Villain(sf::Texture & texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = false;

	body.setSize(sf::Vector2f(70.0f, 70.0f));
	body.setScale(sf::Vector2f(1.5, 1.5));
	body.setTexture(&texture);
	texture.setSmooth(true);
}

Villain::~Villain()
{
}

void Villain::OnCollision(sf::Vector2f direction)
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

void Villain::position(sf::Vector2f position)
{
	body.setPosition(position);
}

void Villain::yPosition(float yPosition)
{
	float x = body.getPosition().x;
	body.setPosition(x, yPosition - 106);
}

void Villain::Dead()
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

void Villain::update(float deltaTime)
{
	velocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && canJump) {
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

sf::Vector2f Villain::getPosition()
{
	float x = body.getPosition().x - 20.0f;
	float y = body.getPosition().y;
	return sf::Vector2f(x, y);
}

void Villain::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}