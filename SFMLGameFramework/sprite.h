#pragma once
#include <SFML/Graphics.hpp>
#include "HitBox.h"

struct pixelData
{
	int x, y;
	pixelData(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
};

class sprite: public HitBox
{
private:
	sf::Sprite sp;
	sf::Vector2f vel;
	std::vector<std::vector<bool>> hasPixel;

	std::vector<pixelData> BorderPixelData;
public:
	sprite(sf::Sprite, sf::Vector2f, sf::Vector2f);
	~sprite();


	void init();
	void update(double);
	void draw(sf::RenderWindow*);
	std::vector<std::vector<bool>> getHasPixel();
	std::vector<pixelData> getBorderPixelData();
	sf::Sprite& getSprite();


	bool isColliding(sprite);
	bool isCollidingBorderPixels(sprite);
};

