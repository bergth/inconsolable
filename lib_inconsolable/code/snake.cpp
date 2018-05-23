#include "snake.hpp"
#include "libinc.hpp"

using namespace std;

Snake::Snake(int _size): size{_size}, inc{SIZE_X,SIZE_Y,FPS}
{
    dir = 1;
    v[0] = {(float)SIZE_X/2,(float)SIZE_Y/2};
    v[1] = {(float)SIZE_X/2,(float)SIZE_Y/2 -size};
    v[2] = {(float)SIZE_X/2,(float)SIZE_Y/2 -2*size};
    v_size = 3;
    to_delete = {(float)SIZE_X/2,(float)SIZE_Y/2 -3*size};
}

void Snake::draw_snake()
{
    for(size_t i = 0; i < v_size; i++)
    {
        coord c = v[i];
        inc.fillRect(c.x - size/2,c.x + size/2, c.y - size/2, c.y + size/2,WHITE);
    }
     inc.fillRect(to_delete.x - size/2,to_delete.x + size/2, to_delete.y - size/2, to_delete.y + size/2,BLACK);
}

void Snake::get_ctrl()
{
    if(inc.get_key_left())
    {
        if(dir == 3 || dir == 1)
            dir = 2;
    }
    else if(inc.get_key_right())
    {
        if(dir == 3 || dir == 1) 
            dir = 0;
    }
    else if(inc.get_key_up())
    {
        if(dir == 0 || dir == 2)
            dir = 3;
    }
    else if(inc.get_key_down())
    {
        if(dir == 0 || dir == 2)
            dir = 1;
    }
    
}

void Snake::move_snake()
{
    int move_x = 0;
    int move_y = 0;
    switch(dir)
    {
        case 0:
            move_x = 1;
            move_y = 0;
            break;
        case 1:
            move_x = 0;
            move_y = 1;
            break;
        case 2:
            move_x = -1;
            move_y = 0;
            break;
        case 3:
            move_x = 0;
            move_y = -1;
            break;
    }
    int nx = v[0].x + move_x * size;
    int ny = v[0].y + move_y * size;
    to_delete = v[v_size-1];
    for(size_t i = v_size - 1; i > 0; i--)
    {
        v[i] = v[i-1];
    }
    v[0].x = nx;
    v[0].y = ny;
}
        

void Snake::play()
{
    while(inc.isRunning())
    {
        if(inc.time_since(500))
        {
            move_snake();
        }
        get_ctrl();
        draw_snake();
        inc.update();
    }
}