#pragma once
#include <SFML/Graphics.hpp>

class Food : public sf::RectangleShape
{
public:
	Food(int, int);
	~Food();
	void updateOrigin();
};

