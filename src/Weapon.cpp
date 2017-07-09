
#include "Weapon.h"
#include "Level.h"

Weapon::Weapon(void)
{
	_cooldown = 3;
	_count = _cooldown;
	_autofire = true;
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
	if (_count < _cooldown) //some condition
	{
		_count++;
		return (false);
	}
	_count = 0; //some condition
	Collidable	*b = new Bullet(x, y);
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

void		Weapon::flipAutofire(void)
{
	_autofire = (true == _autofire) ? false : true;
	_count = _cooldown;
}
