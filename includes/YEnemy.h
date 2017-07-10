
#ifndef YENEMY_H
# define YENEMY_H

# include "Enemy.h"

class				YEnemy : virtual public Enemy
{
public:
	YEnemy();
	YEnemy(float const x, float const y);
};

#endif