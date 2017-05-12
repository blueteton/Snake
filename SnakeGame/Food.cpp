#include "stdafx.h"
#include "Food.h"
#include <SFML\Graphics.hpp>

Food::Food(int x, int y)
{
	setSize(sf::Vector2f(20, 20));
	updateOrigin();
	setFillColor(sf::Color::Red);
	setPosition(sf::Vector2f(x, y));
}


Food::~Food()
{
}


//set the origin of food object
void Food::updateOrigin()
{
	setOrigin(sf::Vector2f(getLocalBounds().width / 2, getLocalBounds().height / 2));
}