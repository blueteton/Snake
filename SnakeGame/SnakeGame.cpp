// SnakeGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Snake.h"
#include"Food.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;

vector <Snake> changeDirection(double, double, vector <Snake>);

sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake!");

int _tmain(int argc, _TCHAR* argv[])
{

	window.setFramerateLimit(480);

	vector <Snake> snakes;
	vector <Snake> *snakesPtr = &snakes; 
	Snake s;

	Food food(rand() % 1000, rand() % 1000);

	for (int i = 0; i < 10; i++)
	{
		snakes.push_back(Snake());
		snakes.at(i).setPosition(sf::Vector2f(s.getPosition().x - 21 *i, s.getPosition().y));
		snakes.at(i).setVelocities(1, 0);
	}

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Up)
				snakes = changeDirection(0, -1, snakes);

			if (event.key.code == sf::Keyboard::Down)
				snakes = changeDirection(0, 1, snakes);

			if (event.key.code == sf::Keyboard::Left)
				snakes = changeDirection(-1, 0, snakes);

			if (event.key.code == sf::Keyboard::Right)
				snakes = changeDirection(1, 0, snakes);
		}

		window.clear();

		for (int i = 0; i < snakes.size(); i++)
		{
			snakes.at(i).move();
			window.draw(snakes.at(i));
		}
		window.draw(food);
		window.display();
	}
	return 0;
}


vector <Snake> changeDirection(double vX, double vY, vector <Snake> s)
{
	int x = s.at(0).getPosition().x;
	int y = s.at(0).getPosition().y;
	s.at(0).setVelocities(vX, vY);
	bool finished = false;
	int i = 1;

	while (!finished)
	{
		if (s.at(i).getPosition().x == x && s.at(i).getPosition().y == y)
		{
			s.at(i).setVelocities(vX, vY);
			i++;
		}
		if (i == s.size())
			finished = true;
		window.clear();
		for (int j = 0; j < s.size(); j++)
		{
			s.at(j).move();
			window.draw(s.at(j));
		}
		window.display();
	}
	return s;
}


bool snakeCollision(vector <Snake> s)
{
	
}