#ifndef WEAPON_H
# define WEAPON_H

#include "Bullet.h"

class					Weapon
{
public:
	Weapon();
	Weapon(Weapon const &ref);
	~Weapon();

	void				attack(void);

	Weapon				&operator=(Weapon const &rhs);
	int					getCD(void) const;
	Bullet				*getBullet(void) const;

private:
	int					_cooldown;
	Bullet				*_bullet;
};

#endif