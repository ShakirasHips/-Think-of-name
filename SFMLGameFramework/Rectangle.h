#pragma once
#include "HitBox.h"
class Rectangle: public HitBox
{
private:
	sf::RectangleShape shape;
	sf::Vector2f vel;
public:
	Rectangle(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f size, sf::Color);
	~Rectangle();

	void draw(sf::RenderWindow*);
	void update(double);

	sf::RectangleShape& getShape();
};

