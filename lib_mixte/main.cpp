/*#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main()
{
	ALLEGRO_DISPLAY * display;

	al_init();
	display = al_create_display(640, 480);
	al_init_primitives_addon();

	bool running = true;
	while (running) {
		al_draw_line(0, 0, al_get_display_width(display), al_get_display_height(display), al_map_rgb(255, 0, 0),5.0);
		al_draw_rectangle(100, 100, 300, 300, al_map_rgb(0, 255, 0), 1);
		al_draw_ellipse(300, 300, 120, 50, al_map_rgb(0, 0, 255), 3);
		al_flip_display();
	}

	al_destroy_display(display);
	
	return 0;
}*/

#include "libinc.hpp"

int main()
{
    Inconsolable inc(500,500,20);
    while(inc.isRunning())
    {
        //inc.drawLine(0,0,200,200,{255,255,255});
		//inc.fillRect(0,400,0,400,{255,0,0});
		inc.drawCircle(250,250,50,{255,255,255});
		//inc.drawChar(250,250,16,{255,255,255});
        inc.update();
    }
    return 0;
}