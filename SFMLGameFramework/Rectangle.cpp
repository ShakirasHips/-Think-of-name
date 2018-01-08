#include "Rectangle.h"


Rectangle::Rectangle(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f size, sf::Color c): HitBox(pos,size)
{
	shape.setPosition(pos);
	shape.setSize(size);
	shape.setFillColor(c);
	this->vel = vel;
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(sf::RenderWindow *w)
{
	w->draw(shape);
}

void Rectangle::update(double t)
{
	if (getPos().x <= 0 || getPos().x+getWidth() >= 800)
		vel.x = vel.x * -1;

	if (getPos().y <=0 || getPos().y + getHeight() >= 600)
		vel.y = vel.y * -1;

	getPos().x = getPos().x + vel.x*t;
	getPos().y = getPos().y + vel.y*t;
	shape.setPosition(getPos());
}

sf::RectangleShape& Rectangle::getShape()
{
	return shape;
}
