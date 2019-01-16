#include "Collider.h"


Collider::Collider(sf::RectangleShape& body) : body(body)
{
}


Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider other, sf::Vector2f & direction)
{
	sf::Vector2f otherPosition = other.GetPosition();
	sf::Vector2f otherHalfsize = other.GetHalfSize();
	sf::Vector2f thisPosition = GetPosition();
	sf::Vector2f thisHalfsize = GetHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	float intersectX = abs(deltaX) - (otherHalfsize.x + thisHalfsize.x);
	float intersectY = abs(deltaY) - (otherHalfsize.y + thisHalfsize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		if (intersectX > intersectY) {
			if (deltaX > 0.0f) {
				direction.x = 1.0f;
				direction.y = 0.0f;
			}
			else {
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else {
			if (deltaY > 0.0f) {
				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else {
				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}
		//Move(0.0f, 100.0f);

		return true;
	}

	return false;
}
