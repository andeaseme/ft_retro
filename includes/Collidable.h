
#ifndef COLLIDABLE_H
# define COLLIDABLE_H

# include <string>
# include "Place.h"

class				Collidable
{
public:

	Collidable(); // Needs to setLocation, setSprite, setSpeed
	Collidable(float const x, float const y); // Needs to setSprite
	Collidable(Collidable const &ref); // Needs to setSprite, setLocation. Copies speed, not location
	virtual			~Collidable();

	void			setLocation(Place *loc); // Adds self to place as well
	void			setSprite(std::string const sprite);
	void			setPosition(float const x, float const y);
	void			setSpeed(float const dx, float const dy);
	Place			*getLoc() const;
	std::string		getSprite() const;
	float			getDX() const;
	float			getDY() const;
	bool			isReady() const;

	virtual void	move();
	virtual void	collide(Collidable *ref);
	virtual int		getCollideDamage() const = 0;
	virtual void	takeCollideDamage(int amount) const = 0;

	Collidable		&operator =(Collidable const &rhs);

protected:
	Place			*_location;
	std::string		_sprite;
	unsigned int	_hp;
	unsigned int	_damage;
	float			_x;
	float			_y;
	float			_dx;
	float			_dy;
	bool			_ready; // Determines if it can be rendered / moved. Fixed by setLocation + setSprite
};

#endif
