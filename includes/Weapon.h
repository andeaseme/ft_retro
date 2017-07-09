#ifndef WEAPON_H
# define WEAPON_H

#include "Bullet.h"

class					Weapon
{
public:
	Weapon();
	Weapon(Weapon const &ref);
	~Weapon();

	bool				attack(float x, float y);

	Weapon				&operator=(Weapon const &rhs);
	int					getCD(void) const;
	void				flipAutofire(void);

protected:
	int					_cooldown;
	int					_count;
	bool				_autofire;
};

#endif