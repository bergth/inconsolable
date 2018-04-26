#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



#include "pong.h"
#include "racket_player.h"
#include "racket_IA.h"
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
Racket_player* player = new Racket_player(R_DIM_X, R_DIM_Y, R_X1, R_Y);
Racket_IA* enemy = new Racket_IA(R_DIM_X, R_DIM_Y, R_X2, R_Y);




void pong_init() {
	player->set_coord_y(R_Y);

	enemy->set_coord_y(R_Y);

	Ball::init();
}


bool test_game_over() {
	tft.setTextSize(1);
	tft.setTextColor(WHITE);
	tft.setCursor(42, 29);

	if (Ball::get_coord_x() <= B_X_MIN - 0.5)
		tft.print("YOU LOSE");
	else if (Ball::get_coord_x() >= B_X_MAX + 0.5)
		tft.print("YOU WIN");
  else
		return 0;

	pong_init();

	return 1;
}


void print_border() {
	size_t i, j;

	for (i = 0; i < DIM_Y; i++) {
		for (j = 0; j < DIM_X; j++) {
			if ( (i < BORDER_THICKNESS) || (i >= DIM_Y - BORDER_THICKNESS) || (j < BORDER_THICKNESS) || (j >= DIM_X - BORDER_THICKNESS) ) {
				tft.drawPixel(j, i, WHITE);
			}
		}
	}

}


void print_racket(Racket* r) {
	int i, j;

	for (i = (int)r->get_coord_y() - (int)r->get_center_y(); i != (int)r->get_coord_y() + (int)r->get_center_y(); i++) 
		for (j = (int)r->get_coord_x() - (int)r->get_center_x(); j != (int)r->get_coord_x() + (int)r->get_center_x(); j++) 
			tft.drawPixel(j, i, WHITE);

}


void print_ball() {
	int i = (int)Ball::get_coord_y() - (int)Ball::get_center_y(), j = (int)Ball::get_coord_x() - (int)Ball::get_center_x();
  //Serial.println("TEST 2.1 :  i = " + String(i) + "  j = " + String(j) );

	for (i = (int)Ball::get_coord_y() - (int)Ball::get_center_y(); i <= (int)Ball::get_coord_y() + (int)Ball::get_center_y(); i++)
		for (j = (int)Ball::get_coord_x() - (int)Ball::get_center_x(); j <= (int)Ball::get_coord_x() + (int)Ball::get_center_x(); j++){
			tft.drawPixel(j, i, WHITE);
		}
}


void update_screen(bool b) {
	tft.display();
	delay(2); //peut etre modifiee
	if (b)
		delay(2000);
	tft.clearDisplay();
}




void setup()
{
  //Serial.begin(9600);
  
	//config pin
	pinMode(3, INPUT);
	pinMode(A0, INPUT);
	pinMode(A1, INPUT);

	//init de l'ecran
	tft.begin(SSD1306_SWITCHCAPVCC);


	//init objets
	Ball::init();
}

void loop()
{
  
  //Serial.println("TEST 1.1");
	bool game_over = 0;
	//update objets
  //Serial.println("TEST 1.2");
	player->update();
  //Serial.println("TEST 1.3");
	enemy->update();
  //Serial.println("TEST 1.4");
	Ball::update();

 //Serial.println( "X : " + String(Ball::get_coord_x(), 2) + "  Y : " + String(Ball::get_coord_y(), 2) );
 

	//fin de partie
	game_over = test_game_over();
  //Serial.println("TEST 1.5");

	//print
	print_border();
  //Serial.println("TEST 1.6");
	print_racket(player);
  //Serial.println("TEST 1.7");
	print_racket(enemy);
  //Serial.println("TEST 1.8");
	if (!game_over)
		print_ball();
  //Serial.println("TEST 1.9");

	//affichage
	update_screen(game_over);
  //Serial.println("TEST 1.10");
}
