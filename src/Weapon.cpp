
#include "Weapon.h"
#include "Level.h"

Weapon::Weapon(void)
{
	_cooldown = 3;
	_count = _cooldown;
	_bullet = new Bullet();
	Level::deleteObject(_bullet);
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
	if (false == _autofire)
		return ;
	if (_count < _cooldown) //some condition
	{
		_count++;
		return ;
	}
	_count = 0; //some condition
	Collidable	*b = new Bullet(*_bullet);
	b->setLocation(x, y);
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

void		Weapon::flipAutofire(void)
{
	_autofire = (true == _autofire) ? false : true;
	_count = _cooldown;
}
