#ifndef BULLET_H
# define BULLET_H

#include "Collidable.h"

class			Bullet : public Collidable
{
public:
	Bullet(void);
	Bullet(Bullet const &ref);

	Bullet		&operator=(Bullet const &rhs);
	
};

#endif