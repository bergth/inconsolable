#include "snake.hpp"
#include "libinc.hpp"

using namespace std;

void Snake::draw_rect(coord c, IncColor col)
{

    inc.fillRect(c.x*size+1,c.x*size+size,c.y*size+1,c.y*size+size,col);
}

void Snake::move_fruit()
{
    nope:
    fruit = {(float)inc.rand(0,max_x),(float)inc.rand(0,max_y)};
    for(size_t i = 0; i < v_size; i++)
    {
        if(fruit.x == v[i].x && fruit.y == v[i].y)
        {
            goto nope;
        }
    }
}

Snake::Snake(int _size): size{_size}, inc{SIZE_X,SIZE_Y,FPS}
{
    max_x = SIZE_X/size - 1;
    max_y = SIZE_Y/size - 1;
    int mid_x = max_x/2;
    int mid_y = max_y/2;
    dir = 1;
    v[0] = {(float)mid_x,(float)mid_y};
    v[1] = {(float)mid_x,(float)mid_y-1};
    v[2] = {(float)mid_x,(float)mid_y-2};
    v_size = 3;
    to_delete = {(float)mid_x,(float)mid_y -3};
    move_fruit();
}

void Snake::draw_snake()
{
    for(size_t i = 0; i < v_size; i++)
    {
        draw_rect(v[i],WHITE);
    }

    draw_rect(fruit,RED);
    draw_rect(to_delete,BLACK);
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
    int nx = v[0].x + move_x;
    int ny = v[0].y + move_y;
    to_delete = v[v_size-1];
    for(size_t i = v_size - 1; i > 0; i--)
    {
        v[i] = v[i-1];
    }
    v[0].x = nx;
    v[0].y = ny;
    if(v_size < 200)
    {
        if(v[0].x == fruit.x && v[0].y == fruit.y)
        {
            float tmp_x = v[v_size-1].x - v[v_size-2].x;
            float tmp_y = v[v_size-1].y - v[v_size-2].y;
            v[v_size].x = v[v_size-1].x + tmp_x;
            v[v_size].y = v[v_size-1].y + tmp_y;
            to_delete.x = v[v_size].x + tmp_x;
            to_delete.y = v[v_size].y + tmp_y;
            v_size++;
            move_fruit();
        }
    }
}

bool Snake::is_dead()
{
    if(v[0].x < 0 || v[0].x > max_x)
        return true;
    if(v[0].y < 0 || v[0].y > max_y)
        return true;
    for(size_t i = 1; i < v_size; i++)
    {
        if(v[0].x == v[i].x && v[0].y == v[i].y)
        {
            return true;
        }
    }
    return false;
}

void Snake::play()
{
    while(inc.isRunning())
    {
        if(inc.time_since(300))
        {
            move_snake();
        }
        get_ctrl();
        draw_snake();
        inc.update();
        if(is_dead())
        {
            inc.fillScreen(RED);
            break;
        }
    }
}