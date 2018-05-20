#ifndef LIBINC_HPP
#define LIBINC_HPP
#include<cstddef>
#include<cstdint>
#include<chrono>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_opengl.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
struct s_color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

typedef s_color IncColor;


class Inconsolable
{
    private:
        ALLEGRO_DISPLAY* display;
        ALLEGRO_EVENT_QUEUE* event_queue;
        ALLEGRO_TIMER* timer;
        ALLEGRO_EVENT event;
        ALLEGRO_TIMEOUT timeout;
        bool running;
        bool redraw;
        time_t last_time;

    public:
        Inconsolable(size_t sx, size_t sy,size_t FPS);
        ~Inconsolable();
        void clear();
        void update();
        bool isRunning();
        void drawPixel(size_t coord_x,size_t coord_y, IncColor color);
        void drawLine(size_t coord_x1, size_t coord_x2, size_t coord_y1, size_t coord_y2, IncColor color);
        void drawRect(size_t coord_x1, size_t coord_x2, size_t coord_y1, size_t coord_y2, IncColor color);
        void fillRect(size_t coord_x1, size_t coord_x2, size_t coord_y1, size_t coord_y2, IncColor color);
        void drawCircle(size_t coord_x, size_t coord_y, size_t r, IncColor color);
        void drawChar(size_t coord_x, size_t coord_y, size_t txt_size, IncColor color,char* c);
        void fillScreen(IncColor color);
        bool time_since(int t);
}; 

#endif