#ifndef BULLET_H
# define BULLET_H

#include "Collidable.h"

class			Bullet : public Collidable
{
public:
	Bullet(void);
	Bullet(float const x, float const y);
	Bullet(Bullet const &ref);
	~Bullet(void);

	Bullet		&operator=(Bullet const &rhs);
	
	void		move(void);
};

#endif