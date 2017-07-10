
#include "Weapon.h"
#include "Level.h"

Weapon::Weapon(void)
{
	_cooldown = 4;
	_count = _cooldown;
	_autofire = true;
	_dx = 0;
	_dy = 0;
	_sprite = '^';
	_bulletCount = 1;
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
	switch (this->_bulletCount)
	{
		case 1:
			a = new Bullet(x, y);
			if (_dx || _dy)
				a->setSpeed(_dx, _dy);
			a->setSprite(_sprite);
			break;
		case 2:
			a = new Bullet(x - 1, y);
			b = new Bullet(x + 1, y);
			break;
		case 3:
			a = new Bullet(x, y - 1);
			b = new Bullet(x - 1, y);
			c = new Bullet(x + 1, y);
			break;
		case 4:
			a = new Bullet(x - 1, y - 2);
			b = new Bullet(x + 1, y - 2);
			c = new Bullet(x - 2, y - 1);
			d = new Bullet(x + 2, y - 1);
			break;
		case 5:
			a = new Bullet(x - 1, y - 2);
			b = new Bullet(x + 1, y - 2);
			c = new Bullet(x - 2, y - 1);
			d = new Bullet(x + 2, y - 1);
			e = new Bullet(x, y - 3);
			break;
		case 6:
			a = new Bullet(x - 1, y - 2);
			b = new Bullet(x + 1, y - 2);
			c = new Bullet(x - 2, y - 1);
			d = new Bullet(x + 2, y - 1);
			e = new Bullet(x - 3, y - 2);
			e->setSpeed(-0.3, -1.0);
			f = new Bullet(x + 3, y - 2);
			f->setSpeed(0.3, -1.0);
			break;
		case 7:
			a = new Bullet(x - 1, y - 2);
			b = new Bullet(x + 1, y - 2);
			c = new Bullet(x - 2, y - 1);
			d = new Bullet(x + 2, y - 1);
			e = new Bullet(x, y - 3);
			f = new Bullet(x - 3, y - 2);
			f->setSpeed(-0.3, -1.0);
			g = new Bullet(x + 3, y - 2);
			g->setSpeed(0.3, -1.0);
			break;
	}
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

void		Weapon::upPower()
{
	if (this->_cooldown > this->_bulletCount)
		this->_cooldown--;
	else if (this->_bulletCount < 7)
	{
		this->_bulletCount++;
		this->_cooldown += this->_bulletCount * 1.5 + 3;
	}
}

void		Weapon::resetPower()
{
	this->_cooldown = 4;
	this->_bulletCount = 1;
}
