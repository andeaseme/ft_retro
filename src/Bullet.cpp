#include "Bullet.h"

Bullet::Bullet(void)
{
	this->_location = 0;
	this->_sprite = "O";
	this->_hp = 1;
	this->_damage = 1;
	this->_x = -1;
	this->_y = -1;
	this->_dx = 1;
	this->_dy = 0;
	this->_ready = false;
}

Bullet::Bullet(Bullet const &ref)
{
	*this = ref;
}

Bullet		&Bullet::operator=(Bullet const &rhs)
{
	
}