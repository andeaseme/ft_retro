
#include "Level.h"
#include "Bullet.h"

Bullet::Bullet(void) : Collidable::Collidable()
{
	this->setSprite('o');
	this->setSpeed(0.0, -1.0);
	this->_damage = 1;
}

Bullet::Bullet(Bullet const &ref)
{
	*this = ref;
}