
#include "Weapon.h"
#include "Level.h"

Weapon::Weapon(void)
{
	_cooldown = 4;
	_count = _cooldown;
	_autofire = true;
	_dx = 0;
	_dy = 0;
	_sprite = '^';
	_bulletCount = 1;
}

Weapon::Weapon(Weapon const &ref)
{
	*this = ref;
}

Weapon::~Weapon(void)
{
}

bool		Weapon::attack(float x, float y)
{
	if (false == _autofire)
		return (false);
	if (_count < _cooldown)
	{
		_count++;
		return (false);
	}
	_count = 0; //some condition
	Collidable *b = new Bullet(x, y);
	return (true);
}

Weapon		&Weapon::operator=(Weapon const &rhs)
{
	_cooldown = rhs.getCD();
	_count = _cooldown;
	return (*this);
}

int			Weapon::getCD(void) const
{
	return(_cooldown);
}

void		Weapon::setSpeed(float x, float y)
{
	(void)x;
	(void)y;
}

void		Weapon::setSprite(char sprite)
{
	_sprite = sprite;
}

void		Weapon::flipAutofire(void)
{
	_autofire = (true == _autofire) ? false : true;
	_count = _cooldown;
}

void		Weapon::upPower()
{
	if (this->_cooldown > this->_bulletCount)
		this->_cooldown--;
	else if (this->_bulletCount < 7)
	{
		this->_bulletCount++;
		this->_cooldown += this->_bulletCount * 1.5 + 3;
	}
}

void		Weapon::resetPower()
{
	this->_cooldown = 4;
	this->_bulletCount = 1;
}
