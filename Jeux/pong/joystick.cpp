#include <Arduino.h>


#include "joystick.h"




float Joystick::get_Tx() {
	float Tx;


	Tx = ((float)analogRead(A0) - 512) / 512;


	if (Tx < 0.15 && Tx > -0.15)
		Tx = 0;


	return Tx;
}


float Joystick::get_Ty() {
	float Ty;


	Ty = ((float)analogRead(A1) - 512) / 512;


	if (Ty < 0.15 && Ty > -0.15)
		Ty = 0;


	return Ty;
}


int Joystick::get_SW() {
	if (digitalRead(3) == HIGH)
		return 1;
	else
		return 0;
}
