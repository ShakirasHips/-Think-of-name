#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Audio.hpp>

void soundTest()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Window Memes");
	window.setKeyRepeatEnabled(false);

	sf::SoundBuffer buff;
	buff.loadFromFile("Sound Files/1.wav");

	sf::SoundBuffer buff2;
	buff2.loadFromFile("Sound Files/2.wav");

	sf::SoundBuffer buff3;
	buff3.loadFromFile("Sound Files/3.wav");

	sf::Sound sound1;
	sound1.setBuffer(buff);

	sf::Sound sound2;
	sound2.setBuffer(buff2);

	sf::Sound sound3;
	sound3.setBuffer(buff3);

	sf::Music song;
	song.openFromFile("Sound Files/Journey.wav");
	song.setVolume(0.5);

	while (window.isOpen())
	{
		sf::Event e;
		window.pollEvent(e);

		if (e.type == sf::Event::Closed)
			window.close();

		if (e.type == sf::Event::KeyPressed)
		{
			if (e.key.code == sf::Keyboard::Num1)
				sound1.play();
			if (e.key.code == sf::Keyboard::Num2)
				sound2.play();
			if (e.key.code == sf::Keyboard::Num3)
				sound3.play();
			if (e.key.code == sf::Keyboard::Num0)
			{
				if (song.getStatus() == sf::Music::Paused || song.getStatus() == sf::Music::Stopped)
				{
					song.play();
				}
				else if (song.getStatus() == sf::Music::Playing)
				{
					song.pause();
				}
				else
				{
					song.play();
				}

			}
		}
	}
}