#include "Circle.h"
#include <iostream>
#define log(x) std::cout << x << std::endl;

Circle::Circle(sf::Vector2f pos, sf::Vector2f vel ,float radi, sf::Color c): CircleHitBox(pos,radi)
{
	shape.setRadius(radi);
	shape.setPosition(pos);
	shape.setFillColor(c);
	this->vel = vel;
}


Circle::~Circle()
{
}

void Circle::draw(sf::RenderWindow* screen)
{
	screen->draw(shape);
}

void Circle::update(double t)
{
	if (getPos().x <= 0 || getPos().x + getRadi()*2 >= 800)
	{
		vel.x = vel.x * -1;
	}
		
	if (getPos().y<= 0 || getPos().y + getRadi()*2 >= 600)
	{
		vel.y = vel.y * -1;
	}
	

	getPos().x = getPos().x + vel.x*t;
	getPos().y = getPos().y + vel.y*t;
	shape.setPosition(getPos());

}

sf::CircleShape & Circle::getShape()
{
	return shape;
}

sf::Vector2f Circle::getSpritePos()
{
	auto dimensions = shape.getGlobalBounds();

	return sf::Vector2f(dimensions.left + dimensions.width / 2.0f,
		dimensions.top + dimensions.height / 2.0f);
}

sf::Vector2f Circle::getVel()
{
	return vel;
}

void Circle::setVel(sf::Vector2f v)
{
	vel = v;
}

