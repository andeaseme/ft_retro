
#include "Level.h"

Player::Player() : Collidable::Collidable(
		Level::getWidth() / 2,
		3 * Level::getHeight() / 4
	)
{
	this->_sprite = 'A';
	this->setSpeed(0.0, 0.0);
	this->_wep = 0;
	this->_damage = 2;
	this->_score = 0;
	this->_lives = 3;
	this->_enemy = false;
	this->_killable = false;
}

Player::Player(float const x, float const y)
	: Collidable::Collidable(x, y)
{
	this->_sprite = 'A';
	this->setSpeed(0.0, 0.0);
	this->_wep = 0;
	this->_damage = 2;
	this->_score = 0;
	this->_lives = 3;
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

int				Player::getLives() const
{
	return this->_lives;
}

void			Player::loseLife()
{
	this->_lives--;
	this->_hp = 1;
}

void			Player::gainLife()
{
	this->_lives++;
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
