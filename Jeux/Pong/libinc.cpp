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
  screen.drawPixel(coord_x, coord_y, incColor_to_uint16_t(color));
}


void Inconsolable::drawLine(size_t coord_x1, size_t coord_x2, size_t coord_y1, size_t coord_y2, IncColor color){
  screen.drawLine(coord_x1, coord_y1, coord_x2, coord_y2, incColor_to_uint16_t(color));
}


void Inconsolable::drawRect(size_t coord_x, size_t coord_y, size_t w, size_t h, IncColor color){
  screen.drawRect(coord_x, coord_y, w, h, incColor_to_uint16_t(color));
}


void Inconsolable::fillRect(size_t coord_x, size_t coord_y, size_t w, size_t h, IncColor color){
  screen.fillRect(coord_x, coord_y, w, h, incColor_to_uint16_t(color));
}


void Inconsolable::drawTriangle(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, size_t coord_x3, size_t coord_y3, IncColor color){
  screen.drawTriangle(coord_x1, coord_y1, coord_x2, coord_y2, coord_x3, coord_y3, incColor_to_uint16_t(color));
}


void Inconsolable::fillTriangle(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, size_t coord_x3, size_t coord_y3, IncColor color){
  screen.fillTriangle(coord_x1, coord_y1, coord_x2, coord_y2, coord_x3, coord_y3, incColor_to_uint16_t(color));
}


void Inconsolable::drawCircle(size_t coord_x, size_t coord_y, size_t r, IncColor color){
  screen.drawCircle(coord_x, coord_y, r, incColor_to_uint16_t(color));
}


void Inconsolable::drawChar(size_t coord_x, size_t coord_y, char c, size_t txt_size, IncColor color){
  screen.setTextSize(txt_size);
  screen.setTextColor(incColor_to_uint16_t(color));
  screen.setCursor(coord_x ,coord_y);
  screen.write(c);
}


void Inconsolable::drawString(size_t coord_x, size_t coord_y, char* s, size_t txt_size, IncColor color){
  screen.setTextSize(txt_size);
  screen.setTextColor(incColor_to_uint16_t(color));
  screen.setCursor(coord_x ,coord_y);
  screen.print(s);
}


void Inconsolable::drawBitmap(size_t coord_x, size_t coord_y, uint32_t bitmap[], size_t w, size_t h){
  //????
}


void Inconsolable::fillScreen(IncColor color){
  screen.fillScreen(incColor_to_uint16_t(color));
}




uint16_t incColor_to_uint16_t(IncColor color){
  return (((31*(color.r+4))/255)<<11) | (((63*(color.g+2))/255)<<5) | ((31*(color.b+4))/255);
}

