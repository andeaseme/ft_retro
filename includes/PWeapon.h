
#ifndef PWEAPON_H
# define PWEAPON_H

# include "Weapon.h"

class				PWeapon : public Weapon
{
public:

	bool			attack(float x, float y);
};

#endif
