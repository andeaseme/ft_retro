
#include <chrono>
#include <thread>
#include "Level.h"

Player			*Level::_player = 0;
int				Level::_width = 31;
int				Level::_height = 81;
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
	initscr();
	cbreak();
	noecho();
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
			Level::_objects[i] = Level::_objects[--(Level::_numObjects)];
			Level::_objects[Level::_numObjects] = 0;
			return;
		}
	}
}

Place			*Level::getPlace(unsigned int const x, unsigned int const y)
{
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

void			Level::updatePlayer()
{
	// Here goes the input stuff
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
	int			h, w;

	h = Level::_height;
	w = Level::_width;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (Level::_map[i * w + j]->getObj())
				mvwaddch(stdscr, i, j, Level::_map[i * w + j]->getObj()->getSprite());
}

void			Level::loop()
{
	for (int i = 0; i < 10; ++i)
	{
		Level::updatePlayer();
		Level::updateObjects();
		Level::cleanupObjects();
		Level::render();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}
