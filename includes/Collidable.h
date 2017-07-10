
#ifndef COLLIDABLE_H
# define COLLIDABLE_H

# include <string>
# include <curses.h>
# include <iostream>

class				Collidable;

# include "Place.h"

class				Collidable
{
public:

	Collidable(); // Needs to setLocation, setSprite, setSpeed
	Collidable(float const x, float const y); // Needs to setSprite
	Collidable(Collidable const &ref); // Needs to setSprite, setLocation. Copies speed, not location. Avoid
	virtual			~Collidable();

	void			setLocation(Place *loc); // Adds self to place as well
	void			setLocation(float const x, float const y);
	void			setSprite(char const sprite);
	void			setSpeed(float const dx, float const dy);
	unsigned int	getHP() const;
	unsigned int	getDamage() const;
	Place			*getLocation() const;
	char			getSprite() const;
	float			getX() const;
	float			getY() const;
	float			getDX() const;
	float			getDY() const;
	bool			isReady() const;
	bool			isEnemy() const;
	bool			isKillable() const;

	virtual void	move();
	virtual void	collide(Collidable *ref);
	virtual int		getCollideDamage() const;
	virtual void	takeCollideDamage(int amount);

	Collidable		&operator =(Collidable const &rhs); // Best implementation I could do, but still avoid it

protected:
	Place			*_location;
	char			_sprite;
	unsigned int	_hp;
	unsigned int	_damage;
	float			_x;
	float			_y;
	float			_dx;
	float			_dy;
	bool			_ready; // Determines if it can be rendered / moved. Fixed by setLocation + setSprite
	bool			_enemy;
	bool			_killable;
};

#endif
