#pragma once
#include <SFML\Graphics.hpp>

class CircleHitBox
{
private:
	sf::Vector2f pos;
	float radi;
public:
	CircleHitBox(sf::Vector2f, float);
	~CircleHitBox();

	sf::Vector2f& getPos();
	float getRadi();

	CircleHitBox getHitBox();

	bool IsColliding(CircleHitBox);
};

