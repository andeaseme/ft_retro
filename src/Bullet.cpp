#include "Bullet.h"

Bullet::Bullet(void) :
	_location(0),
	_sprite("O"),
	_hp(1),
	_damage(1),
	_x(-1),
	_y(-1),
	_dx(1),
	_dy(0),
	_ready(0)
{

}

Bullet::Bullet(float const x, float const y) : Collidable::Collidable(x, y)
{
	setSprite("O");
}

Bullet::Bullet(Bullet const &ref)
{
	*this = ref;
}

Bullet		&Bullet::operator=(Bullet const &rhs)
{

}