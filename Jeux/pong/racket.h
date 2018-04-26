#include "joystick.h"
#include "ball.h"




#pragma once
class Racket
{
public:

	Racket(const float dim_xr, const float dim_yr, const float coord_xr, const float coord_yr);

	~Racket();


	float get_center_x();

	float get_center_y();

	float get_coord_x();

	float get_coord_y();

	void set_coord_y(float y);


  void update();

  virtual float update_virtual() = 0;


protected:

	float dim_x;
	float dim_y;
	float center_x;
	float center_y;
	float coord_x;
	float coord_y;
};

