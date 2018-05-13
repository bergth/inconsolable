#include "libinc.hpp"
#include "pong.h"
#include "racket.h"
#include "ball.h"
#include "config.h"


using namespace config;




Inconsolable* inc = new Inconsolable();
IncColor WHITE = White;




//init des objets
Racket* player = new Racket(R_DIM_X, R_DIM_Y, R_X1, R_Y);
Racket* enemy = new Racket(R_DIM_X, R_DIM_Y, R_X2, R_Y);




void init() {
	player->set_coord_y(R_DIM_Y);

	enemy->set_coord_y(R_DIM_Y);

	Ball::init();
}


bool test_game_over() {
  
	if (Ball::get_coord_x() == B_X_MIN)
    inc->drawString(49, 29, (char*)"YOU LOSE", 1, WHITE);

	else if (Ball::get_coord_x() == B_Y_MAX)
    inc->drawString(49, 29, (char*)"YOU WIN", 1, WHITE);

	else
		return 0;

	init();

	return 1;
}


void print_border() {
	size_t i, j;

	for (i = 0; i != DIM_Y; i++) {
		if (i == BORDER_THICKNESS)
			i = DIM_Y - BORDER_THICKNESS;
		for (j = 0; j != DIM_X; j++) {
			if (j == BORDER_THICKNESS)
				j = DIM_X - BORDER_THICKNESS;
			inc->drawPixel(j, i, WHITE);
		}
	}

}


void print_racket(Racket* r) {
	size_t i, j;

	for (i = (size_t)(-r->get_center_y()); i != (size_t)r->get_center_y(); i++) 
		for (j = (size_t)(-r->get_center_x()); j != (size_t)r->get_center_x(); j++) 
			inc->drawPixel(j, i, WHITE);

}


void print_ball() {
	size_t i, j;

	for (i = (size_t)(-Ball::get_center_y()); i != (size_t)Ball::get_center_y(); i++) {
		for (j = (size_t)(-Ball::get_center_x()); j != (size_t)Ball::get_center_x(); j++) {
			inc->drawPixel(j, i, WHITE);
		}
	}
}




void setup()
{
	//config pin
	pinMode(3, INPUT);
	pinMode(A0, INPUT);
	pinMode(A1, INPUT);


	//init objets
	Ball::init();
}

void loop()
{
	bool game_over = 0;
	//update objets
	player->update();
	enemy->update();
	Ball::update();

	//fin de partie
	game_over = test_game_over();

	//print
	print_border();
	print_racket(player);
	print_racket(enemy);
	if (!game_over)
		print_ball();

	//affichage
	inc->update();
	if(game_over)
    delay(2000);
}
