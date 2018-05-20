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
    Inconsolable inc(hauteur,largeur,50);

    int x,y,r;
    int largeur_r, longueur_r;

    x = largeur / 10;

    y = hauteur/2;

    r = (hauteur + largeur)/200;

    largeur_r = largeur/10;

    longueur_r = hauteur/4;

    Ball b(x,y,r);

    Raquette rp(largeur_r,longueur_r,2*largeur_r,2*longueur_r);
    Raquette ria(11*largeur_r,longueur_r,12*largeur_r,2*longueur_r);

    inc.fillRect(rp.get_x1(), rp.get_x2(), rp.get_y1(), rp.get_y2(),{255,255,255});
    inc.fillRect(ria.get_x1(), ria.get_x2(), ria.get_y1(), ria.get_y2(),{255,255,255});
    
    while(inc.isRunning())
    {

        rp.moove_IA(b,hauteur,largeur);
        ria.moove_IA(b,hauteur,largeur);
        inc.fillRect(rp.get_x1(), rp.get_x2(), rp.get_y1(), rp.get_y2(),{255,255,255});
        inc.fillRect(ria.get_x1(), ria.get_x2(), ria.get_y1(), ria.get_y2(),{255,255,255});
        inc.drawCircle(b.get_x(),b.get_y(),b.get_r(),{255,255,255});

        inc.update();

        inc.drawCircle(b.get_x(),b.get_y(),b.get_r(),{0,0,0});
        inc.fillRect(rp.get_x1(), rp.get_x2(), rp.get_y1(), rp.get_y2(),{0,0,0});
        inc.fillRect(ria.get_x1(), ria.get_x2(), ria.get_y1(), ria.get_y2(),{0,0,0});

        b.parcour(hauteur,largeur,rp,ria);
        
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

void Ball::parcour(int hauteur, int largeur, Raquette rp, Raquette ria)
{
    int p;

    p = (hauteur + largeur) /200;

    if(x+p>=hauteur - r)
    {
        sense_x = -1;
    }
        
    if(x-p<=0 + r)
    {
        sense_x = 1;
    }
            
    if(y+p >= largeur - r)
    {
        sense_y=-1;
                
    }

    if(y-5<=0+  r)
    {
        sense_y = 1;
    }

    if(rp.est_la(x,y))
    {
        sense_x = 1;
    }

    if(ria.est_la(x,y))
    {
        sense_x = -1;
    }

    x = x + (sense_x * p);

    y = y + (sense_y * p);



}

Raquette::Raquette(int _x1, int _y1, int _x2, int _y2)
{
    y1 = _y1;

    y2 = _y2;

    x1 = _x1;

    x2 = _x2;

    centerx = (x1 + x2)/2;

    centery = (y1 +y2)/2;

}

int Raquette::get_x1() const
{
    return x1;
}

int Raquette::get_y1() const
{
    return y1;
}

int Raquette::get_x2() const
{
    return x2;
}

int Raquette::get_y2() const
{
    return y2;
}

void Raquette::moove_IA(Ball la_balle, int hauteur, int largeur)
{

    int yb = la_balle.get_y();

    int p = (hauteur + largeur) /200;
    

    if(yb != centery )
    {
        if(yb > centery )
        {
            if(y2 +p <= hauteur)
            {
                y1 = y1 + p;

                y2 = y2 + p;

            }
        }

        if(yb < centery )
        {
            if (y1 -p >=0)
            {
                y1 = y1 - p;

                y2 = y2 - p;
            }
        }

         centery = (y1 + y2)/2;

    }
}

bool Raquette::est_la(int x, int y) const
{
    if ((x==x1 || x == x2) && (y>=y1 && y<=y2))
    {
        return true;

    }

    else
        return false;
}
