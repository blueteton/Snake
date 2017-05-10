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


void Snake::move()
{
	setPosition(sf::Vector2f(getPosition().x + vX, getPosition().y + vY));
}


void Snake::setVelocities(double x, double y)
{
	vX = x;
	vY = y;
}


void Snake::updateOrigin()
{
	setOrigin(sf::Vector2f(getLocalBounds().width / 2, getLocalBounds().height / 2));
}


Snake Snake::increaseLength()
{
	Snake snake;
	return snake;
}


double Snake::getvX()
{
	return vX;
}


double Snake::getvY()
{
	return vY;
}