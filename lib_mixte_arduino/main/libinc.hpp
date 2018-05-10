#include<stddef>
#include<stdint>

struct s_color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

typedef s_color IncColor;

class Inconsolable
{
    private:
    public:
        Inconsolable(size_t sx, size_t sy,size_t FPS);
        
        ~Inconsolable();
        
        
        void clear();
        
        void update();
        
        bool isRunning();

        
        void drawPixel(size_t coord_x,size_t coord_y, IncColor color);
        
        void drawLine(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, IncColor color);
        
        void drawRect(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, IncColor color);
        
        void fillRect(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, IncColor color);
        
        void drawTriangle(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, size_t coord_x3, size_t coord_y3, IncColor color);
        
        void fillTriangle(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, size_t coord_x3, size_t coord_y3, IncColor color);
        
        void drawCircle(size_t coord_x, size_t coord_y, size_t r, IncColor color);
        
        void drawChar(size_t coord_x, size_t coord_y, char c, size_t txt_size, IncColor color);
        
        void drawString(size_t coord_x, size_t coord_y, char* s, size_t txt_size, IncColor color);

        void drawBitmap(size_t coord_x, size_t coord_y, uint32_t bitmap[], size_t w, size_t h);

        void fillScreen(IncColor color);
};
