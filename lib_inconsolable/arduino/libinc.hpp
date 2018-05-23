#ifndef LIBINC_HPP
#define LIBINC_HPP

#include<stddef.h>
#include<stdint.h>
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"


#define TFT_DC 9
#define TFT_CS 10

#define JOY_X 7
#define JOY_Y 6

#define B_DOWN  37
#define B_UP    33
#define B_LEFT  36
#define B_RIGHT 32

struct s_color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

typedef s_color IncColor;

class Joystick
{
    public:
       //Joystick();
        float get_x();
        float get_y();
    private:
        float treat_value(int b);
};


class Inconsolable
{
    private:
        Adafruit_ILI9341 screen;
        bool running;
        int last_time;
        Joystick J;
    public:
        Inconsolable(size_t sx, size_t sy,size_t FPS);
        ~Inconsolable();
        void clear();
        void update();
        bool isRunning();
        void drawPixel(size_t coord_x,size_t coord_y, IncColor color);
        void drawLine(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, IncColor color);
        void drawRect(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, IncColor color);
        void fillRect(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, IncColor color);
        void fillTriangle(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, size_t coord_x3, size_t coord_y3, IncColor color);
        void drawTriangle(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, size_t coord_x3, size_t coord_y3, IncColor color);
        void drawCircle(size_t coord_x, size_t coord_y, size_t r, IncColor color);
        void drawChar(size_t coord_x, size_t coord_y, char c, size_t txt_size, IncColor color);
        void drawString(size_t coord_x, size_t coord_y, char* s, size_t txt_size, IncColor color);
        void fillScreen(IncColor color);
        bool time_since(int t);
        int  rand(int a, int b);
        bool get_key_right();
        bool get_key_left();
        bool get_key_up();
        bool get_key_down();
};

uint16_t incColor_to_uint16_t(IncColor color);

#endif