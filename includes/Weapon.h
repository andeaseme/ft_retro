#ifndef WEAPON_H
# define WEAPON_H

#include "Bullet.h"

class					Weapon
{
public:
	Weapon();
	Weapon(Weapon const &ref);
	~Weapon();

	void				attack(float x, float y);

	Weapon				&operator=(Weapon const &rhs);
	int					getCD(void) const;
	Bullet				*getBullet(void) const;

protected:
	int					_cooldown;
	int					_count;
	Bullet				*_bullet;
};

#endif