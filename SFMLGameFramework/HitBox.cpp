#include "HitBox.h"

HitBox::HitBox(sf::Vector2f pos, sf::Vector2f sides)
{
	this->pos = pos;
	this->sides = sides;
}

HitBox::~HitBox()
{
}

sf::Vector2f& HitBox::getPos()
{
	return pos;
}

sf::Vector2f HitBox::getSides()
{
	return sides;
}

float HitBox::getWidth()
{
	return sides.x;
}

float HitBox::getHeight()
{
	return sides.y;
}

HitBox HitBox::getHitBox()
{
	return *this;
}

void HitBox::drawHitBox(sf::RenderWindow* w)
{
	sf::RectangleShape r;
	r.setPosition(pos);
	r.setSize(sides);
	r.setOutlineColor(sf::Color::Black);
	r.setOutlineThickness(1);
	r.setFillColor(sf::Color::Transparent);
	w->draw(r);
}

bool HitBox::IsColliding(HitBox b)
{
	if (pos.x + sides.x < b.getPos().x || pos.x > b.getPos().x + b.getWidth())
		return false;
	if (pos.y + sides.y < b.getPos().y || pos.y > b.getPos().y + b.getHeight())
		return false;
	return true;
}
