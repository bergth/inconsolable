#include<stddef.h>
#include<stdint.h>




 /*
  PIN CONFIG
  3 input joystick push
  9 input OLED_MOSI 
  10  input OLED_CLK   
  11  input OLED_DC    
  12  input OLED_CS    
  13  input OLED_RESET

  A0  input joystick x axis
  A1  input joyctick y axis
 */




#define Black           { 0,     0,      0   }
#define Navy            { 0,     0,      128 }
#define DarkGreen       { 0,     128,    0   }
#define DarkCyan        { 0,     128,    128 }
#define Maroon          { 128,   0,      0   }
#define Purple          { 128,   0,      128 }
#define Olive           { 128,   128,    0   }
#define LightGrey       { 192,   192,    192 }
#define DarkGrey        { 128,   128,    128 }
#define Blue            { 0,     0,      255 }
#define Green           { 0,     255,    0   }
#define Cyan            { 0,     255,    255 }
#define Red             { 255,   0,      0   }
#define Magenta         { 255,   0,      255 }
#define Yellow          { 255,   255,    0   }
#define White           { 255,   255,    255 }
#define Orange          { 255,   165,    0   }
#define GreenYellow     { 173,   255,    47  }
#define Pink            { 255,   192,    203 }




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
        Inconsolable(size_t sx = 0, size_t sy = 0,size_t FPS = 0);
        
        ~Inconsolable();
        
        
        void clear();
        
        void update();
        
        bool isRunning();

        
        void drawPixel(size_t coord_x,size_t coord_y, IncColor color);
        
        void drawLine(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, IncColor color);
        
        void drawRect(size_t coord_x, size_t coord_y, size_t w, size_t h, IncColor color);
        
        void fillRect(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, IncColor color);
        
        void drawTriangle(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, size_t coord_x3, size_t coord_y3, IncColor color);
        
        void fillTriangle(size_t coord_x1, size_t coord_y1, size_t coord_x2, size_t coord_y2, size_t coord_x3, size_t coord_y3, IncColor color);
        
        void drawCircle(size_t coord_x, size_t coord_y, size_t r, IncColor color);
        
        void drawChar(size_t coord_x, size_t coord_y, char c, size_t txt_size, IncColor color);
        
        void drawString(size_t coord_x, size_t coord_y, char* s, size_t txt_size, IncColor color);

        void drawBitmap(size_t coord_x, size_t coord_y, uint32_t bitmap[], size_t w, size_t h);

        void fillScreen(IncColor color);
};




uint16_t incColor_to_uint16_t(IncColor color);
