#ifndef POINTSHOT_H
# define POINTSHOT_H

# include "EWeapon.h"
# include "Level.h"

class				PointShot : public EWeapon
{
public:
	PointShot();

	void			setSpeed(float x, float y);
	
};

#endif