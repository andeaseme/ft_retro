
#include "Level.h"
#include "Bullet.h"

Bullet::Bullet(void) : Collidable::Collidable()
{
	this->_sprite = '^';
	this->setSpeed(0.0, -1.0);
	this->_damage = 1;
	this->_enemy = false;
	this->_killable = true;
}

Bullet::Bullet(float const x, float const y) :
		Collidable::Collidable(x, y)
{
	this->_sprite = '^';
	this->setSpeed(0.0, -1.0);
	this->_damage = 1;
	this->_enemy = false;
	this->_killable = true;
}

Bullet::Bullet(Bullet const &ref)
{
	*this = ref;
}

void			Bullet::setHoming(bool set)
{
	this->_homing = set;
	this->_enemy = set;
	this->_killable = !set;
}

#define ABS(x)	((x < 0) ? -x : x)

void			Bullet::move()
{
	float		ox, oy;

	if (this->_homing)
	{
		_dx = Level::getPlayer()->getX() - this->_x;
		_dy = Level::getPlayer()->getY() - this->_y;
		ox = 0;
		oy = 0;
		if (ABS(_dx) > ABS(_dy))
		{
			if (_dx < 0)
				ox = -0.5;
			else if (_dx > 0)
				ox = 0.5;
			if (_dy < 0)
				oy = -0.18;
			else if (_dy > 0)
				oy = 0.18;
		}
		else
		{
			if (_dy < 0)
				oy = -0.5;
			else if (_dy > 0)
				oy = 0.5;
			if (_dx < 0)
				ox = -0.18;
			else if (_dx > 0)
				ox = 0.18;
		}
		_dx = ox;
		_dy = oy;
	}
	this->Collidable::move();
}