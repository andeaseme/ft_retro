
#include "PointShot.h"

PointShot::PointShot(void) : EWeapon::EWeapon()
{
	_cooldown = 100;
	_count = _cooldown;
	_sprite = '.';
}
