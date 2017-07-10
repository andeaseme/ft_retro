
#include <math.h>
#include "Level.h"

PowerUp::PowerUp(float const x, float const y) :
	Collidable::Collidable(x, y)
{
	this->_sprite = '$';
	this->setSpeed(0.0, +0.24);
	this->_damage = 0;
	this->_hp = 1;
	this->_enemy = true;
	this->_killable = true;
}

int				PowerUp::getCollideDamage() const
{
	return 0;
}

void			PowerUp::takeCollideDamage(int amount)
{
	this->_hp = 0;
	Level::getPlayer()->getWeapon()->upPower();
}
