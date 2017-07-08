
#ifndef COLLIDABLE_H
# define COLLIDABLE_H

# include <string>

class				Collidable
{
public:

	Collidable();
	Collidable(Collidable const &ref);
	~Collidable();

	Place			*getLoc() const;
	std::string		getSprite() const;

	void			move(int xdif, int ydif);

	Collidable		&operator =(Collidable const &rhs);

private:
	Place			*_location;
	std::string		_sprite;
}

#endif
