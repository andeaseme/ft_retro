
#ifndef COLLIDABLE_H
# define COLLIDABLE_H

# include <string>

class				Collidable
{
public:

	Collidable();
	Collidable(Collidable const &ref);
	~Collidable();

	void			setSprite(std::string const sprite);
	Place			*getLoc() const;
	std::string		getSprite() const;

	void			move();

	Collidable		&operator =(Collidable const &rhs);

protected:
	Place			*_location;
	std::string		_sprite;
	float			_x;
	float			_y;
	float			_dx;
	float			_dy;
}

#endif
