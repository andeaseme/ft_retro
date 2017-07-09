
#ifndef PLAYER_H
# define PLAYER_H

# include "Collidable.h"

class				Player : public Collidable
{
public:

	Player();
	Player(float const x, float const y);
};

#endif
