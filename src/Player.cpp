
#include "Level.h"

Player::Player() : Collidable::Collidable(
		Level::getWidth() / 2,
		3 * Level::getHeight() / 4
	)
{
	this->_sprite = 'P';
	this->setSpeed(0.0, 0.0);
	this->_wep = 0;
	this->_damage = 1;
	this->_score = 0;
}

Player::Player(float const x, float const y)
	: Collidable::Collidable(x, y)
{
	this->_sprite = 'A';
	this->setSpeed(0.0, 0.0);
	this->_wep = 0;
	this->_damage = 1;
	this->_score = 0;
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

int				Player::getScore() const
{
	return (this->_score);
}

void			Player::addScore()
{
	this->_score++;
}

void			Player::move()
{
	Collidable::move();
	if (this->_wep)
		this->_wep->attack(this->_x, this->_y - 1);
}
