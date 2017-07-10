
#ifndef LEVEL_H
# define LEVEL_H

# include <ncurses.h>
# include "Player.h"
# include "Enemy.h"
# include "YEnemy.h"
# include "ZEnemy.h"
# include "PowerUp.h"

# define BORDER_W 2
# define BORDER_H 1
# define ADDCH(y, x, c) mvwaddch(stdscr, y + BORDER_H, x + BORDER_W, c)
# define ROUND(x) (floor(x + 0.5))

# define EMPTYSPACE ' '
# define DEATHSPACE '*'

# define DEBUG(i, x, y) mvprintw(i, Level::getWidth() + BORDER_W * 2, "%-30s: %-10i", x, y)

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
	static int			_highscore;

	static void			_addBorder();
	static void			_win_resize();
	static void			_startScreen();
	static void			_endScreen();
	static void			_setHighscore();
	static void			_saveHighscore();
};

#endif
