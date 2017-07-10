
#ifndef POWER_UP_H
# define POWER_UP_H

# include "Collidable.h"

class				PowerUp : public Collidable
{
public:

	PowerUp(float const x, float const y);

	int				getCollideDamage() const;
	void			takeCollideDamage(int amount);
};

#endif
