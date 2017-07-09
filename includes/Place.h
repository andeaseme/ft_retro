
#ifndef PLACE_H
# define PLACE_H

# include "Collidable.h"

class				Place
{
public:

	Place(unsigned int x = 0, unsigned int y = 0, Collidable *obj = 0); // Don't use the default x and y
	Place(Place const &ref); // Avoid
	~Place(); // No specific behaviour, objects are freed elsewhere

	void			setObj(Collidable *obj);
	Collidable		*getObj() const;
	unsigned int	getX() const;
	unsigned int	getY() const;

	Place			&operator =(Place const &rhs); // Best implementation I could do, but still avoid it

private:
	Collidable		*_obj;
	unsigned int	_x;
	unsigned int	_y;
};

#endif
