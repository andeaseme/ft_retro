
#include "Place.h"

Place::Place(unsigned int x, unsigned int y, Collidable *obj)
{
	this->_x = x;
	this->_y = y;
	this->_obj = obj;
}

Place::Place(Place const &ref)
{
	*this = ref;
}

Place::~Place()
{
}

void			Place::setObj(Collidable *obj)
{
	this->_obj = obj;
}

Collidable		*Place::getObj() const
{
	return this->_obj;
}

unsigned int	Place::getX() const
{
	return this->_x;
}

unsigned int	Place::getY() const
{
	return this->_y;
}

Place			&Place::operator =(Place const &rhs)
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	this->_obj = rhs.getObj();
	return *this;
}
