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

void changeDirection(double, double, vector <Snake>*, vector <Food>*);
void drawObjects(sf::RenderWindow*, vector <Snake>*, vector <Food>*);
bool snakeCollision(vector <Snake>*);

int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake!");
	window.setFramerateLimit(240);

	vector <Snake> snakes;
	vector <Food> food;
	Snake s;

	for (int i = 0; i < 10; i++)
	{
		snakes.push_back(Snake());
		snakes.at(i).setPosition(sf::Vector2f(s.getPosition().x - 21 *i, s.getPosition().y));
		snakes.at(i).setVelocities(1, 0);
	}

	food.push_back(Food(rand()%1000, rand()%1000));

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
				changeDirection(0, -1, &snakes, &food);

			if (event.key.code == sf::Keyboard::Down)
				changeDirection(0, 1, &snakes, &food);

			if (event.key.code == sf::Keyboard::Left)
				changeDirection(-1, 0, &snakes, &food);

			if (event.key.code == sf::Keyboard::Right)
				changeDirection(1, 0, &snakes, &food);
		}

		window.clear();
		drawObjects(&window, &snakes, &food);
		window.display();
	}
	return 0;
}


void changeDirection(double vX, double vY, sf::RenderWindow *window, vector <Snake> *s, vector <Food> *f)
{
	int x = s->at(0).getPosition().x;
	int y = s->at(0).getPosition().y;
	s->at(0).setVelocities(vX, vY);
	bool finished = false;
	int i = 1;

	while (!finished)
	{
		if (s->at(i).getPosition().x == x && s->at(i).getPosition().y == y)
		{
			s->at(i).setVelocities(vX, vY);
			i++;
		}

		if (i == s->size())
			finished = true;

		window->clear();

		for (int j = 0; j < s->size(); j++)
			s->at(j).move();

		drawObjects(window, s, f);

		window->display();
	}
}


bool snakeCollision(vector <Snake> *s)
{
	for (int i = 1; i < s->size(); i++)
	{
		//if (s->at(0.get )
	}
	return true;
}


void drawObjects(sf::RenderWindow *window, vector <Snake> *s, vector <Food> *f)
{
	for (int i = 0; i < s->size(); i++)
		window->draw(s->at(i));

	for (int i = 0; i < f->size(); i++)
		window->draw(f->at(i));
}