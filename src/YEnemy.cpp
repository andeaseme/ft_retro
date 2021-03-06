
#include "YEnemy.h"
#include "PointShot.h"

YEnemy::YEnemy() : Enemy::Enemy()
{
	this->setSprite('Y');
	this->setSpeed(0, 0.2);
	this->_hp = 1;
	this->_damage = 1;
	this->switchWeapon(new PointShot());
}

YEnemy::YEnemy(float const x, float const y) : Enemy::Enemy(x, y)
{
	this->setSprite('Y');
	this->setSpeed(0, 0.2);
	this->_hp = 1;
	this->_damage = 1;
	this->switchWeapon(new PointShot());
}

YEnemy::~YEnemy()
{
	if (this->_wep)
		delete this->_wep;
}