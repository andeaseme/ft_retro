
#include "Level.h"
#include "Bullet.h"

Bullet::Bullet(void) : Collidable::Collidable()
{
	this->_sprite = 'O';
	this->setSpeed(0.0, -1.0);
	this->_damage = 1;
}

Bullet::Bullet(float const x, float const y) :
		Collidable::Collidable(x, y)
{
	this->_sprite = 'O';
	this->setSpeed(0.0, -1.0);
	this->_damage = 1;
}

Bullet::Bullet(Bullet const &ref)
{
	*this = ref;
}