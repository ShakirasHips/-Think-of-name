#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Main.hpp>
#include <SFML\System.hpp>
#include "KeyBoardTest.h"
#include "SoundTest.h"
#include "TextureTest.h"
#include "Circle.h"
#include <chrono>
#include "CircleColTest.h"
#include "Rectangle.h"
#include "RectColTest.h"
#include "sprite.h"

#define log(x) std::cout << x << std::endl

void PixelPerfectTest()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Window Memes");

	auto start = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed;

	sf::Font font;
	font.loadFromFile("fonts/arial.ttf");
	sf::Text fps("FPS", font, 50);
	fps.setFillColor(sf::Color::Black);

	sf::Texture t;
	t.loadFromFile("img/Sprite_2.png");

	sf::Sprite a, b;
	a.setTexture(t);
	b.setTexture(t);

	sprite player(a, sf::Vector2f(0, 0), sf::Vector2f(120, 120));
	sprite object(b, sf::Vector2f(200, 150), sf::Vector2f(120, 120));
	player.init();
	object.init();
	window.setKeyRepeatEnabled(false);

	bool colType = true;

	while (window.isOpen())
	{
		std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
		start = std::chrono::high_resolution_clock::now();

		sf::Event e;
		window.pollEvent(e);

		if (e.type == sf::Event::Closed)
			window.close();


		object.drawHitBox(&window);
		object.draw(&window);
		player.drawHitBox(&window);
		player.draw(&window);


		player.getPos().x = sf::Mouse::getPosition(window).x;
		player.getPos().y = sf::Mouse::getPosition(window).y;
		player.update(0);
		object.update(0);

		if (e.type == sf::Event::KeyPressed)
			if (e.key.code == sf::Keyboard::C)
				colType = !colType;
		
		if (colType)
		{
			if (player.isCollidingBorderPixels(object))
				log("Yes");
			else
				log("NO");
		}
		else
		{
			if (player.isColliding(object))
				log("Yes");
			else
				log("NO");
		}
		

		window.draw(fps);
		window.display();
		window.clear(sf::Color::White);
		fps.setString(std::to_string((int)(1 / elapsed.count())));
	}
}