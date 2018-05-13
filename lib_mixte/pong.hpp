#include <utility> 

class Raquette;
class Ball;

class Pong
{
    public:
        Pong(int _largeur=500, int _hauteur=500);
        void game_running()const;

    private:
        int hauteur;
        int largeur;


};

class Ball
{
    public:
        Ball(int _x, int _y, int _r);
        int get_x() const;
        int get_y() const;
        int get_r() const;
        void parcour(int hauteur, int largeur, Raquette rp, Raquette ria);
        
        

    private:
        int x;
        int y;
        int r;
        int sense_x;
        int sense_y;
    

};


class Raquette
{
    public:
        Raquette(int x1, int y1, int x2, int y2);
        int get_x1() const;
        int get_y1() const;
        int get_x2() const;
        int get_y2() const;
        void moove_IA(Ball la_balle, int hauteur, int largeur);
        bool est_la(int x, int y) const;


    private:
        int x1;
        int y1;
        int x2;
        int y2;
        int centerx;
        int centery;
        

};

