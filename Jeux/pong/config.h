#pragma once


#include "stdlib.h"


namespace config {

//screen
  const size_t DIM_X				    =	128;
  const size_t DIM_Y				    =	64;


//edge
	const size_t BORDER_THICKNESS	=	2;


//DIM objects
  const size_t R_DIM_X		    	=	3;
  const size_t R_DIM_Y		    	=	12;
  const size_t B_DIM_X          = 3;
  const size_t B_DIM_Y          = 3;
//POS objects
  const size_t R_X1			      	=	BORDER_THICKNESS + B_DIM_X;
  const size_t R_X2			      	=	DIM_X - R_X1;
  const size_t R_Y			      	=	DIM_Y / 2;
//LIM objects
  const size_t R_Y_MIN		    	=	BORDER_THICKNESS + 2 + R_DIM_Y / 2;
  const size_t R_Y_MAX		    	=	DIM_Y - R_Y_MIN;
  const size_t B_X_MIN		    	=	BORDER_THICKNESS;
	const size_t B_X_MAX		    	=	DIM_X - B_X_MIN;
	const size_t B_Y_MIN		    	=	BORDER_THICKNESS;
	const size_t B_Y_MAX			    =	DIM_Y - B_Y_MIN;
//SPEED object
  const float R_SPEED          = 2; //vitesse de la racket || max : 1
  const float B_SPEED          = 2; //vitesse de la ball || max : 1/coef_max
}
