#include"libinc.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
using namespace std::chrono;

Inconsolable::Inconsolable(size_t sx, size_t sy, size_t FPS)
{
    std::srand(std::time(nullptr));
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
    al_install_keyboard();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_start_timer(timer);
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    running = true;
    redraw = true;

    last_time = Time::now();
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
            case ALLEGRO_EVENT_KEY_DOWN:
                cout << "KEY DOWN" << endl;
                switch(event.keyboard.keycode) {
                    case ALLEGRO_KEY_UP:
                    key[KEY_UP] = true;
                    break;

                    case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = true;
                    break;

                    case ALLEGRO_KEY_LEFT: 
                    key[KEY_LEFT] = true;
                    break;

                    case ALLEGRO_KEY_RIGHT:
                    key[KEY_RIGHT] = true;
                    break;
                    default:
                    break;
                }
                break;
            case ALLEGRO_EVENT_KEY_UP:
                switch(event.keyboard.keycode) {
                    case ALLEGRO_KEY_UP:
                    key[KEY_UP] = false;
                    break;

                    case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = false;
                    break;

                    case ALLEGRO_KEY_LEFT: 
                    key[KEY_LEFT] = false;
                    break;

                    case ALLEGRO_KEY_RIGHT:
                    key[KEY_RIGHT] = false;
                    break;
                    default:
                    break;
                }
            break;
            default:
                //cerr << "Unsupported event received: " << event.type << endl;
                //exit(1);
                break;
        }
    }

    if(redraw && al_is_event_queue_empty(event_queue))
    {
        al_flip_display();
        redraw = false;
    }


    cout << "l:" << key[KEY_LEFT] << endl;

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

bool Inconsolable::time_since(int t)
{
    time_p new_time = Time::now();
    fsec fs = new_time - last_time;
    int diff = fs.count() * 1000;
    if(diff > t)
    {
        last_time = new_time;
        return true;
    }
    return false;
}

int Inconsolable::rand(int a, int b)
{
    float res_tmp = ((float)std::rand() / RAND_MAX) * (b - a);
    return res_tmp + a;
}

void Inconsolable::fillScreen(IncColor color)
{
    al_clear_to_color(al_map_rgb(color.r, color.g, color.b));
}

bool Inconsolable::get_key_up()
{
    return key[KEY_UP];
}

bool Inconsolable::get_key_down()
{
    return key[KEY_DOWN];
}
bool Inconsolable::get_key_left()
{
    return key[KEY_LEFT];
}
bool Inconsolable::get_key_right()
{
    return key[KEY_RIGHT];
}
