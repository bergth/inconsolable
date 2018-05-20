#include "libinc.hpp"



Inconsolable::Inconsolable(size_t sx, size_t sy,size_t FPS): screen{TFT_CS,TFT_DC}
{
  //init de l'ecran
  running = true;
  screen = ILI9341_due(TFT_CS, TFT_DC);
  screen.begin();
  fillScreen({0,0,0});
}


Inconsolable::~Inconsolable(){
  
}




void Inconsolable::clear(){
  fillScreen({0,0,0});
}


void Inconsolable::update(){
  delay(1); //peut etre modifiee
  clear();
}


bool Inconsolable::isRunning(){
  return running;
}




void Inconsolable::drawPixel(size_t coord_x,size_t coord_y, IncColor color){
  screen.drawPixel(coord_y, coord_x, incColor_to_uint16_t(color));
}


void Inconsolable::drawLine(size_t coord_x1, size_t coord_x2, size_t coord_y1, size_t coord_y2, IncColor color){
  screen.drawLine(coord_y1, coord_x1, coord_y2, coord_x2, incColor_to_uint16_t(color));
}


void Inconsolable::drawRect(size_t coord_x1, size_t coord_x2, size_t coord_y1, size_t coord_y2, IncColor color){
  int w = coord_x2 - coord_x1;
  int h = coord_y2 - coord_y1;
  screen.drawRect(coord_y1, coord_x1, h, w, incColor_to_uint16_t(color));
}


void Inconsolable::fillRect(size_t coord_x1, size_t coord_x2, size_t coord_y1, size_t coord_y2, IncColor color){
  int w = coord_x2 - coord_x1;
  int h = coord_y2 - coord_y1;
  screen.fillRect(coord_y1, coord_x1, h, w, incColor_to_uint16_t(color));
}


void Inconsolable::drawTriangle(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, size_t coord_x3, size_t coord_y3, IncColor color){
  screen.drawTriangle(coord_y1, coord_x1, coord_y2, coord_x2, coord_y3, coord_x3, incColor_to_uint16_t(color));
}


void Inconsolable::fillTriangle(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, size_t coord_x3, size_t coord_y3, IncColor color){
  screen.fillTriangle(coord_y1, coord_x1, coord_y2, coord_x2, coord_y3, coord_x3, incColor_to_uint16_t(color));
}


void Inconsolable::drawCircle(size_t coord_x, size_t coord_y, size_t r, IncColor color){
  screen.drawCircle(coord_y, coord_x, r, incColor_to_uint16_t(color));
}


void Inconsolable::drawChar(size_t coord_x, size_t coord_y, char c, size_t txt_size, IncColor color){
 // screen.setTextSize(txt_size);
 // screen.setTextColor(incColor_to_uint16_t(color));
 // screen.setCursor(coord_y ,coord_x);
 // screen.write(c);
}


void Inconsolable::drawString(size_t coord_x, size_t coord_y, char* s, size_t txt_size, IncColor color){
 // screen.setTextSize(txt_size);
 // screen.setTextColor(incColor_to_uint16_t(color));
 // screen.setCursor(coord_y ,coord_x);
 // screen.print(s);
}





void Inconsolable::fillScreen(IncColor color){
  screen.fillScreen(incColor_to_uint16_t(color));
}


uint16_t incColor_to_uint16_t(IncColor color){
  return (((31*(color.r+4))/255)<<11) | (((63*(color.g+2))/255)<<5) | ((31*(color.b+4))/255);
}
