
#include "EWeapon.h"
#include "Level.h"

EWeapon::EWeapon(void) : Weapon::Weapon()
{
	_cooldown = 100;
	_count = _cooldown;
	_autofire = true;
	_dx = 0;
	_dy = 0;
	_sprite = '@';
	_bulletCount = 1;
}

bool		EWeapon::attack(float x, float y)
{
	Collidable	*a, *b, *c, *d, *e, *f, *g;
	if (false == _autofire)
		return (false);
	if (_count < _cooldown)
	{
		_count++;
		return (false);
	}
	this->setSpeed(x, y);
	_count = 0;
	if (_dx || _dy)
		a->setSpeed(_dx, _dy);
	a->setSprite(_sprite);
	return (true);
}
