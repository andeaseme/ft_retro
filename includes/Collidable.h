
#ifndef COLLIDABLE_H
# define COLLIDABLE_H

# include <string>
# include "Place.h"

class				Collidable
{
public:

	Collidable();
	Collidable(float const x, float const y);
	Collidable(Collidable const &ref);
	~Collidable();

	void			setLocation(Place const *loc);
	void			setSprite(std::string const sprite);
	void			setPosition(float const x, float const y);
	void			setSpeed(float const dx, float const dy);
	Place			*getLoc() const;
	std::string		getSprite() const;

	virtual void	move();

	Collidable		&operator =(Collidable const &rhs);

protected:
	Place			*_location;
	std::string		_sprite;
	float			_x;
	float			_y;
	float			_dx;
	float			_dy;
};

#endif
