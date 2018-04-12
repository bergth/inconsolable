#include <stdlib.h>
#include <time.h>
#include <math.h>


#include "ball.h"
#include "config.h"


using namespace config;




float Ball::get_coord_x() {
	return coord_x;
}


float Ball::get_coord_y() {
	return coord_y;
}


float Ball::get_center_x() {
	return center_x;
}


float Ball::get_center_y() {
	return center_y;
}


void Ball::set_coord_x(float x) {
	Ball::coord_x = x;
}


void Ball::set_coord_y(float y) {
	Ball::coord_y = y;
}


void Ball::set_coef_dir(const float a) {
	coef_dir = a;
}




void Ball::inverse_dir_x() {
	dir_x *= -1;
}


void Ball::inverse_dir_y() {
	coef_dir *= -1;
}




void Ball::init() {
	dim_x = B_DIM_X;
	dim_y = B_DIM_Y;
	center_x = dim_x / 2;
	center_y = dim_y / 2;
	coord_x = DIM_X / 2;
	coord_y = DIM_Y / 2;

	dir_x = 1;

	srand(time(NULL));
	coef_dir = rand() % 6 - 3; // entre -3 et 3
}


void Ball::update() {
	float v = 1/3; //vitesse de la ball || max : 1/coef_max
	float dx = v / sqrt(1 + pow(Ball::coef_dir, 2));


	coord_x += dx * dir_x;
	coord_y += coef_dir * dx;

	if ( (coord_y == BORDER_THICKNESS + Ball::center_y) || (coord_y == DIM_Y - (BORDER_THICKNESS + Ball::center_y)) )
		inverse_dir_y();

}