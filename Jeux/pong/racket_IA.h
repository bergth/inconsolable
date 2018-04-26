#pragma once


#include "racket.h"




class Racket_IA :
	public Racket
{
public:
	Racket_IA(const float dim_xr, const float dim_yr, const float coord_xr, const float coord_yr);

	~Racket_IA();


  float update_virtual();
};

