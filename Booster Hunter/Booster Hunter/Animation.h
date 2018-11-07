#pragma once
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	~Animation();
	void update(int row, float deltaTime);
private:
	sf::Vector2u imageCount;
};

