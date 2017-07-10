#ifndef WEAPON_H
# define WEAPON_H

#include "Bullet.h"

class					Weapon
{
public:
	Weapon();
	Weapon(Weapon const &ref);
	~Weapon();

	virtual bool		attack(float x, float y);

	Weapon				&operator=(Weapon const &rhs);
	int					getCD(void) const;
	void				flipAutofire(void);
	void				upPower();
	void				resetPower();

protected:
	int					_cooldown;
	int					_bulletCount;
	int					_count;
	bool				_autofire;
};

#endif