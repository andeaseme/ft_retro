
#include "PointShot.h"

PointShot::PointShot(void) : EWeapon::EWeapon()
{
	_cooldown = 100;
	_count = _cooldown;
	_sprite = '.';
}

#define ABS(x)	((x < 0) ? -x : x)

void		PointShot::setSpeed(float x, float y)
{
	_dx = Level::getPlayer()->getX() - x;
	_dy = Level::getPlayer()->getY() - y;
	while(ABS(_dx) + ABS(_dy) > 1)
	{
		_dx /= 2;
		_dy /= 2;
	}
	DEBUG(0, "dx", _dx);
	DEBUG(1, "dy", _dy);
}