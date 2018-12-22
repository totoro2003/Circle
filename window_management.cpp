#include "window_management.h"

window_management::window_management( std::string window_title, int width, int height, int spawn_pos_x, int spawn_pos_y ) 
{
    window = NULL;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        std::cout << "SDL couldn't initialize. " 
        << "error: " << SDL_GetError();
    } 
    
    this->window_title = window_title;
    
    this->width = width;
    
    this->height = height;
    
    this->spawn_pos_x = spawn_pos_x;
    
    this->spawn_pos_y = spawn_pos_y;
}
    
void window_management::init_window() 
{
    window = SDL_CreateWindow( window_title.c_str(), spawn_pos_x, spawn_pos_y, width, height, SDL_WINDOW_SHOWN );   
}

SDL_Window * window_management::get_window_instance() 
{
    return window;
}

SDL_Surface * window_management::get_window_surface() 
{
    return SDL_GetWindowSurface( window );
}

window_management::~window_management() 
{
    SDL_DestroyWindow(window);
}

