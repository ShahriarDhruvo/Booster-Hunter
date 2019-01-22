#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Player
{
public:
	Player(sf::Texture & texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();
	void update(float deltaTime);
	void Draw(sf::RenderWindow & window);
	Collider GetCollider() { return Collider(body); }
	void OnCollision(sf::Vector2f direction);
	void position(sf::Vector2f position);
	void yPosition(float yPosition);
	sf::Vector2f getPosition();
	bool direction() { return faceRight; };
private:
	sf::RectangleShape body;
	sf::Vector2f velocity;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	bool canJump;
	float jumpHeight;
};
