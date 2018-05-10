#include "libinc.hpp"

int main()
{
    Inconsolable inc(500,500,20);
    while(inc.isRunning())
    {
        //inc.drawLine(0,0,200,200,{255,255,255});
		//inc.fillRect(0,400,0,400,{255,0,0});
		//inc.drawCircle(250,250,50,{255,255,255});
		inc.drawChar(250,250,16,{255,255,255});
        inc.update();
    }
    return 0;
}