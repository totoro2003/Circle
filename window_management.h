#ifndef WINDOW_MANAGEMENT
#define WINDOW_MANAGEMENT

#include <SDL2/SDL.h>
#include <iostream>

class window_management
{
//automatically handles errors and
//destroys the window 
private:

    std::string window_title;
    
    int width;
    
    int height;
    
    int spawn_pos_x;
    
    int spawn_pos_y;
    
    SDL_Window * window;
    
public:

    window_management( std::string window_title, int width, int height, int spawn_pos_x, int spawn_pos_y );
    
    ~window_management();
    
    void init_window();
    
    SDL_Window * get_window_instance();
    
    SDL_Surface * get_window_surface();
};

#endif
