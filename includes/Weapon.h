#ifndef WEAPON_H
# define WEAPON_H

class					Weapon
{
public:
	Weapon();
	Weapon(Weapon const &ref);
	~Weapon();

	Weapon				&operator=(Weapon const &rhs);

	void				attack(void);

private:
	int					_cooldown;
	Bullet				*_bullet;
};

#endif