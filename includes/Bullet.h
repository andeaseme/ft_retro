#ifndef BULLET_H
# define BULLET_H

class			Bullet : public Collidable
{
publici:
	Bullet(float const x, float const y);
	Bullet(Bullet const &ref);
	~Bullet(void);

	Bullet		&operator=(Bullet const &rhs);
	
	void		move(void);
}

#endif