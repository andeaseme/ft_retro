
#ifndef ENEMY_H
# define ENEMY_H

# include "Collidable.h"
# include "Weapon.h"

class				Enemy : public Collidable
{
public:

	Enemy();
	Enemy(float const x, float const y);
	~Enemy();

	Weapon			*getWeapon();
	void			switchWeapon(Weapon *ptr);

	void			move();

private:
	Weapon			*_wep;
};

#endif
