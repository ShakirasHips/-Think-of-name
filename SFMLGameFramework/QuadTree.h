#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <SFML\Main.hpp>

struct Point
{
	float x;
	float y;

	Point(float x = 400.0f, float y = 300.0f): x(x), y(y)
	{

	}
};

template<typename T>
struct Data
{
public:
	Point center;
	float Maxradi;
	T* data;

	Data(Point center, float Maxradi, T* data): center(center), Maxradi(Maxradi), data(data)
	{

	};

	Point getPos()
	{
		return center;
	}
};

struct AABB
{
	Point center;
	float width, height;
	sf::RectangleShape shape;

	AABB(Point center = Point(), float width = 800.0f, float height = 600.0f): center(center), width(width), height(height)
	{
		shape.setSize(sf::Vector2f(width, height));
		shape.setPosition(sf::Vector2f(center.x - width/2, center.y - height / 2));
		shape.setOutlineColor(sf::Color::Black);
		shape.setOutlineThickness(1);
		shape.setFillColor(sf::Color::Transparent);
	}

	bool contains(const Point& point) const 
	{
		if (point.x < center.x + width && point.x > center.x - width)
			if (point.y < center.y + height && point.y > center.y - height)
				return true;
		return false;
	}


	bool contains(const Point& point, float radi) const
	{
		if (point.x < center.x + width && point.x > center.x - width)
			if (point.y < center.y + height && point.y > center.y - height)
				return true;
		return true;
	}


	void draw(sf::RenderWindow* window)
	{
		window->draw(shape);
	}
};

template <class T>
class QuadTree
{
private:
	QuadTree* TopLeft;
	QuadTree* TopRight;
	QuadTree* BottomLeft;
	QuadTree* BottomRight;
	static constexpr int MAXDEPTH = 2;
	static constexpr int MAXOBJECTSPERNODE = 10;


	std::vector<Data<T>> objects;
	int objectCount;
	int depth;
	AABB box;

public:
	QuadTree<T>();
	QuadTree<T>(AABB box,int);
	~QuadTree();

	void subDivide();
	bool addObject(Data<T>);
	void clear();
	void draw(sf::RenderWindow* window);
	int getObjectCount()
	{
		return objectCount;
	}
	//void updateObjects(void(*update)(void *));
	std::vector<QuadTree<T>*>& getLeafs(std::vector<QuadTree<T>*>&);
	std::vector<Data<T>> getObjects();

};

template<class T>
QuadTree<T>::QuadTree()
{
	TopLeft = nullptr;
	TopRight = nullptr;
	BottomLeft = nullptr;
	box = AABB();
	BottomRight = nullptr;
	objects = std::vector<Data<T>>();
	objectCount = 0;
}

template<class T>
QuadTree<T>::QuadTree(AABB box , int depth)
{
	TopLeft = nullptr;
	TopRight = nullptr;
	BottomLeft = nullptr;
	BottomRight = nullptr;
	this->box = box;
	objects = std::vector<Data<T>>();
	this->depth = depth;
	objectCount = 0;
}

template<class T>
QuadTree<T>::~QuadTree()
{
	if (TopLeft)
		delete TopLeft;
	if (TopRight)
		delete TopRight;
	if (BottomLeft)
		delete BottomLeft;
	if (BottomRight)
		delete BottomRight;
}

//TODO: add objects to each of the sub trees, then clear parent
template<class T>
inline void QuadTree<T>::subDivide()
{
	int temp = 0;
	float width = box.width / 2;
	float height = box.height / 2;
	temp = this->depth + 1;

	TopLeft = new QuadTree<T>(AABB(Point(box.center.x - width/2, box.center.y - height/2), width, height), temp); 
	TopRight = new QuadTree<T>(AABB(Point(box.center.x + width/2, box.center.y - height/2), width, height), temp);
	BottomLeft = new QuadTree<T>(AABB(Point(box.center.x - width/2, box.center.y + height/2), width, height), temp);
	BottomRight = new QuadTree<T>(AABB(Point(box.center.x + width / 2, box.center.y + height / 2), width, height), temp);

	for (auto& d: objects)
	{
		addObject(d);
	}
	objects.clear();

}

template<class T>
inline bool QuadTree<T>::addObject(Data<T> data)
{
	if (!this->box.contains(data.center))
	{
		return false;
	}

	if (objectCount < MAXOBJECTSPERNODE || depth == MAXDEPTH)
	{
		objects.push_back(data);
		objectCount++;
		return true;
	}

	if (!this->TopLeft)
	{
		subDivide();
	}
	
	if (TopLeft->addObject(data))
		return true;
	if (TopRight->addObject(data))
		return true;
	if (BottomLeft->addObject(data))
		return true;
	if (BottomRight->addObject(data))
		return true;

	return false;

}

template<class T>
void QuadTree<T>::clear()
{
	objects.clear();
	if (TopLeft)
		TopLeft->clear();
	if (TopRight)
		TopRight->clear();
	if (BottomLeft)
		BottomLeft->clear();
	if (BottomRight)
		BottomRight->clear();
}


template<class T>
inline void QuadTree<T>::draw(sf::RenderWindow* window)
{
	box.draw(window);
	if (TopLeft)
		TopLeft->draw(window);
	if (TopRight)
		TopRight->draw(window);
	if (BottomLeft)
		BottomLeft->draw(window);
	if (BottomRight)
		BottomRight->draw(window);
}

template<class T>
inline std::vector<QuadTree<T>*>& QuadTree<T>::getLeafs(std::vector<QuadTree<T>*>& temp)
{
	if (TopLeft || TopRight || BottomLeft || BottomRight)
	{
		if (TopLeft)
			TopLeft->getLeafs(temp);
		if (TopRight)
			TopRight->getLeafs(temp);
		if (BottomLeft)
			BottomLeft->getLeafs(temp);
		if (BottomRight)
			BottomRight->getLeafs(temp);
	}
	else
	{
		temp.push_back(this);
	}
	return temp;
}

template<class T>
std::vector<Data<T>> QuadTree<T>::getObjects()
{
	return objects;
}


//template<class T>
//std::vector<Data<T>> QuadTree<T>::getObjects()
//{
//	return objects;
//}


