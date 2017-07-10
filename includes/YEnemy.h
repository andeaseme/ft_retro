
#ifndef YENEMY_H
# define YENEMY_H

# include "Enemy.h"

class				YEnemy : public Enemy
{
public:

	YEnemy();
	YEnemy(float const x, float const y);
	~YEnemy();
};

#endif