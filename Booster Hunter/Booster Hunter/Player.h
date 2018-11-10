#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Player
{
public:
	Player(sf::Texture & texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();
	void update(float deltaTime);

public:
	sf::Sprite body;

private:
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};

