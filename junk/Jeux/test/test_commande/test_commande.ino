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
  // put your setup code here, to run once:
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


void test_drawLine(){
  tft.drawLine(10, 7, 35, 30, WHITE);
}


void test_drawRect(){
  tft.drawRect(20, 20, 40, 40, WHITE);
}


void test_fillRect(){
  tft.fillRect(60, 28, 8, 8, WHITE);
}


void test_drawTriangle(){
  tft.drawTriangle(100, 50, 100, 60, 110, 55, WHITE);
}


void test_fillTriangle(){
  tft.fillTriangle(98, 50, 98, 60, 88, 55, WHITE);
}


void test_drawCircle(){
  tft.drawCircle(100, 20, 15, WHITE);
}


void test_fillCircle(){
  tft.fillCircle(100, 20, 8, WHITE);
}


void test_drawChar(){
  tft.setTextSize(3);
  tft.setTextColor(WHITE);
  tft.setCursor(27,27);
  tft.write('q');
}


void test_drawString(){
  tft.setTextSize(1);
  tft.setTextColor(WHITE);
  tft.setCursor(25,10);
  tft.print("qqqqqqqqqqqq");
}




void loop() {
  // put your main code here, to run repeatedly:
  test_drawPixel();
  test_drawLine();
  test_drawRect();
  test_fillRect();
  test_drawTriangle();
  test_fillTriangle();
  test_drawCircle();
  test_fillCircle();
  test_drawChar();
  test_drawString();
}
