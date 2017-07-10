
#include "PointShot.h"

PointShot::PointShot(void) : EWeapon::EWeapon()
{
	_cooldown = 84;
	_count = _cooldown;
	_sprite = '*';
}
