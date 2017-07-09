
#ifndef ENEMY_H
# define ENEMY_H

# include "Collidable.h"

class				Enemy : public Collidable
{
public:

	Enemy();
	Enemy(float const x, float const y);
	Enemy(Enemy const &ref);
	~Enemy();

	void			move();
};

#endif
