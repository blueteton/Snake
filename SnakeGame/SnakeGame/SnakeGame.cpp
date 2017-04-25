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
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake!");
	vector <Snake> snakes;
	Snake s;
	for (int i = 0; i < 10; i++)
	{
		snakes.push_back(s.increaseLength());
		//snakes.at(i).setVelocities(s.getvX(), s.getvY());
		snakes.at(i).updateOrigin();
		snakes.at(i).setPosition(sf::Vector2f(s.getPosition().x - 10, s.getPosition().y - 10));
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		s.move();
		window.clear();
		window.draw(s);
		for (int i = 0; i < snakes.size(); i++)
		{
			window.draw(snakes.at(i));
		}
		window.display();
	}
	return 0;
}

