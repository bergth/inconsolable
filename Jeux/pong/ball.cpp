#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Arduino.h>


#include "ball.h"
#include "config.h"


using namespace config;




float Ball::dim_x;
float Ball::dim_y;
float Ball::center_x;
float Ball::center_y;
float Ball::coord_x;
float Ball::coord_y;
int Ball::dir_x;
float Ball::coef_dir;





float Ball::get_coord_x() {
	return Ball::coord_x;
}


float Ball::get_coord_y() {
	return Ball::coord_y;
}


float Ball::get_center_x() {
	return Ball::center_x;
}


float Ball::get_center_y() {
	return Ball::center_y;
}


void Ball::set_coord_x(float x) {
	Ball::coord_x = x;
}


void Ball::set_coord_y(float y) {
	Ball::coord_y = y;
}


int Ball::get_dir_x() {
  return Ball::dir_x;
}


void Ball::set_coef_dir(const float a) {
	Ball::coef_dir = a;
}




void Ball::inverse_dir_x() {
	Ball::dir_x *= -1;
}


void Ball::inverse_dir_y() {
	Ball::coef_dir *= -1;
}




void Ball::init() {
	Ball::dim_x = B_DIM_X;
	Ball::dim_y = B_DIM_Y;
	Ball::center_x = dim_x / 2;
	Ball::center_y = dim_y / 2;
	Ball::coord_x = DIM_X / 2;
	Ball::coord_y = DIM_Y / 2;

	Ball::dir_x = 1;

	//srand(time(NULL));
	//Ball::coef_dir = rand() % 6 - 3; // entre -3 et 3
	Ball::coef_dir = 0;
}


void Ball::update() {
	float dx = B_SPEED / sqrt(1 + pow(Ball::coef_dir, 2));
  //Serial.println( "dx : " + String(dx, 2) + "  " + String(dx * Ball::dir_x, 2) + "  " + String(Ball::coef_dir * dx, 2)  + "  " + String(v, 2) );
  
	Ball::coord_x += dx * Ball::dir_x;
	Ball::coord_y += Ball::coef_dir * dx;

	if (Ball::coord_y <= BORDER_THICKNESS + Ball::center_y)
		Ball::coef_dir = 1;
  else if(Ball::coord_y >= DIM_Y - (BORDER_THICKNESS + Ball::center_y))
    Ball::coef_dir = -1;
}
