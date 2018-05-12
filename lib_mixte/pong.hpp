

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
        void parcour(int hauteur, int largeur);
        
        

    private:
        int x;
        int y;
        int r;
        int sense_x;
        int sense_y;
    

};

class raquette
{
    public:

    private:

};

