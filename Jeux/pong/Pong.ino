#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



#include "pong.h"
#include "racket.h"
#include "ball.h"
#include "config.h"


using namespace config;




 /*
	PIN CONFIG
	3	input	joystick push
	9	input	OLED_MOSI 
	10	input	OLED_CLK   
	11	input	OLED_DC    
	12	input	OLED_CS    
	13	input	OLED_RESET

	A0	input	joystick x axis
	A1	input	joyctick y axis
 */



 // If using software SPI (the default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13

Adafruit_SSD1306 tft(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


//init des objets
Racket* player = new Racket(R_DIM_X, R_DIM_Y, R_X1, R_Y);
Racket* enemy = new Racket(R_DIM_X, R_DIM_Y, R_X2, R_Y);




void init() {
	player->set_coord_y(R_DIM_Y);

	enemy->set_coord_y(R_DIM_Y);

	Ball::init();
}


bool test_game_over() {
	tft.setTextSize(1);
	tft.setTextColor(WHITE);
	tft.setCursor(42, 29);

	if (Ball::get_coord_x() == B_X_MIN)
		tft.print("YOU LOSE");

	else if (Ball::get_coord_x() == B_Y_MAX)
		tft.print("YOU WIN");

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
			tft.drawPixel(j, i, WHITE);
		}
	}

}


void print_racket(Racket* r) {
	size_t i, j;

	for (i = (size_t)(-r->get_center_y()); i != (size_t)r->get_center_y(); i++) 
		for (j = (size_t)(-r->get_center_x()); j != (size_t)r->get_center_x(); j++) 
			tft.drawPixel(j, i, WHITE);

}


void print_ball() {
	size_t i, j;

	for (i = (size_t)(-Ball::get_center_y()); i != (size_t)Ball::get_center_y(); i++) {
		for (j = (size_t)(-Ball::get_center_x()); j != (size_t)Ball::get_center_x(); j++) {
			tft.drawPixel(j, i, WHITE);
		}
	}
}


void update_screen(bool b) {
	tft.display();
	delay(250); //peut etre modifiee
	if (b)
		delay(2000);
	tft.clearDisplay();
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
	update_screen(game_over);
}
