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
	virtual void		setSpeed(float x, float y);
	void				setSprite(char sprite);
	void				flipAutofire(void);
	void				upPower();
	void				resetPower();

protected:
	int					_cooldown;
	int					_bulletCount;
	int					_count;
	bool				_autofire;
	float				_dx;
	float				_dy;
	char				_sprite;
};

#endif