
#include "Level.h"

Player::Player() : Collidable::Collidable(
		Level::getWidth() / 2,
		3 * Level::getHeight() / 4
	)
{
	this->_sprite = 'P';
	this->setSpeed(0.0, 0.0);
	this->_wep = 0;
}

Player::Player(float const x, float const y)
	: Collidable::Collidable(x, y)
{
	this->_sprite = 'P';
	this->setSpeed(0.0, 0.0);
	this->_wep = 0;
}

Weapon			*Player::getWeapon()
{
	return this->_wep;
}

void			Player::switchWeapon(Weapon *ptr)
{
	if (this->_wep)
		delete this->_wep;
	this->_wep = ptr;
}

void			Player::move()
{
	Collidable::move();
	if (this->_wep)
		this->_wep->attack(this->_x, this->_y - 2);
}
