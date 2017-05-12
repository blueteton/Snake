#include "stdafx.h"
#include "Snake.h"
#include <SFML\Graphics.hpp>


Snake::Snake()
{
	setRadius(10);
	setFillColor(sf::Color::White);		
	setPosition(sf::Vector2f(500,500));
	updateOrigin();
	setVelocities(1, 0);
}


Snake::~Snake()
{
}


//moves the snake by adding the velocity to the position
void Snake::move()
{
	setPosition(sf::Vector2f(getPosition().x + vX, getPosition().y + vY));
}


//set the x and y velocity
//preconditions: double x velocity, double y velocity
void Snake::setVelocities(double x, double y)
{
	vX = x;
	vY = y;
}


//set the orgin of the snake object
void Snake::updateOrigin()
{
	setOrigin(sf::Vector2f(getLocalBounds().width / 2, getLocalBounds().height / 2));
}



//returns the x velocity
double Snake::getvX()
{
	return vX;
}


//returns the y velocity
double Snake::getvY()
{
	return vY;
}