
#include <math.h>
#include "Level.h"
#include "ZEnemy.h"

ZEnemy::ZEnemy() : Enemy::Enemy()
{
	this->setSprite('Z');
	this->setSpeed(0, 0.6);
	this->_hp = 2;
	this->_damage = 1;
	this->_wep = 0;
}

ZEnemy::ZEnemy(float const x, float const y) : Enemy::Enemy(x, y)
{
	this->setSprite('Z');
	this->setSpeed(0, 0.6);
	this->_hp = 2;
	this->_damage = 1;
	this->_wep = 0;
}

void			ZEnemy::move()
{
	int			dy;
	float		dx;

	dy = ROUND(Level::getPlayer()->getY() - this->_y);
	if (this->_dy != 0.0)
	{
		if (dy == 0)
		{
			this->_dy = 0;
			dx = 0.6;
		}
		else if (dy == 1)
			dx = 0.5;
		else if (dy == 2)
			dx = 0.4;
		else if (dy == 3)
		{
			this->_dy = 0.4;
			dx = 0.3;
		}
		else if (dy == 4)
		{
			this->_dy = 0.5;
			dx = 0.2;
		}
		if (Level::getPlayer()->getX() > this->_x)
			this->_dx = dx;
		else
			this->_dx = -dx;
	}
	this->Collidable::move();
}
