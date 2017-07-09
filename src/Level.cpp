
#include <chrono>
#include <thread>
#include <math.h>
#include "Level.h"

Player			*Level::_player = 0;
int				Level::_width = 61;
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

#define ROUND(x) (floor(x + 0.5))
#define P1 Level::_player

void			Level::updatePlayer()
{
	int			ch;

	nodelay(stdscr, true);
	ch = getch();
	mvwaddch(stdscr, ROUND(P1->getY()), ROUND(P1->getX()), ACS_BULLET);
	switch (ch)
	{
		case 'w':
			P1->setLocation(P1->getX(), P1->getY() - 1);
			break;
		case 'a':
			P1->setLocation(floor(P1->getX() - 0.9), P1->getY());
			break;
		case 's':
			P1->setLocation(P1->getX(), floor(P1->getY() + 1.9));
			break;
		case 'd':
			P1->setLocation(floor(P1->getX() + 1.9), P1->getY());
			break;
		case ' ':
			P1->getWeapon()->flipAutofire();
			break;
	}
	mvwaddch(stdscr, ROUND(P1->getY()), ROUND(P1->getX()), P1->getSprite());
}

void			Level::updateObjects()
{
	for (int i = 0; i < Level::_numObjects; ++i)
		Level::_objects[i]->move();
}

void			Level::cleanupObjects()
{
	for (int i = 0; i < Level::_numObjects; ++i)
		if (Level::_objects[i]->getHP() == 0)
			Level::deleteObject(Level::_objects[i]);
}

void			Level::render()
{
	refresh();
}

void			Level::loop()
{
	for (int i = 0; i < 1000; ++i)
	{
		Level::updatePlayer();
		Level::updateObjects();
		Level::cleanupObjects();
		Level::render();
		std::this_thread::sleep_for(std::chrono::milliseconds(6));
	}
}
