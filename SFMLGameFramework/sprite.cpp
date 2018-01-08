#include "sprite.h"
#include <algorithm>
#include <iostream>
#include <exception>

sprite::sprite(sf::Sprite s, sf::Vector2f pos, sf::Vector2f sides): HitBox(pos, sides)
{
	sp = s;
	sp.setPosition(pos);

}


sprite::~sprite()
{
}

void sprite::init()
{
	const sf::Texture * t = sp.getTexture();
	sf::Image data = t->copyToImage();

	for (size_t i = 0; i < data.getSize().x; i++)
	{
		std::vector<bool> temp;
		for (size_t j = 0; j < data.getSize().y; j++)
		{
			if (data.getPixel(i, j).a > 0)
				temp.push_back(true);
			else
				temp.push_back(false);
		}
		hasPixel.push_back(temp);
		temp.clear();
	}

	for (size_t i = 0; i < data.getSize().x; i++)
	{
		for (size_t j = 0; j < data.getSize().y; j++)
		{
			if (data.getPixel(i, j).a > 0)
			{
					if (i == 0 || i == data.getSize().x || j == 0 || j == data.getSize().y || i-1 == 0 || i+1 == data.getSize().x || j-1 == 0 || j+1 == data.getSize().y)
					{
						BorderPixelData.push_back(pixelData(i, j));
					}
					else if (data.getPixel(i - 1, j).a == 0 || data.getPixel(i, j - 1).a == 0 || data.getPixel(i + 1, j).a == 0 || data.getPixel(i, j + 1).a == 0)
					{
						BorderPixelData.push_back(pixelData(i, j));
					}
			}
			
		}
	}
	std::cout << BorderPixelData.size() << std::endl;
}

void sprite::update(double t)
{
	sp.setPosition(getPos());
}

void sprite::draw(sf::RenderWindow *w)
{
	w->draw(sp);
}

std::vector<std::vector<bool>> sprite::getHasPixel()
{
	return hasPixel;
}

std::vector<pixelData> sprite::getBorderPixelData()
{
	return BorderPixelData;
}

sf::Sprite& sprite::getSprite()
{
	return sp;
}



bool sprite::isColliding(sprite s)
{
	if (this->IsColliding(s.getHitBox()))
	{
		int x1 = std::max(s.getPos().x, this->getPos().x);
		int y1 = std::max(s.getPos().y, this->getPos().y);
		int x2 = std::min(s.getPos().x+s.getWidth(), this->getPos().x + this->getWidth());
		int y2 = std::min(s.getPos().y + s.getHeight(), this->getPos().y + this->getHeight());
		
		for (size_t i = x1; i < x2; i++)
		{
			for (size_t j = y1; j < y2; j++)
			{
				if (hasPixel[i - getPos().x][j - getPos().y] && s.getHasPixel()[i - s.getPos().x][j - s.getPos().y])
					return true;
			}
		}
	}

	return false;
}

bool sprite::isCollidingBorderPixels(sprite s)
{
	if (this->IsColliding(s.getHitBox()))
	{
		for (auto& a: BorderPixelData)
		{
			for (auto b: s.getBorderPixelData())
			{
				if (a.x + getPos().x == b.x + s.getPos().x && a.y + getPos().y == b.y + s.getPos().y)
				{
					return true;
				}
			}
		}
	}

	return false;
}
