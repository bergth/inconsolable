#pragma once


#include "racket.h"




class Racket_player :
	public Racket
{
public:
	Racket_player(const float dim_xr, const float dim_yr, const float coord_xr, const float coord_yr);

	~Racket_player();


  float update_virtual();
};

