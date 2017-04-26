// SnakeGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake!", sf::Style::Default, settings);
	vector <Snake> snakes;
	Snake s;
	for (int i = 0; i < 10; i++)
	{
		snakes.push_back(Snake());
		snakes.at(i).setPosition(sf::Vector2f(s.getPosition().x - 20*i, s.getPosition().y));
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		window.clear();
		for (int i = 0; i < snakes.size(); i++)
		{
			snakes.at(i).move();
			window.draw(snakes.at(i));
		}
		window.display();
	}
	return 0;
}

