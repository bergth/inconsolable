#include "snake.hpp"
#include "libinc.hpp"

using namespace std;

Snake::Snake(int _size): size{_size}, inc{SIZE_X,SIZE_Y,FPS}
{
    dir = 1;
    v.push_back({(float)SIZE_X/2,(float)SIZE_Y/2});
    v.push_back({(float)SIZE_X/2,(float)SIZE_Y/2 -size});
    v.push_back({(float)SIZE_X/2,(float)SIZE_Y/2 -2*size});
}

void Snake::draw_snake()
{
    for(size_t i = 0; i < v.size(); i++)
    {
        coord c = v[i];
        inc.fillRect(c.x - size/2,c.x + size/2, c.y - size/2, c.y + size/2,WHITE);
    }
     inc.fillRect(to_delete.x - size/2,to_delete.x + size/2, to_delete.y - size/2, to_delete.y + size/2,BLACK);
}

void Snake::move_snake()
{
    int move_x = 0;
    int move_y = 0;
    switch(dir)
    {
        case 1:
            move_x = 1;
            move_y = 0;
            break;
        case 2:
            move_x = -1;
            move_y = 0;
            break;
        case 3:
            move_x = 0;
            move_y = 1;
            break;
        case 4:
            move_x = 0;
            move_y = -1;
            break;
    }
    int nx = v[0].x + move_x * size;
    int ny = v[0].y += move_y * size;
    to_delete = v[v.size()-1];
    for(size_t i = v.size() - 1; i > 0; i--)
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
            draw_snake();
        }
        inc.update();
    }
}