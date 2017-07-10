
#include "PWeapon.h"

bool			PWeapon::attack(float x, float y)
{
	Collidable	*a, *b, *c, *d, *e, *f, *g;
	if (false == _autofire)
		return (false);
	if (_count < _cooldown) //some condition
	{
		_count++;
		return (false);
	}
	_count = 0; //some condition
	switch (this->_bulletCount)
	{
		case 1:
			a = new Bullet(x, y);
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
