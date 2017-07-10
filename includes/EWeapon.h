#ifndef EWEAPON_H
# define EWEAPON_H

# include "Weapon.h"

class					EWeapon : public Weapon
{
public:
	EWeapon();

	bool				attack(float x, float y);

};

#endif