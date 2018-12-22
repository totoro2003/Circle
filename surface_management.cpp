#include "surface_management.h"

surface_management::surface_management( SDL_Surface * window_surface ) 
{
    this->surface = window_surface;
    
    if (surface == NULL) 
    {
        std::cout << "SDL couldn't load the surface. error: "
        << SDL_GetError(); 
    }
}

surface_management::surface_management( std::string file_name ) 
{
    this->surface = SDL_LoadBMP( file_name.c_str() );
    
    if (surface == NULL) 
    {
        std::cout << "SDL couldn't load the image. error: "
        << SDL_GetError(); 
    }
}

SDL_Surface * surface_management::get_surface_instance() 
{
    return surface;
}

surface_management::~surface_management() 
{
    SDL_FreeSurface(surface);
}
