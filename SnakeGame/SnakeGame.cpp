// SnakeGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Snake.h"
#include "Food.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

void changeDirection(double, double, sf::RenderWindow*, vector <Snake>*, Food*);
void drawObjects(sf::RenderWindow*, vector <Snake>*, Food*);
bool snakeCollision(vector <Snake>*);
bool snakeFoodCollision(vector <Snake>*, Food*);

int _tmain(int argc, _TCHAR* argv[])
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake!", sf::Style::Default, settings); // creation of the widnow
	window.setFramerateLimit(240);
	
	srand(time(NULL));
	vector <Snake> snakes;
	Food food(rand() % 1000, rand() % 1000); // ranomly places food on screen

	snakes.push_back(Snake());
	for (int i = 1; i < 3; i++)
	{
		snakes.push_back(Snake());
		snakes.at(i).setPosition(sf::Vector2f(snakes.at(0).getPosition().x - 20 * i, snakes.at(0).getPosition().y));
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (event.type == sf::Event::KeyReleased) // detects if a key was released
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
			window.close();

		if (snakeFoodCollision(&snakes, &food))
		{
			food.setPosition(sf::Vector2f(rand() % 1000, rand() % 1000)); //set a new random postion of food
			snakes.push_back(Snake()); // adds a new snake to the vector

			if (snakes.at(snakes.size() - 2).getvX() == -1 || snakes.at(snakes.size() - 2).getvX() == 1)  //finds the direction of the snake
				snakes.at(snakes.size() - 1).setPosition(sf::Vector2f(snakes.at(snakes.size() - 2).getPosition().x - 20 * //sets the new added snakes position 
				snakes.at(snakes.size() - 2).getvX(), snakes.at(snakes.size() - 2).getPosition().y));

			if (snakes.at(snakes.size() - 2).getvY() == -1 || snakes.at(snakes.size() - 2).getvY() == 1)
				snakes.at(snakes.size() - 1).setPosition(sf::Vector2f(snakes.at(snakes.size() - 2).getPosition().x, //sets the new added snakes position
				snakes.at(snakes.size() - 2).getPosition().y - 20 * snakes.at(snakes.size() - 2).getvY()));

			snakes.at(snakes.size() - 1).setVelocities(snakes.at(snakes.size() - 2).getvX(), snakes.at(snakes.size() - 2).getvY()); //sets the new added snakes velocity 
																																	//of the snake before it
		}

		window.clear();

		for (int i = 0; i < snakes.size(); i++)
			snakes.at(i).move();

		drawObjects(&window, &snakes, &food);

		window.display();
	}
	return 0;
}


//changes the direction of the snake so that the rest of it follows
//preconditions: double x velocity,  double y velocity, renderWidnow pointer, vector Snake pointer, and Food pointer
void changeDirection(double vX, double vY, sf::RenderWindow *window, vector <Snake> *s, Food *f)
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
			window->close();

		drawObjects(window, s, f);

		window->display(); 
	}
}


//detects if the snake has collided with itself
//precondition: vector Snake pointer
bool snakeCollision(vector <Snake> *s)
{
	for (int i = 2; i < s->size(); i++)
	{
		if (s->at(0).getGlobalBounds().intersects(s->at(i).getGlobalBounds()))
			return true;
	}

	if (s->at(0).getPosition().x == 0 || s->at(0).getPosition().x == 1000)
		return true;
	else if (s->at(0).getPosition().y == 0 || s->at(0).getPosition().y == 1000)
		return true;

	return false;
}


//detects collision of the snake and food
//precoditions: vector Snake pointer, Food pointer
bool snakeFoodCollision(vector <Snake> *s, Food *f)
{
	if (s->at(0).getGlobalBounds().intersects(f->getGlobalBounds()))
		return true;

	return false;
}


//draws all objects on the screen
//preconditions: RenderWindow pointer, vector Snake pointer, Food pointer
void drawObjects(sf::RenderWindow *window, vector <Snake> *s, Food *f)
{
	for (int i = 0; i < s->size(); i++)
		window->draw(s->at(i));
	window->draw(*f);
}
