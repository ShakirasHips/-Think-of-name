#pragma once
#include "QuadTree.h"
#include "Circle.h"
#include <ctime>



class QuadTreeColTest
{
private:
	int numUnits;
	float radi;
	int MaxDivisions;
	int amountToDivide;
	std::vector<Circle> objects;
	QuadTree<Circle>* units;
public:
	QuadTreeColTest(int numUnits, float radi, int MaxDivisions, int amountToDivide);
	void init();
	void update(double);
	void draw(sf::RenderWindow* screen);

};


QuadTreeColTest::QuadTreeColTest(int numUnits, float radi, int MaxDivisions, int amountToDivide)
{
	this->numUnits = numUnits;
	this->radi = radi;
	this->MaxDivisions = MaxDivisions;
	this->amountToDivide = amountToDivide;
	srand(time(NULL));
}

void QuadTreeColTest::init()
{
	for (size_t i = 0; i < numUnits; i++)
	{
		sf::Vector2f pos;
		pos.x = rand() % 800 - radi;
		pos.y = rand() % 600 - radi;
		sf::Vector2f vel;
		vel.x = rand() % 200 + (-100);
		vel.y = rand() % 200 + (-100);
		objects.push_back(Circle(pos, vel, radi, sf::Color::Green));
	}
}

void QuadTreeColTest::update(double time)
{
	units = new QuadTree<Circle>();
	std::vector<QuadTree<Circle>*> gridContainder;


	for (auto& o : objects)
	{
		o.getShape().setFillColor(sf::Color::Green);
	}
	for (auto& o : objects)
	{
		units->addObject(Data<Circle>(Point(o.getPos().x, o.getPos().y), radi, &o));
	}
	for (auto& c : objects)
	{
		c.update(time);
	}

	for (auto& u : objects)
	{
		u.getShape().setFillColor(sf::Color::Green);
	}
	units->getLeafs(gridContainder);
	int i = 0;
	for (auto& a: gridContainder)
	{
		for (size_t i = 0; i < a->getObjectCount(); i++)
		{
			for (size_t j = i+1; j < a->getObjectCount(); j++)
			{
				if (a->getObjects()[i].data->IsColliding(a->getObjects()[j].data->getHitBox()))
				{
					a->getObjects()[i].data->getShape().setFillColor(sf::Color::Red);
					a->getObjects()[j].data->getShape().setFillColor(sf::Color::Red);
				}
			}
		}
		i++;
	}
	gridContainder.clear();

	
}

void QuadTreeColTest::draw(sf::RenderWindow* window)
{
	//units->draw(window);
	for (auto& u : objects)
	{
		u.draw(window);
	}
	delete units;
}