#include "libinc.hpp"


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>




 // If using software SPI (the default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13

Adafruit_SSD1306 screen(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);





Inconsolable(size_t sx, size_t sy,size_t FPS){
  //init de l'ecran
  screen.begin(SSD1306_SWITCHCAPVCC);
  
}


~Inconsolable(){
  
}




void Inconsolable::clear(){
  
}


void Inconsolable::update(){
  screen.display();
  delay(2); //peut etre modifiee
  screen.clearDisplay();
}


bool Inconsolable::isRunning(){
  
}




void Inconsolable::drawPixel(size_t coord_x,size_t coord_y, IncColor color){
  screen.drawPixel(size_t coord_x, size_t coord_y, color);
}


void Inconsolable::drawLine(size_t coord_x1, size_t coord_x2, size_t coord_y1, size_t coord_y2, IncColor color){
  screen.drawLine(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, color);
}


void Inconsolable::drawRect(size_t coord_x1, size_t coord_x2, size_t coord_y1, size_t coord_y2, IncColor color){
  screen.drawRect(size_t coord_x, size_t coord_y, size_t w, size_t h, color);
}


void Inconsolable::fillRect(size_t coord_x1, size_t coord_x2, size_t coord_y1, size_t coord_y2, IncColor color){
  display.fillRect(size_t coord_x, size_t coord_y, size_t w, size_t h, color);
}


void Inconsolable::drawCircle(size_t coord_x, size_t coord_y, size_t r, IncColor color){
  screen.drawCircle(size_t coord_x, size_t coord_y, size_t r, color);
}


void Inconsolable::drawChar(size_t coord_x, size_t coord_y, char c, size_t txt_size, IncColor color){
  screen.setTextSize(txt_size);
  screen.setTextColor(color);
  screen.setCursor(x ,y);
  screen.write(c);
}

