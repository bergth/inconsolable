#include "racket_IA.h"
#include "config.h"


using namespace config;



Racket_IA::Racket_IA(const float dim_xr, const float dim_yr, const float coord_xr, const float coord_yr) : Racket(dim_xr, dim_yr, coord_xr, coord_yr)
{
}


Racket_IA::~Racket_IA()
{
}




float Racket_IA::update_virtual() {
  if(Ball::get_coord_y() > this->coord_y + R_DIM_Y / 4)
	  return R_SPEED;
  if(Ball::get_coord_y() < this->coord_y - R_DIM_Y / 4)
    return (-1*R_SPEED);
  return 0;
}
