#pragma once
#include <SFML\Graphics.hpp>

using namespace std;

class Snake : public sf::CircleShape
{
public:
	Snake();
	~Snake();
	double vX;
	double vY;
	//vector <Snake> snakes;
	void updateOrigin();
	Snake increaseLength();
	void move();
	double getvX();
	double getvY();
	void setVelocities(double, double);
};

