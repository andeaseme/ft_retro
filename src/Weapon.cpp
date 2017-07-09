#include "Weapon.h"

Weapon::Weapon(void)
{
	_cooldown = 5;
	_count = _cooldown;
	_bullet = new Bullet;
}

Weapon::Weapon(Weapon const &ref)
{
	*this = ref;
}

Weapon::~Weapon(void)
{
	delete _bullet;
}

void		Weapon::attack(float x, float y)
{
	if (_count < _cooldown)
	{
		_count++;
		return ;
	}
	_count = 0;
	Bullet	b = new Bullet(_bullet);
	b.setLocation(x, y);
}

Weapon		&Weapon::operator=(Weapon const &rhs)
{
	_cooldown = rhs.getCD();
	_count = _cooldown;
	_bullet = rhs.getBullet();
	return (*this);
}

int			Weapon::getCD(void) const
{
	return(_cooldown);
}

Bullet		*Weapon::getBullet(void) const
{
	return(_bullet);
}
