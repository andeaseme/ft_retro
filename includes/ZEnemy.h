
#ifndef ZENEMY_H
# define ZENEMY_H

# include "Enemy.h"

class				ZEnemy : public Enemy
{
public:

	ZEnemy();
	ZEnemy(float const x, float const y);

	void			move();
};

#endif
