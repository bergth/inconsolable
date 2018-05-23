#ifndef LIBINC_HPP
#define LIBINC_HPP
#include <cstddef>
#include <cstdint>
#include <chrono>
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

#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_LEFT 3
#define KEY_RIGHT 4


typedef s_color IncColor;

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::high_resolution_clock::time_point time_p;
typedef std::chrono::milliseconds ms;
typedef std::chrono::duration<float> fsec;

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
        bool key[4] = {false, false, false, false};
        time_p last_time;

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
        int rand(int a, int b);
        bool get_key_up();
        bool get_key_down();
        bool get_key_left();
        bool get_key_right();
}; 

#endif