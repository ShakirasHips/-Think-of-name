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
#include "PixelPerfectTest.h"
#include "QuadTreeTest.h"
#define log(x) std::cout << x << std::endl

int main()
{

	//CircleColTest test(200, 10);
	QuadTreeColTest test(300, 10, 2, 5);
	test.init();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Window Memes");

	sf::Font font;
	font.loadFromFile("fonts/arial.ttf");
	sf::Text fps("FPS", font, 50);
	fps.setFillColor(sf::Color::Black);


	auto start = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed;
	while (window.isOpen())
	{
		std::chrono::duration<double> elapsed = std::chrono::high_resolution_clock::now() - start;
		start = std::chrono::high_resolution_clock::now();

		sf::Event e;
		window.pollEvent(e);
		test.update(elapsed.count());
		if (e.type == sf::Event::Closed)
			window.close();

		test.draw(&window);
		window.draw(fps);
		window.display();
		window.clear(sf::Color::White);
		fps.setString(std::to_string((int)(1/elapsed.count())));
	}
	
	return 0;
}