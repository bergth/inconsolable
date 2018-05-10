#include"libinc.hpp"
#include<iostream>
using namespace std;


Inconsolable::Inconsolable(size_t sx, size_t sy, size_t FPS)
{
    display = NULL;
    event_queue = NULL;
    timer = NULL;
    if(!al_init())
    {
        cerr << "Failed to initialize allegro.\n";
        exit(1);
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer)
    {
        cerr << "Failed to create timer.\n";
        exit(1);
    }

    display = al_create_display(sx,sy);
    if(!display)
    {
        cerr << "Failed to create display.\n";
        exit(1);
    }

    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        cerr << "Failed to create event queue.\n";
        exit(1);
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_start_timer(timer);
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    running = true;
    redraw = true;


}

Inconsolable::~Inconsolable()
{
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
}

void Inconsolable::update()
{
    al_init_timeout(&timeout, 0.06);
    bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);

    if(get_event)
    {
        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                redraw = true;
                break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                running = false;
                break;
            default:
                //cerr << "Unsupported event received: " << event.type << endl;
                //exit(1);
                break;
        }
    }

    if(redraw && al_is_event_queue_empty(event_queue))
    {
        cout << "refresh" << endl;
        al_flip_display();
        //al_clear_to_color(al_map_rgb(0,0,0));
        redraw = false;
    }

}

bool Inconsolable::isRunning()
{
    return running;
}

void Inconsolable::drawPixel(size_t coord_x,size_t coord_y, IncColor color)
{
    al_draw_pixel((float)coord_x,(float)coord_y,al_map_rgb(color.r,color.g,color.b));
}

void Inconsolable::drawLine(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, IncColor color)
{
    al_draw_line(coord_x1,coord_y1,coord_x2,coord_y2,al_map_rgb(color.r,color.g,color.b),5.0);
}

void Inconsolable::drawRect(size_t coord_x1, size_t coord_x2, size_t coord_y1, size_t coord_y2, IncColor color)
{
    al_draw_rectangle(coord_x1,coord_y1,coord_x2,coord_y2,al_map_rgb(color.r,color.g,color.b),0);
}

void Inconsolable::fillRect(size_t coord_x1, size_t coord_x2, size_t coord_y1, size_t coord_y2, IncColor color)
{
    al_draw_filled_rectangle(coord_x1, coord_y1, coord_x2, coord_y2, al_map_rgb(color.r,color.g,color.b));
}

void Inconsolable::drawCircle(size_t coord_x, size_t coord_y, size_t r, IncColor color)
{
    al_draw_circle(coord_x, coord_y, r, al_map_rgb(color.r,color.g,color.b),5.0);
}

void Inconsolable::drawChar(size_t coord_x, size_t coord_y, size_t txt_size, IncColor color, char* c)
{
    ALLEGRO_FONT* font = al_load_font("arial.ttf",txt_size,0);
    if(!font)
    {
        cerr << "Erreur loading font" << endl;
        exit(1);
    }
    al_draw_text(font,al_map_rgb(color.r,color.g,color.b),coord_x, coord_y, 0, c);
}