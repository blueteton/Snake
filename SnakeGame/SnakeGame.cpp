// SnakeGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Snake.h"
#include "Food.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

void changeDirection(double, double, sf::RenderWindow*, vector <Snake>*, vector <Food>*);
void drawObjects(sf::RenderWindow*, vector <Snake>*, vector <Food>*);
bool snakeCollision(vector <Snake>*);


int _tmain(int argc, _TCHAR* argv[])
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake!", sf::Style::Default, settings);
	window.setFramerateLimit(240);
	vector <Snake> snakes;
	vector <Food> food;
	Snake s;
	for (int i = 0; i < 30; i++)
	{
		snakes.push_back(Snake());
		snakes.at(i).setPosition(sf::Vector2f(s.getPosition().x - 30*i, s.getPosition().y));
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
				changeDirection(0, -1, &window, &snakes, &food);

			if (event.key.code == sf::Keyboard::Down)
				changeDirection(0, 1, &window, &snakes, &food);

			if (event.key.code == sf::Keyboard::Left)
				changeDirection(-1, 0, &window, &snakes, &food);

			if (event.key.code == sf::Keyboard::Right)
				changeDirection(1, 0, &window, &snakes, &food);
		}

		if (snakeCollision(&snakes))
		{
			window.clear();
			break;
		}

		window.clear();

		for (int i = 0; i < snakes.size(); i++)
			snakes.at(i).move();

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

		if (snakeCollision(s))
			cout << "true" << endl;

		drawObjects(window, s, f);

		window->display(); 
	}
}


bool snakeCollision(vector <Snake> *s)
{
	for (int i = 1; i < s->size(); i++)
	{
		if (s->at(0).getGlobalBounds().intersects(s->at(i).getGlobalBounds()))
			return true;
	}
	return false;
}


void drawObjects(sf::RenderWindow *window, vector <Snake> *s, vector <Food> *f)
{
	for (int i = 0; i < s->size(); i++)
		window->draw(s->at(i));

	for (int i = 0; i < f->size(); i++)
		window->draw(f->at(i));
}
