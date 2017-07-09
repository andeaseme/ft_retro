
#include "Level.h"

Player::Player() : Collidable::Collidable(
		Level::getWidth() / 2,
		3 * Level::getHeight() / 4
	)
{
	this->_sprite = "P";
	this->setSpeed(0.0, 0.0);
}

Player::Player(float const x, float const y)
	: Collidable::Collidable(x, y)
{
	this->_sprite = "P";
	this->setSpeed(0.0, 0.0);
}
