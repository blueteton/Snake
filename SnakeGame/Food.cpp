#include "stdafx.h"
#include "Food.h"


Food::Food(int x, int y)
{
	setSize(sf::Vector2f(10, 10));
	updateOrigin();
	setFillColor(sf::Color::Red);
	setPosition(sf::Vector2f(x,y));
}


Food::~Food()
{
}


void Food::updateOrigin()
{
	setOrigin(sf::Vector2f(getLocalBounds().width / 2, getLocalBounds().height / 2));
}