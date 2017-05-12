#pragma once
#include <SFML\Graphics.hpp>

using namespace std;

class Snake : public sf::CircleShape
{
public:
	Snake();
	~Snake();
	void updateOrigin();
	void move();
	double getvX();
	double getvY();
	void setVelocities(double, double);

private:
	double vX;
	double vY;
	
};

