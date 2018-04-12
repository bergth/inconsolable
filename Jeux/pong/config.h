#pragma once


#include "stdlib.h"


namespace config {

//screen
	const size_t DIM_X				=	128;
	const size_t DIM_Y				=	64;


//edge
	const size_t BORDER_THICKNESS	=	2;


//racket
	const size_t R_DIM_X			=	3;
	const size_t R_DIM_Y			=	12;
	const size_t R_X1				=	BORDER_THICKNESS + 4;
	const size_t R_X2				=	DIM_X - R_X1;
	const size_t R_Y				=	DIM_Y / 2;
	const size_t R_Y_MIN			=	BORDER_THICKNESS + 2 + R_DIM_Y / 2;
	const size_t R_Y_MAX			=	DIM_Y - R_Y_MIN;


//ball
	const size_t B_DIM_X			=	3;
	const size_t B_DIM_Y			=	3;
	const size_t B_X_MIN			=	2;
	const size_t B_X_MAX			=	DIM_X - B_X_MIN;
	const size_t B_Y_MIN			=	2;
	const size_t B_Y_MAX			=	DIM_Y - B_Y_MIN;
}