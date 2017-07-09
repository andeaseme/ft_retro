
#include "Level.h"

Player			*Level::_player = 0;
int				Level::_width = 31;
int				Level::_height = 81;
Place			**Level::_map = new Place*[Level::_width * Level::_height];
Collidable		**Level::_objects = new Collidable*[500];

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
}
