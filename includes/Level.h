
#ifndef LEVEL_H
# define LEVEL_H

# include <curses.h>
# include "Player.h"

class					Level
{
public:

	Level();
	Level(Level const &ref);
	~Level();

	Level				&operator =(Level const &rhs);

	static void			init();

	static void			addObject(Collidable *obj);
	static void			deleteObject(Collidable *obj);

	static Place		*getPlace(unsigned int const x, unsigned int const y);
	static Player		*getPlayer();
	static int			getWidth();
	static int			getHeight();

	static void			updatePlayer();
	static void			updateObjects();
	static void			cleanupObjects();
	static void			render();
	static void			loop();

private:
	static Player		*_player;
	static int			_width;
	static int			_height;
	static Place		**_map;
	static Collidable	**_objects;
	static int			_numObjects;
};

#endif
