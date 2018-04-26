#include "racket.h"
#include "config.h"


using namespace config;



Racket::Racket(const float dim_xr, const float dim_yr, const float coord_xr, const float coord_yr)
{
	this->dim_x = dim_xr;
	this->dim_y = dim_yr;
	this->center_x = dim_xr / 2;
	this->center_y = dim_yr / 2;
	this->coord_x = coord_xr;
	this->coord_y = coord_yr;
}


Racket::~Racket()
{
}




float Racket::get_center_x() {
	return this->center_x;
}


float Racket::get_center_y() {
	return this->center_y;
}


float Racket::get_coord_x() {
	return this->coord_x;
}


float Racket::get_coord_y() {
	return this->coord_y;
}


void Racket::set_coord_y(float y) {
	this->coord_y = y;
}




void Racket::update(){
  float new_coord_y = this->update_virtual();

 if (new_coord_y < BORDER_THICKNESS + B_DIM_Y + R_DIM_Y / 2) {
    if (((int)this->coord_x >= (int)Ball::get_coord_x() - ((int)this->center_x + (int)Ball::get_center_x())) && ((int)this->coord_x <= (int)Ball::get_coord_x() + (int)this->center_x + (int)Ball::get_center_x()) && ((int)Ball::get_coord_y() == BORDER_THICKNESS + (int)Ball::get_center_y())) {
      new_coord_y = BORDER_THICKNESS + B_DIM_Y + R_DIM_X / 2;
      Ball::set_coef_dir(0);
    }
    else if (new_coord_y < R_Y_MIN)
      new_coord_y = R_Y_MIN;
  }
  else if (new_coord_y > DIM_Y - (BORDER_THICKNESS + B_DIM_Y + R_DIM_Y / 2)) {
    if (((int)this->coord_x >= (int)Ball::get_coord_x() - ((int)this->center_x + (int)Ball::get_center_x())) && ((int)this->coord_x <= (int)Ball::get_coord_x() + (int)this->center_x + (int)Ball::get_center_x()) && ((int)Ball::get_coord_y() == BORDER_THICKNESS + (int)Ball::get_center_y())) {
      new_coord_y = DIM_Y - (BORDER_THICKNESS + B_DIM_Y + R_DIM_Y / 2);
      Ball::set_coef_dir(0);
    }
    else if (new_coord_y > R_Y_MAX)
      new_coord_y = R_Y_MAX;
  }

  this->coord_y = new_coord_y;
  
  if ((Ball::get_coord_x() - Ball::get_center_x() <= this->coord_x + this->center_x) && (Ball::get_coord_x() - Ball::get_center_x() + (float)R_DIM_X / 2 >= this->coord_x + this->center_x) && (Ball::get_coord_y() - Ball::get_center_y() <= this->coord_y + this->center_y) && (Ball::get_coord_y() + Ball::get_center_y() >= this->coord_y - this->center_y) && (Ball::get_dir_x() == -1)) {
    Ball::inverse_dir_x();
    Ball::set_coef_dir((this->coord_y - Ball::get_coord_y()) * (-3) / (this->center_y + Ball::get_center_y()));
  }
  if ((Ball::get_coord_x() + Ball::get_center_x() >= this->coord_x - this->center_x) && (Ball::get_coord_x() + Ball::get_center_x() - (float)R_DIM_X / 2 <= this->coord_x - this->center_x) && (Ball::get_coord_y() - Ball::get_center_y() <= this->coord_y + this->center_y) && (Ball::get_coord_y() + Ball::get_center_y() >= this->coord_y - this->center_y) && (Ball::get_dir_x() == 1)) {
    Ball::inverse_dir_x();
    Ball::set_coef_dir((this->coord_y - Ball::get_coord_y()) * (-3) / (this->center_y + Ball::get_center_y()));
  }
}
