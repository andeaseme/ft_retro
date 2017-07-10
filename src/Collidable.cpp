
#include <math.h>
#include "Collidable.h"
#include "Level.h"

Collidable::Collidable()
{
	this->_location = 0;
	this->_sprite = 'E';
	this->_hp = 1;
	this->_damage = 0;
	this->_x = -1;
	this->_y = -1;
	this->_dx = 0;
	this->_dy = 0;
	this->_ready = false;
	Level::addObject(this);
}

Collidable::Collidable(float const x, float const y)
{
	Place		*place;

	place = Level::getPlace(ROUND(x), ROUND(y));
	place->setObj(this);
	this->_location = place;
	this->_sprite = 'E';
	this->_hp = 1;
	this->_damage = 0;
	this->_x = x;
	this->_y = y;
	this->_dx = 0;
	this->_dy = 0;
	this->_ready = true;
	Level::addObject(this);
}

Collidable::Collidable(Collidable const &ref)
{
	*this = ref;
	Level::addObject(this);
}

Collidable::~Collidable()
{
	if (this->_location)
		this->_location->setObj(0);
	this->_location = 0;
	this->_ready = false;
}

void			Collidable::setLocation(Place *loc)
{
	if (loc->getObj())
	{
		this->collide(loc->getObj());
		return;
	}
	if (this->_location)
		this->_location->setObj(0);
	loc->setObj(this);
	this->_location = loc;
	this->_x = loc->getX();
	this->_y = loc->getY();
	if (!this->_ready)
	{
		if (this->_sprite != 'E')
			this->_ready = true;
	}
}

void			Collidable::setLocation(float const x, float const y)
{
	Place		*to;

	to = Level::getPlace(ROUND(x), ROUND(y));
	if (!to)
		this->_hp = 0;
	else
		this->setLocation(to);
}

void			Collidable::setSprite(char const sprite)
{
	this->_sprite = sprite;
	if (!this->_ready && (this->_x == -1 || this->_y == -1))
		this->_ready = true;
}

void			Collidable::setSpeed(float const dx, float const dy)
{
	this->_dx = dx;
	this->_dy = dy;
}

unsigned int	Collidable::getHP() const
{
	return this->_hp;
}

unsigned int	Collidable::getDamage() const
{
	return this->_damage;
}

Place			*Collidable::getLocation() const
{
	return this->_location;
}

char			Collidable::getSprite() const
{
	return this->_sprite;
}

float			Collidable::getX() const
{
	return this->_x;
}

float			Collidable::getY() const
{
	return this->_y;
}

float			Collidable::getDX() const
{
	return this->_dx;
}

float			Collidable::getDY() const
{
	return this->_dy;
}

bool			Collidable::isReady() const
{
	return this->_ready;
}

void			Collidable::move()
{
	int			prevX, prevY;
	float		tx, ty;

	if (this->_hp == 0)
		return;
	prevX = ROUND(this->_x);
	prevY = ROUND(this->_y);
	this->_x += this->_dx;
	this->_y += this->_dy;
	tx = this->_x;
	ty = this->_y;
	if (prevX != (int)ROUND(this->_x) || prevY != (int)ROUND(this->_y) || this->_sprite == '+')
	{
		attron(COLOR_PAIR(1));
		ADDCH(prevY, prevX, EMPTYSPACE);
		this->setLocation(tx, ty);
		switch (this->_sprite)
		{
			case '^' :
				attron(COLOR_PAIR(5));
				break ;
			case 'W' :
				attron(COLOR_PAIR(4));
				break ;
			case '+' :
				attron(COLOR_PAIR(3));
				break ;
		}
		if (0 != this->_hp)
			ADDCH(ROUND(this->_y), ROUND(this->_x), this->_sprite);
		this->_x = tx;
		this->_y = ty;
	}
}

void			Collidable::collide(Collidable *ref)
{
	attron(COLOR_PAIR(1));
	this->takeCollideDamage(ref->getCollideDamage());
	ref->takeCollideDamage(this->getCollideDamage());
	if (this->getHP() != 0 && ref->getHP() == 0)
	{
		ref->getLocation()->setObj(0);
		this->setLocation(ref->getLocation());
	}
	else
		ADDCH(ROUND(this->_y), ROUND(this->_x), EMPTYSPACE);
}

int				Collidable::getCollideDamage() const
{
	return this->getDamage();
}

void			Collidable::takeCollideDamage(int amount)
{
	if (amount < 0)
		return;
	else if (amount > this->_hp)
		this->_hp = 0;
	else
		this->_hp -= amount;
}

Collidable		&Collidable::operator =(Collidable const &rhs)
{
	this->_location = 0;
	this->_sprite = rhs.getSprite();
	this->_hp = rhs.getHP();
	this->_damage = rhs.getDamage();
	this->_x = -1;
	this->_y = -1;
	this->_dx = rhs.getDX();
	this->_dy = rhs.getDY();
	this->_ready = false;
	return *this;
}
