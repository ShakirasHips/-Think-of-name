#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>



void EventKeyTest()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Window Memes");
	sf::Event lastEvent;
	window.pollEvent(lastEvent);
	window.setKeyRepeatEnabled(false);
	char out;
	while (window.isOpen())
	{
		sf::Event e;
		window.pollEvent(e);
		if (e.type == sf::Event::Closed)
			window.close();

		if (e.type == sf::Event::KeyPressed)
		{
			out = e.key.code + 97;
			std::cout << "Pressed: " << out << std::endl;
			lastEvent = e;
		}
		if (e.type == sf::Event::KeyReleased)
		{
			if (e.key.code != lastEvent.key.code)
			{
				lastEvent = e;
				out = e.key.code + 97;
				std::cout << "Released: " << out << std::endl;
			}
		}
		lastEvent = e;
	}
}

void RealTimeKeyPressed()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Window Memes");
	std::string out = "";
	std::string last = out;
	while (window.isOpen())
	{
		sf::Event e;
		window.pollEvent(e);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			out.append("Key1: 1\n");
		else
			out.append("Key1: 0\n");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			out.append("Key2: 1\n");
		else
			out.append("Key2: 0\n");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
			out.append("Key3: 1\n");
		else
			out.append("Key3: 0\n");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			out.append("Key4: 1\n");
		else
			out.append("Key4: 0\n");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
			out.append("Key5: 1\n");
		else
			out.append("Key5: 0\n");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
			out.append("Key6: 1\n");
		else
			out.append("Key6: 0\n");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
			out.append("Key7: 1\n");
		else
			out.append("Key7: 0\n");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
			out.append("Key8: 1\n");
		else
			out.append("Key8: 0\n");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
			out.append("Key9: 1\n");
		else
			out.append("Key9: 0\n");
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
			out.append("Key0: 1\n");
		else
			out.append("Key0: 0\n");

		if (e.type == sf::Event::Closed)
			window.close();

		if (!(out == last))
		{
			system("cls");
			std::cout << out << std::endl;
			last = out;
			out.clear();
		}
		out.clear();

	}

}