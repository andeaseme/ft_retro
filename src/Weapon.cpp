#include "Weapon.h"

Weapon::Weapon(void)
{
	_bullet = new Bullet;
	_cooldown = 100;
}

Weapon::Weapon(Weapon const &ref)
{
	*this = ref;
}

Weapon::~Weapon(void)
{
	delete _bullet;
}

void		Weapon::attack(void)
{
	//check cooldown then make copies of each 
	//bullet and place into maps
}

Weapon		&Weapon::operator=(Weapon const &rhs)
{
	_cooldown = rhs.getCD();
	_bullet = rhs.getBullet();
}

int			Weapon::getCD(void) const
{
	return(_cooldown);
}

Bullet		*Weapon::getBullet(void) const
{
	//gets full list
	return(_bullet);
}
