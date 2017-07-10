
#ifndef PLAYER_H
# define PLAYER_H

# include "Collidable.h"
# include "Weapon.h"

class				Player : public Collidable
{
public:

	Player();
	Player(float const x, float const y);

	Weapon			*getWeapon();
	void			switchWeapon(Weapon *ptr);
	int				getScore() const;
	void			addScore();
	void			move();

private:
	Weapon			*_wep;
	int				_score;
};

#endif
