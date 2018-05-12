#include "pong.hpp"
#include "libinc.hpp"

using namespace std;

Pong::Pong(int _hauteur, int _largeur)
{
    hauteur = _hauteur;

    largeur = _largeur;

}

void Pong::game_running() const
{
    Inconsolable inc(hauteur,largeur,20);

    int x,y,r;

    x = largeur / 10;

    y = hauteur/2;

    r = (hauteur + largeur)/200;

    Ball b(x,y,r);

    while(inc.isRunning())
    {
        int xb = b.get_x();
        int yb = b.get_y();
        int rb = b.get_r();
            


        inc.drawCircle(xb,yb,rb,{255,255,255});
        

        inc.update();

        b.parcour(hauteur,largeur);

    }




}

Ball::Ball(int _x, int _y, int _r)
{
    x = _x;

    y = _y;

    r = _r;

    sense_x = 1;

    sense_y = 1;

}

int Ball::get_x() const
{
    return x;
}

int Ball::get_y()const
{
    return y;
}

int Ball::get_r()const
{
    return r;
}

void Ball::parcour(int hauteur, int largeur)
{
    int p;

    p = (hauteur + largeur) /200;

    if(x+p>=largeur - r)
    {
        sense_x = -1;
    }
        
    if(x-p<=0 + r)
    {
        sense_x = 1;
    }
            
    if(y+p >= hauteur - r)
    {
        sense_y=-1;
                
    }

    if(y-5<=0+  r)
    {
        sense_y = 1;
    }

    x = x + (sense_x * p);

    y = y + (sense_y * p);



}
