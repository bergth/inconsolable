#include "libinc.hpp"
#include "iostream"
#include "pong.hpp"


int main()
{

    /*Inconsolable inc(500,500,20);
    while(inc.isRunning())
    {

        
        int x=50, y=250, sx=1, sy=1, i=0;


        while(i<150)
        {

            x=x+(sx*5);
        
            y=y+(sy*5);
       
            if(x+5>=450)
            {
                sx = -1;
            }
        
            if(x-5<=50)
            {
                sx = 1;
            }
            
            if(y+5 >= 450)
            {
                sy=-1;
                
            }

            if(y-5<=50)
            {
                sy = 1;
            }


            inc.drawCircle(x,y,5,{255,255,255});
        

            inc.update();

            i++;

            std::cout << x << std::endl;
        }


        

        //inc.drawLine(0,0,200,200,{255,255,255});
		//inc.fillRect(0,400,0,400,{255,0,0});
		//inc.drawCircle(250,250,50,{255,255,255});
		//inc.drawChar(250,250,16,{255,255,255},(char*)"cb");
        inc.update();
    }*/

    Pong p(500,500);

    p.game_running();

    return 0;
}