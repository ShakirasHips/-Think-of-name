#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Audio.hpp>

void imageTest()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Window Memes");

	sf::Texture backgroundtexture;
	backgroundtexture.loadFromFile("img/background.jpg");
	sf::Sprite background(backgroundtexture);

	sf::Texture img1Texture;
	img1Texture.loadFromFile("img/dog.jpg", sf::IntRect(0, 0, 1280, 360));
	sf::Sprite img1(img1Texture);
	img1.setScale(sf::Vector2f(0.5, 0.5));

	sf::Texture img2Texture;
	img2Texture.loadFromFile("img/dog.jpg", sf::IntRect(1280 / 2, 360, 1280, 360));
	sf::Sprite img2(img2Texture);
	img2.setScale(sf::Vector2f(0.5, 0.5));

	sf::Texture img3Texture;
	img3Texture.loadFromFile("img/dog.jpg", sf::IntRect(0, 360, 1280 / 2, 720));
	sf::Sprite img3(img3Texture);
	img3.setScale(sf::Vector2f(0.5, 0.5));

	bool showBackground = true;

	while (window.isOpen())
	{
		sf::Event e;
		window.pollEvent(e);

		if (e.type == sf::Event::Closed)
			window.close();
		if (e.type == sf::Event::KeyPressed)
		{
			if (e.key.code == sf::Keyboard::Num0)
				showBackground = !showBackground;
			if (e.key.code == sf::Keyboard::Num1)
				img1.setPosition(sf::Vector2f(rand() % 800, rand() % 600));
			if (e.key.code == sf::Keyboard::Num2)
				img2.setPosition(sf::Vector2f(rand() % 800, rand() % 600));
			if (e.key.code == sf::Keyboard::Num3)
				img3.setPosition(sf::Vector2f(rand() % 800, rand() % 600));
		}

		if (showBackground)
			window.draw(background);

		window.draw(img1);
		window.draw(img2);
		window.draw(img3);
		window.display();
		window.clear(sf::Color::White);
	}
}