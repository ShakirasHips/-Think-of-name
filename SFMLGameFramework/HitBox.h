#pragma once
#include <SFML\Graphics.hpp>

class HitBox
{
private:
	sf::Vector2f pos;
	sf::Vector2f sides;
public:
	HitBox(sf::Vector2f, sf::Vector2f);
	~HitBox();

	sf::Vector2f& getPos();
	sf::Vector2f getSides();

	float getWidth();
	float getHeight();
	void drawHitBox(sf::RenderWindow* w);

	HitBox getHitBox();

	bool IsColliding(HitBox);
};

