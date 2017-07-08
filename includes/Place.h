
#ifndef PLACE_H
# define PLACE_H

class				Place
{
public:

	Place();
	Place(unsigned int x, unsigned int y, Collidable *obj = 0);
	Place(Place const &ref);
	~Place();

	Collidable		*getObj() const;
	unsigned int	getX() const;
	unsigned int	getY() const;

	Place			&operator =(Place const &rhs);

private:
	Collidable		*_obj;
	unsigned int	_x;
	unsigned int	_y;
};

#endif
