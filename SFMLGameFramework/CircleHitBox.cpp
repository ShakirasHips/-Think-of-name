#include "CircleHitBox.h"
#include <math.h>

CircleHitBox::CircleHitBox(sf::Vector2f pos, float radi)
{
	this->pos = pos;
	this->radi = radi;
}

CircleHitBox::~CircleHitBox()
{
}

sf::Vector2f &CircleHitBox::getPos()
{
	return pos;
}

float CircleHitBox::getRadi()
{
	return radi;
}

CircleHitBox CircleHitBox::getHitBox()
{
	return *this;
}

bool CircleHitBox::IsColliding(CircleHitBox c)
{
	return pow((c.getPos().x - pos.x), 2) + pow((pos.y - c.getPos().y), 2) <= pow((radi + c.getRadi()), 2);
}
