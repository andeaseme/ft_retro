#ifndef BULLET_H
# define BULLET_H

#include "Collidable.h"

class			Bullet : public Collidable
{
public:
	Bullet(void);
	Bullet(float const x, float const y);
	Bullet(Bullet const &ref);

	void		setHoming(bool set);

	void		move();

private:
	bool		_homing;
};

#endif