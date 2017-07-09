
#include "Level.h"
#include "Bullet.h"

Bullet::Bullet(void) : Collidable::Collidable()
{
	this->setSprite('O');
	this->setSpeed(0.0, -1.2);
	this->_damage = 1;
}

Bullet::Bullet(Bullet const &ref)
{
	*this = ref;
}