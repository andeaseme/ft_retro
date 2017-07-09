
#ifndef LEVEL_H
# define LEVEL_H

# include <curses.h>
# include "Player.h"

# define BORDER_W 2
# define BORDER_H 1
# define ADDCH(y, x, c) mvwaddch(stdscr, y + BORDER_H, x + BORDER_W, c)

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

	static void			_addBorder();
	static void			_win_resize();
	static void			_startScreen();
};

#endif
