
#include "Enemy.h"

Enemy::Enemy() : Collidable::Collidable(0, 0)
{
	this->_sprite = 'W';
	this->setSpeed(0.0, 1.0);
	this->_wep = 0;
	this->_damage = 1;
}

Enemy::Enemy(float const x, float const y) :
		Collidable::Collidable(x, y)
{
	this->_sprite = 'W';
	this->setSpeed(0.0, 1.0);
	this->_wep = 0;
	this->_damage = 1;
}

Weapon			*Enemy::getWeapon()
{
	return this->_wep;
}

void			Enemy::switchWeapon(Weapon *ptr)
{
	if (this->_wep)
		delete this->_wep;
	this->_wep = ptr;
}

void			Enemy::move()
{
	Collidable::move();
	if (this->_wep)
		this->_wep->attack(this->_x, this->_y - 1);
}
