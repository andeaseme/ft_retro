
#include <math.h>
#include "Level.h"

Enemy::Enemy() : Collidable::Collidable(0, 0)
{
	this->_sprite = 'W';
	this->setSpeed(0.0, 0.3);
	this->_wep = 0;
	this->_damage = 1;
	this->_enemy = true;
}

Enemy::Enemy(float const x, float const y) :
		Collidable::Collidable(x, y)
{
	this->_sprite = 'W';
	this->setSpeed(0.0, 0.3);
	this->_wep = 0;
	this->_damage = 1;
	this->_enemy = true;
}

Enemy::~Enemy()
{
	if (Level::getPlace(ROUND(this->_x), ROUND(this->_y + 1))
		&& std::rand() % 5 == 0)
		PowerUp *power = new PowerUp(ROUND(this->_x), ROUND(this->_y + 1));
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
