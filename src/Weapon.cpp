
#include "Weapon.h"
#include "Level.h"

Weapon::Weapon(void)
{
	_cooldown = 2;
	_count = _cooldown;
	_autofire = true;
	_dx = 0;
	_dy = 0;
	_sprite = '^';
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
	if (_count < _cooldown)
	{
		_count++;
		return (false);
	}
	_count = 0;
	Collidable	*b = new Bullet(x, y);
	this->setSpeed(x, y);
	if (_dx || _dy)
		b->setSpeed(_dx, _dy);
	b->setSprite(_sprite);
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

void		Weapon::setSpeed(float x, float y)
{
	(void)x;
	(void)y;
}

void		Weapon::setSprite(char sprite)
{
	_sprite = sprite;
}

void		Weapon::flipAutofire(void)
{
	_autofire = (true == _autofire) ? false : true;
	_count = _cooldown;
}
