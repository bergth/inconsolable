#include "racket_player.h"
#include "config.h"


using namespace config;



Racket_player::Racket_player(const float dim_xr, const float dim_yr, const float coord_xr, const float coord_yr) : Racket(dim_xr, dim_yr, coord_xr, coord_yr)
{
}


Racket_player::~Racket_player()
{
}




float Racket_player::update_virtual() {
	return Joystick::get_Ty() * R_SPEED;
}
