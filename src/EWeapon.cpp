
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
	Bullet	*a;
	if (!_autofire)
		return (false);
	if (_count < _cooldown)
	{
		_count++;
		return (false);
	}
	a = new Bullet(x, y);
	a->setHoming(true);
	_count = 0;
	return (true);
}
