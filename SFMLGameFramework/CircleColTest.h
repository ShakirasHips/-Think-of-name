#pragma once
#include <vector>
#include <array>
#include <ctime>
#include "Circle.h"
#include <iostream>

#define log(x) std::cout << x << std::endl

class CircleColTest
{
private:
	int numUnits;
	float radi;
	std::vector<Circle*> units;
public:
	CircleColTest(int numUnits, float radi);

	void init();
	void update(double);
	void draw(sf::RenderWindow* screen);

};

CircleColTest::CircleColTest(int numUnits, float radi): numUnits(numUnits), radi(radi)
{
	srand(time(NULL));
}


void CircleColTest::init()
{
	for (size_t i = 0; i < numUnits; i++)
	{
		sf::Vector2f pos;
		pos.x = rand() % 800 - radi;
		pos.y = rand() % 600 - radi;
		sf::Vector2f vel;
		vel.x = rand() % 200 + (-100);
		vel.y = rand() % 200 + (-100);
		units.push_back(new Circle(pos, vel, radi, sf::Color::Green));
	}
}

void CircleColTest::update(double time)
{
	for (auto& c : units)
	{
		c->update(time);
	}

	for (size_t i = 0; i < numUnits; i++)
	{
		units[i]->getShape().setFillColor(sf::Color::Green);
	}
	
	for (int i = 0; i < numUnits; i++)
	{
		for (int j = i+1; j < numUnits; j++)
		{
			if (units[i]->IsColliding(units[j]->getHitBox()))
			{
				units[i]->getShape().setFillColor(sf::Color::Red);
				units[j]->getShape().setFillColor(sf::Color::Red);


				//float newVelX1 = (2 * radi * units[j]->getVel().x) / (2*radi);
				//float newVelY1 = (2 * radi * units[j]->getVel().y) / (2*radi);

				//float newVelX2 = (2 * radi * units[i]->getVel().x) / (2 * radi);
				//float newVelY2 = (2 * radi * units[i]->getVel().y) / (2 * radi);
				//
				//units[i]->setVel(sf::Vector2f(newVelX1, newVelY1));
				//units[j]->setVel(sf::Vector2f(newVelX2, newVelY2));
				//
			} 
		}
	}
}

void CircleColTest::draw(sf::RenderWindow* screen)
{
	for (auto& c : units)
	{
		c->draw(screen);
	}
}
