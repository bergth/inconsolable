#include "libinc.hpp"


#define WHITE {255,255,255}
#define BLACK {0,0,0}
#define RED {255,0,0}

#define SIZE_X 320
#define SIZE_Y 245
#define FPS 60

typedef struct coord_s
{
    float x;
    float y;
} coord;



class Snake
{
    private:
        int size;
        int dir;
        Inconsolable inc;
        coord v[200];
        size_t v_size;
        coord to_delete;
        void draw_snake();
        void move_snake();
        void get_ctrl();
    public:
        Snake(int _size);
        void play();
};