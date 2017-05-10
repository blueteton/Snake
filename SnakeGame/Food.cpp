#include "stdafx.h"
#include "Food.h"
#include <SFML\Graphics.hpp>

Food::Food(int x, int y)
{

}


Food::~Food()
{
}


void Food::updateOrigin()
{
	setOrigin(sf::Vector2f(getLocalBounds().width / 2, getLocalBounds().height / 2));
}