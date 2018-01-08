#pragma once
#include "Rectangle.h"
#include <ctime>
#include <vector>

class RectColTest
{
private:
	int numUnits;
	sf::Vector2f size;
	std::vector<Rectangle*> units;
public:
	RectColTest(int numUnits, sf::Vector2f size);
	
	void init();
	void update(double);

	void draw(sf::RenderWindow*);

};

RectColTest::RectColTest(int numUnits, sf::Vector2f size)
{
	this->numUnits = numUnits;
	this->size = size;
	srand(time(NULL));
}

void RectColTest::init()
{
	for (size_t i = 0; i < numUnits; i++)
	{
		sf::Vector2f pos;
		pos.x = rand() % 800 - size.x;
		pos.y = rand() % 600 - size.y;
		sf::Vector2f vel;
		vel.x = rand() % 200 + (-100);
		vel.y = rand() % 200 + (-100);
		units.push_back(new Rectangle(pos,vel,size,sf::Color::Green));
	}
}

void RectColTest::update(double d)
{
	for (auto& r : units)
	{
		r->update(d);
	}

	for (size_t i = 0; i < numUnits; i++)
	{
		units[i]->getShape().setFillColor(sf::Color::Green);
	}

	for (int i = 0; i < numUnits; i++)
	{
		for (int j = i + 1; j < numUnits; j++)
		{
			if (units[i]->IsColliding(units[j]->getHitBox()))
			{
				units[i]->getShape().setFillColor(sf::Color::Red);
				units[j]->getShape().setFillColor(sf::Color::Red);
			}
		}
	}

}

void RectColTest::draw(sf::RenderWindow* w)
{
	for (auto& r : units)
	{
		r->draw(w);
	}
}

