#pragma once
#include "CircleHitBox.h"
#include "SFML\Graphics.hpp"
#include <vector>

class Circle: public CircleHitBox
{
private:
	sf::CircleShape shape;
	sf::Vector2f vel;
public:
	Circle(sf::Vector2f pos, sf::Vector2f vel, float radi, sf::Color);
	~Circle();

	void draw(sf::RenderWindow*);
	void update(double);
	
	sf::CircleShape& getShape();
	sf::Vector2f getSpritePos();
	sf::Vector2f getVel();
	void setVel(sf::Vector2f);
};

