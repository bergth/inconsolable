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

Adafruit_SSD1306 tft(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


void update_screen() {
  tft.display();
  delay(2); //peut etre modifiee
  tft.clearDisplay();
}




void setup() {
  //Serial.begin(9600);
  
  //config pin
  pinMode(3, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  //init de l'ecran
  tft.begin(SSD1306_SWITCHCAPVCC);
}




void test_drawPixel(){
  tft.drawPixel(12, 12, WHITE);
}


void test_writePixel(){
  tft.writePixel(10, 10, WHITE);
}




void loop() {
  // put your main code here, to run repeatedly:
  test_drawPixel();
  test_writePixel();
  

  update_screen();
}
