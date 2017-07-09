
#ifndef LEVEL_H
# define LEVEL_H

class					Level
{
public:

	Level();
	Level(int const width, int const height);
	Level(Level const &ref);
	~Level();

	Level				&operator =(Level const &rhs);

	static void			addObject(Collidable *obj);
	static void			deleteObject(Collidable *obj);
	static Place		*getPlace(unsigned int const x, unsigned int const y);

private:
	static int			_width;
	static int			_height;
	static Place		*_map;
	static Collidable	**_objects;
};

#endif
