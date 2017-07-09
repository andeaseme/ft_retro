#include "Weapon.h"
#include "Level.h"

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
	Place	*place;

	if (_count < _cooldown) //some condition
	{
		_count++;
		return ;
	}
	_count = 0; //some condition
	Collidable	*b = new Bullet(*_bullet);
	place = Level::getPlace((int)x, (int)y);
	place->setObj(b);
	b->setLocation(place);
	Level::addObject(b);
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
