
#include <chrono>
#include <thread>
#include <math.h>
#include "Level.h"

Player			*Level::_player = 0;
int				Level::_width = 81;
int				Level::_height = 71;
Place			**Level::_map = new Place*[Level::_width * Level::_height];
Collidable		**Level::_objects = new Collidable*[500];
int				Level::_numObjects = 0;

Level::Level()
{
}

Level::Level(Level const &ref)
{
}

Level::~Level()
{
}

Level			&Level::operator =(Level const &rhs)
{
	return *this;
}

void			Level::init()
{
	for (int i = 0; i < Level::getWidth() * Level::getHeight(); ++i)
		Level::_map[i] = new Place(i % Level::getWidth(),
			i / Level::getWidth());
	for (int i = 0; i < 500; ++i)
		Level::_objects[i] = 0;
	Level::_player = new Player();
	Level::_player->switchWeapon(new Weapon());
	initscr();
	cbreak();
	noecho();
	curs_set(false);
	clear();
	keypad(stdscr, true);

	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK); //default
	init_pair(2, COLOR_BLACK, COLOR_WHITE); //border
	init_pair(3, COLOR_CYAN, COLOR_BLACK); //player
	init_pair(4, COLOR_RED, COLOR_BLACK); //enemy
	init_pair(5, COLOR_YELLOW, COLOR_BLACK); //bullet
	_startScreen();
	_addBorder();
	attron(COLOR_PAIR(1));
	nodelay(stdscr, true);
}

void			Level::addObject(Collidable *obj)
{
	if (obj == 0 || Level::_numObjects >= 500)
		return;
	for (int i = 0; i < Level::_numObjects; ++i)
		if (Level::_objects[i] == obj)
			return;
	Level::_objects[Level::_numObjects++] = obj;
}

void			Level::deleteObject(Collidable *obj)
{
	if (obj == 0 || Level::_numObjects <= 0)
		return;
	for (int i = 0; i < Level::_numObjects; ++i)
	{
		if (Level::_objects[i] == obj)
		{
			delete Level::_objects[i];
			Level::_numObjects--;
			Level::_objects[i] = Level::_objects[Level::_numObjects];
			Level::_objects[Level::_numObjects] = 0;
			return;
		}
	}
}

Place			*Level::getPlace(unsigned int const x, unsigned int const y)
{
	if (x >= Level::getWidth() || y >= Level::getHeight())
		return 0;
	return Level::_map[y * Level::getWidth() + x];
}

Player			*Level::getPlayer()
{
	return Level::_player;
}

int				Level::getWidth()
{
	return Level::_width;
}

int				Level::getHeight()
{
	return Level::_height;
}

#define P1 Level::_player

void			Level::updatePlayer()
{
	int			ch;

	ch = getch();
	attron(COLOR_PAIR(3));
	ADDCH(ROUND(P1->getY()), ROUND(P1->getX()), EMPTYSPACE);
	if (0 == P1 || 0 == P1->getHP())
	{
		attron(COLOR_PAIR(2));
		mvprintw(0, 0, "GAME OVER !");
	}
	else
	{
		switch (ch)
		{
			case 'w':
			case KEY_UP:
				P1->setLocation(P1->getX(), ROUND(P1->getY() - 1.0));
				break;
			case 'a':
			case KEY_LEFT:
				P1->setLocation(ROUND(P1->getX() - 1.0), P1->getY());
				break;
			case 's':
			case KEY_DOWN:
				P1->setLocation(P1->getX(), ROUND(P1->getY() + 1.0));
				break;
			case 'd':
			case KEY_RIGHT:
				P1->setLocation(ROUND(P1->getX() + 1.0), P1->getY());
				break;
			case ' ':
				P1->getWeapon()->flipAutofire();
				break;
		}
		ADDCH(ROUND(P1->getY()), ROUND(P1->getX()), P1->getSprite());
	}
	attron(COLOR_PAIR(1));
}

void			Level::updateObjects()
{
	for (int i = 0; i < Level::_numObjects; ++i)
		Level::_objects[i]->move();
}

void			Level::cleanupObjects()
{
	attron(COLOR_PAIR(1));
	for (int i = 0; i < Level::_numObjects; ++i)
		if (Level::_objects[i]->getHP() == 0)
		{
	if (0 == Level::getPlace(ROUND(_objects[i]->getX()),
					ROUND(_objects[i]->getY())))
			{
				ADDCH(ROUND(_objects[i]->getX()), 
					ROUND(_objects[i]->getY()), EMPTYSPACE);
			}
			Level::deleteObject(Level::_objects[i]);
		}
}

void			Level::render()
{
	_win_resize();
	_addBorder(); //patch
	refresh();
}

void			Level::loop()
{
	int			i;

	Collidable 	*e;
	i = 0;
	while (++i)
	{
		if (0 == i % 15)
			e = new Enemy(std::rand() % Level::getWidth(), 0); //test enemy
		Level::updatePlayer();
		Level::updateObjects();
		Level::cleanupObjects();
		Level::render();
		std::this_thread::sleep_for(std::chrono::milliseconds(25));
	}
}

void			Level::_addBorder()
{
	attron(COLOR_PAIR(2));
	mvprintw(0, 0, "%*c", Level::getWidth() + 2 * BORDER_W, ' ');
	mvprintw(Level::getHeight() + BORDER_H, 0, "%*c", 
			Level::getWidth() + 2 * BORDER_W, ' ');
	for (int i = 1; i < Level::getHeight() + BORDER_H; ++i)
	{
		mvprintw(i, 0, "  ");
		mvprintw(i, Level::getWidth() + BORDER_W, "  ");
	}
	attron(COLOR_PAIR(1));
}

void	Level::_win_resize(void)
{
	static int	h_prev;
	static int	w_prev;
	int			h;
	int			w;

	getmaxyx(stdscr, h, w);
	if (h != h_prev || w != w_prev)
	{
		h_prev = h;
		w_prev = w;
		clear();
		_addBorder();
	}
}

void	Level::_startScreen(void)
{
	int		offset;
	int		i;

	i = Level::getHeight() / 3;
	offset = (Level::getWidth() - 41) / 2;
	clear();
	attron(COLOR_PAIR(1));
	mvprintw(i    , offset, "    ______                  __          ");
	mvprintw(i + 1, offset, "   / __/ /_      ________  / /__________");
	mvprintw(i + 2, offset, "  / /_/ __/     / ___/ _ \\/ __/ ___/ __ \\");
	mvprintw(i + 3, offset, " / __/ /_      / /  /  __/ /_/ /  / /_/ /");
	mvprintw(i + 4, offset, "/_/  \\__/_____/_/   \\___/\\__/_/   \\____/");
	mvprintw(i + 5, offset, "       /______/                          ");
	mvprintw(Level::getHeight() / 2, (Level::getWidth() - 23) / 2, "Press Any Key to Begin!");
	refresh();
	getch();
}
